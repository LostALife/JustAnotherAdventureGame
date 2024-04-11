#include "RoomManager.h"

RoomManager::RoomManager()
{
}

RoomManager::RoomManager(const RoomManager& _other)
{
}

RoomManager::~RoomManager()
{
    for (int i = 0; i < m_rooms.size(); i++) {
        delete m_rooms[i];
    }
}

// Gets the Room at the specified position.
// If no room exists, returns nullptr.
Room* RoomManager::GetRoomAtPosition(const Vector2 _roomPosition)
{
    Room* result = BinarySearchRoomPos(_roomPosition);

    return result;
}

// Generate a new room at the specified position. If a room already exists at _roomPosition, returns its pointer.
// If the generation fails, returns a null pointer.
Room* RoomManager::GenerateNewRoom(const Vector2 _roomPosition)
{
    Room* searchResult = BinarySearchRoomPos(_roomPosition);
    if (searchResult != nullptr)
        return searchResult;

    RoomGenParams newRoomParams = GenerateNewRoomParameters(_roomPosition);

    Room* newRoom = new Room(newRoomParams.roomName, newRoomParams.roomPosition, newRoomParams.roomType, newRoomParams.roomExits, newRoomParams.roomItems);
    m_rooms.push_back(newRoom);

    return newRoom;
}

// Generate a new room at the specified position. If a room already exists at _roomPosition, returns its pointer.
// If the generation fails, returns a null pointer.
Room* RoomManager::GenerateNewRoom(const String _roomName, const Vector2 _roomPosition, const RoomType _roomType, const RoomExits _roomExits, const std::vector<Item*>& _roomItems)
{
    Room* searchResult = BinarySearchRoomPos(_roomPosition);
    if (searchResult != nullptr)
        return searchResult;

    Room* newRoom = new Room(_roomName, _roomPosition, _roomType, _roomExits, _roomItems);
    m_rooms.push_back(newRoom);

    return newRoom;
}

// Creates a RoomGenerationParameters struct object with all relevant information required to create a new room.
RoomGenParams RoomManager::GenerateNewRoomParameters(const Vector2 _newRoomPosition)
{
    RoomGenParams params;
    params.roomPosition = _newRoomPosition;

    std::vector<RoomType> possibleRoomTypes;

#pragma region RoomType
    // Add the Normal room type by default.
    possibleRoomTypes.push_back(RoomType::Normal);

    Room* foundRoom;

    // Check for Branch rooms within a 2 room range, if none exist, add it to the possible room types.
    foundRoom = GetClosestRoomByType(RoomType::Branch, _newRoomPosition, 2);
    if (foundRoom == nullptr)
        possibleRoomTypes.push_back(RoomType::Branch);

    // Check for ChestRoom rooms within a 8 room range, if none exist, add it to the possible room types.
    foundRoom = GetClosestRoomByType(RoomType::ChestRoom, _newRoomPosition, 8);
    if (foundRoom == nullptr)
        possibleRoomTypes.push_back(RoomType::ChestRoom);

    // Check for BossChamber rooms within a 15 room range, if none exist, add it to the possible room types.
    foundRoom = GetClosestRoomByType(RoomType::BossChamber, _newRoomPosition, 15);
    if (foundRoom == nullptr)
        possibleRoomTypes.push_back(RoomType::BossChamber);

    srand(time(NULL));
    int randIndex = std::rand() % possibleRoomTypes.size();
    params.roomType = possibleRoomTypes[randIndex];
#pragma endregion

#pragma region RoomExits
    // Check each space around the new room position and check for an existing room.
    // If there is an existing room, check if it's exits point towards the new room. If so, create an exit on the new room pointing to it.
    // Otherwise, randomly decide to make an exit on blank spots.

    foundRoom = BinarySearchRoomPos(_newRoomPosition + Vector2(0,1));
    if (foundRoom != nullptr) {
        if (foundRoom->getRoomExits().down)
            params.roomExits.up = true;
    }
    else {
        if (params.roomType == RoomType::Branch) {
            params.roomExits.up = true;
        }
        else {
            params.roomExits.up = std::rand() % 2;
        }
    }

    foundRoom = BinarySearchRoomPos(_newRoomPosition + Vector2(1, 0));
    if (foundRoom != nullptr) {
        if (foundRoom->getRoomExits().left)
            params.roomExits.right = true;
    }
    else {
        if (params.roomType == RoomType::Branch) {
            params.roomExits.right = true;
        }
        else {
            params.roomExits.right = std::rand() % 2;
        }
    }

    foundRoom = BinarySearchRoomPos(_newRoomPosition + Vector2(0, -1));
    if (foundRoom != nullptr) {
        if (foundRoom->getRoomExits().up)
            params.roomExits.down = true;
    }
    else {
        if (params.roomType == RoomType::Branch) {
            params.roomExits.down = true;
        }
        else {
            params.roomExits.down = std::rand() % 2;
        }
    }

    foundRoom = BinarySearchRoomPos(_newRoomPosition + Vector2(-1, 0));
    if (foundRoom != nullptr) {
        if (foundRoom->getRoomExits().right)
            params.roomExits.left = true;
    }
    else {
        if (params.roomType == RoomType::Branch) {
            params.roomExits.left = true;
        }
        else {
            params.roomExits.left = std::rand() % 2;
        }
    }
#pragma endregion

#pragma region RoomName
    if (params.roomType == RoomType::BossChamber) {
        srand(time(NULL));
        int bossName = rand() % m_bossNames.size();
        srand(time(NULL));
        int roomName = rand() % m_roomNames.size();

        params.roomName = m_bossNames[bossName] + "'s " + m_roomNames[roomName];
    }
    else if (params.roomType == RoomType::ChestRoom) {
        params.roomName = "Chest Room";
    }
    else if (params.roomType == RoomType::Branch) {
        params.roomName = "Branch Room";
    }
    else {
        params.roomName = "Regular Room";
    }
#pragma endregion

#pragma region RoomItems
    srand(time(NULL));
    int numberOfItems = rand() % 4;

    ItemLibrary itemLibrary;
    for (int i = 0; i < numberOfItems; i++) {
        Item* newItem = new Item(itemLibrary.GetRandomItem());
        params.roomItems.push_back(newItem);
    }
#pragma endregion


    return params;
}

