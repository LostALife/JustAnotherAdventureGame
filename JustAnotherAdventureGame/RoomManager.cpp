#include "RoomManager.h"

// Gets the Room at the specified position.
// If no room exists, a new one is generated.
const Room& RoomManager::GetRoomAtPosition(const Vector2 _roomPosition)
{
    Room* result = FindRoomFromPosition(_roomPosition);

    if (result != nullptr) {
        return *result;
    }
    else {
        return GenerateNewRoom("Test", _roomPosition);
    }
}

// Generate a new Room at the specified position and return it.
Room& RoomManager::GenerateNewRoom(String _roomName, Vector2 _position)
{
    m_rooms.push_back(*new Room(_roomName, _position));
    
    return m_rooms.back();
}

// Finds the Room at the specified position and returns a reference to it.
// If no Room is found, returns a null pointer.
Room* RoomManager::FindRoomFromPosition(Vector2 _position)
{
    if (m_rooms.size() == 0)
        return nullptr;

    // Does a binary search to find the first occurence of a room with the same m_x position as the target.
    // If a match is found, a for loop runs over every item within the last searched range until an exact position match is found.

    int minRange = 0;
    int maxRange = m_rooms.size() - 1;
    bool itemFound = false;
    while (minRange <= maxRange) {
        int middleRange = (minRange + maxRange) / 2;
        if (m_rooms[middleRange].getRoomPosition().m_x == _position.m_x) {
            itemFound = true;
            break;
        }
        else if (m_rooms[middleRange].getRoomPosition().m_x < _position.m_x) {
            minRange = middleRange + 1;
        }
        else if (m_rooms[middleRange].getRoomPosition().m_x > _position.m_x) {
            maxRange = middleRange - 1;
        }
    }
    
    if (itemFound) {
        for (int i = minRange; i <= maxRange; i++) {
            if (m_rooms[i].getRoomPosition() == _position) {
                return &m_rooms[i];
            }
        }
    }

    return nullptr;
}
