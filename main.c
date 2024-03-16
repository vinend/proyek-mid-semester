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
#include "MainShop.h"

typedef struct{
    float weights;
    float price;
    float dps;
    float durability;
    float effectTime;
    char description[500];
    char type[300];
    char name[300];
<<<<<<< HEAD

} items;

typedef struct itemInventory {
    float money;
=======
}items;

typedef struct{
    int money;
>>>>>>> 62107cdceebecda24e9119ad6f5674bdc2ad40c3
    int carryLoad;
    int numberOfItems;
    items *items;
}inventory;

void viewInventory(inventory player) {
    printf("Jumlah uang yang dimiliki : %.2f\n", player.money);
    printf("Carry weight tersisa: %.2f\n", player.carryLoad);

    if(player.numberOfItems == 0) {
        printf("Anda Saat Ini Tidak Punya Item!");
        return;
    }

    for(int i = 0; i < player.numberOfItems; i++) {

        if(strcpy(player.items[i].type, "Weapon") ) {
            printf("%s %s %.2f %.2f %s", player.items[i].name, player.items[i].type, player.items[i].dps, player.items[i].description);
        }

        else if(strcpy(player.items[i].type, "Armor")) {
            printf("%s %s %.2f %.2f %s", player.items[i].name, player.items[i].type, player.items[i].durability, player.items[i].description);
        }

        else {
            printf("%s %s %.2f %.2f %s", player.items[i].name, player.items[i].type, player.items[i].effectTime, player.items[i].description);
        }
    }
}

int main() {
    int trigger = 0, pilihan;

    inventory player, shop;

    do { 
        system("cls");
        printf("\n");
        printf(" +-------------------------------------------------+\n");
        printf(" |         SELAMAT DATANG DI SHOP ITEM LIYUE       |\n");
        printf(" +-------------------------------------------------+\n");
        printf(" | No. |                Description                |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  1  | Shop for Items                            |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  2  | View Inventory                            |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  3  | Sorting Inventory                         |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  4  | Searching Inventory                       |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  5  | Exit Program                              |\n");
        printf(" +-----+-------------------------------------------+\n");

        printf("Masukkan Pilihan: "); scanf("%d", &pilihan);

        switch(pilihan) {
            case 1 : viewInventory(player);
            
            case 2 :
            
            case 3 :

            case 4 :
        }
    } while(trigger == 0);
    
}