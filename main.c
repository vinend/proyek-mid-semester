#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "MainShop.h"
#include "IsiMainShop.h"
#include "struct.h"

int main() {
    int trigger = 0, pilihan, jumlahItem = 0, JumlahW = 0, JumlahA = 0, i;
    itemInventory *player = (itemInventory*)malloc(sizeof(itemInventory));
    itemsTypes *Weapon =(itemsTypes*)malloc(sizeof(itemsTypes));
    itemsTypes *Armor =(itemsTypes*)malloc(sizeof(itemsTypes));
    system("cls");

    mainIsiShop(&Weapon, &Armor, &JumlahW, &JumlahA);

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
            case 1 : MainSHOP(&player, Weapon, Armor, JumlahW, JumlahA);
            break;
            case 2 : 
            break;
            case 3 :
			break;
            case 4 :break;
        }
    } while(trigger == 0);
    
}
