#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "MainShop.h"
#include "IsiMainShop.h"
#include "struct.h"

int main() {
    int trigger = 0, pilihan, jumlahItem = 0, i;
    itemInventory *player = (itemInventory*)malloc(sizeof(itemInventory));
    itemsTypes *Weapon =(itemsTypes*)malloc(sizeof(itemsTypes));
    system("cls");

    mainIsiShop(&Weapon, &jumlahItem);

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
        printf(" |  3  | Exit Program                              |\n");
        printf(" +-----+-------------------------------------------+\n");

        printf("Masukkan Pilihan: "); scanf("%d", &pilihan);

        switch(pilihan) {
            case 1 : MainSHOP(&player, &Weapon);
            break;
            case 2 : viewInventory(&player);
            break;
            case 3 : 
			break;
            case 4 :break;
        }
    } while(trigger == 0);
    
}