// Finds the Room at the specified position using a binary search and returns a reference to it.
// If no Room is found, returns a null pointer.
Room* RoomManager::BinarySearchRoomPos(const Vector2 _position)
{
    if (m_rooms.size() == 0)
        return nullptr;

    // Does a binary search to find the first occurence of a room with the same m_x position as the target.
    // If a match is found, a for loop runs over every item within the last searched range until an exact position match is found.

    std::vector<Room*> sortedRooms = m_rooms;
    std::sort(sortedRooms.begin(), sortedRooms.end(), [](Room* a, Room* b) {
        return a->getRoomPosition().m_x < b->getRoomPosition().m_x;
    });

    int minRange = 0;
    int maxRange = sortedRooms.size() - 1;
    bool itemFound = false;
    while (minRange <= maxRange) {
        int middleRange = (minRange + maxRange) / 2;
        if (sortedRooms[middleRange]->getRoomPosition().m_x == _position.m_x) {
            itemFound = true;
            break;
        }
        else if (sortedRooms[middleRange]->getRoomPosition().m_x < _position.m_x) {
            minRange = middleRange + 1;
        }
        else if (sortedRooms[middleRange]->getRoomPosition().m_x > _position.m_x) {
            maxRange = middleRange - 1;
        }
    }
    
    if (itemFound) {
        for (int i = minRange; i <= maxRange; i++) {
            if (sortedRooms[i]->getRoomPosition() == _position) {
                return sortedRooms[i];
            }
        }
    }

    return nullptr;
}

// Find the closest room within _searchDistance of _searchFrom with type _roomType.
// Returns null if no rooms of type _roomType found.
Room* RoomManager::GetClosestRoomByType(const RoomType _roomType, Vector2 _searchFrom, const int _searchDistance)
{
    Room* closestRoom = nullptr;

    Vector2 searchFrom = _searchFrom - _searchDistance;
    Vector2 searchTo = _searchFrom + _searchDistance;

    for (int x = searchFrom.m_x; x <= searchTo.m_x; x++) {
        for (int y = searchFrom.m_y; y <= searchTo.m_y; y++) {
            Room* searchResult = BinarySearchRoomPos(Vector2(x, y));

            if (searchResult == nullptr || searchResult->getRoomType() != _roomType)
                continue;

            if (closestRoom == nullptr) {
                closestRoom = searchResult;
            }
            else {
                int distanceToCurrent = Vector2::Distance(_searchFrom, closestRoom->getRoomPosition());
                int distanceToNew = Vector2::Distance(_searchFrom, searchResult->getRoomPosition());

                if (distanceToNew < distanceToCurrent)
                    closestRoom = searchResult;
            }
        }
    }

    return closestRoom;
}
