#include "RoomManager.h"

// Gets the Room at the specified position.
// If no room exists, a new one is generated.
const Room& RoomManager::GetRoomAtPosition(const Vector2 _roomPosition)
{
    Room* result = FindRoomFromPosition(_roomPosition);

    if (result == nullptr) {
        return GenerateNewRoom("Test", _roomPosition);
    }
    else {
        return *result;
    }
}

// Generate a new Room at the specified position and return it.
Room& RoomManager::GenerateNewRoom(String _roomName, Vector2 _position)
{
    // TODO: insert return statement here
}

// Finds the Room at the specified position and returns a reference to it.
// If no Room is found, returns a null pointer.
Room* RoomManager::FindRoomFromPosition(Vector2 _position)
{
    // TODO: Do a binary search to find the first instance of the x pos and store the range.
    // Do a for loop to search through the entire range and check if both x and y match the specified search.
    // If no room exists at position, return NULL.

    // Psuedocode:
    // Binary search for _position.x in m_rooms;
    // Get items between range L and R from binary search;
    // For item in range between L and R
    //  If item.x equals _position.x and item.y equals _position.y;
    //  return this item;
    // End For

    return nullptr;
}
