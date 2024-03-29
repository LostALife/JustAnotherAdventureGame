#include "RoomManager.h"

const Room& RoomManager::GetRoomInfo(Vector2 _roomPosition)
{
	//
	// TODO: Generate new room if room at position doesn't exist.
	//

	return FindRoomFromPosition(_roomPosition);
}

void RoomManager::GenerateNewRoom(String _roomName, Vector2 _position)
{
}

Room& RoomManager::FindRoomFromPosition(Vector2 _position)
{
	//
	// TODO: Implement binary search function to find room.
	//

	//procedure binarySearch(A = list of sortable items, K = item to look for)
	//	.
	//	.L = 0
	//	.R = length of A - 1
	//	. while L less or equal to R
	//	. .
	//	..M = integer((L + R) / 2)
	//	. . if A[M] == K then
	//	. . . return M
	//	. . .
	//	. . if A[M] < K then
	//	. ..L = M + 1
	//	. . .
	//	. . if A[M] > K then
	//	. ..R = M – 1
	//	. .
	//	.end while
	//	. return NotFound
	//	.
	//	end procedure

	
	


	// Return null if no room exists.
}
