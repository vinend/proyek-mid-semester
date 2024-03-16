// Program Management Inventory dalam Game RPG
// Kelompok 2 :
// 1. Andi Muhammad Alvin Farhansyah 2306161933
// 2. Alexander Christhian 2306267025

// Versi 1.0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

typedef struct itemsTypes{
    float weights;
    float price;
    float dps;
    float durability;
    char description[500];
    char type[500];

} items;

typedef struct itemInventory {
    int money;
    int carryLoad;
    int numberOfItems;
    items *items;
} inventory;


int main() {
    
}