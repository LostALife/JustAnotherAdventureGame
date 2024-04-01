#include <iostream>
#include "GameManager.h"
#include "InventoryManager.h"
#include "Item.h"

#include "ItemApple.h";

int main()
{
    GameManager gameManager;
    InventoryManager invManager;

    ItemApple apple;

    invManager.AddNewItem(&apple);
    invManager.PrintInventoryToConsole();
}