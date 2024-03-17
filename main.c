#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "MainShop.h"
#include "ViewInventory.h"
#include "IsiMainShop.h"
#include "struct.h"

int main() {
    int trigger = 0, pilihan, jumlahItem;

    struct itemInventory player, shop;

    printf("Berapa item yang diinginkan di shop?: "); scanf("%d", &jumlahItem);

    system("cls");

    initializeShopItems(&shop, jumlahItem);

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
            case 1 : MainSHOP(&player);
            
            case 2 : viewInventory(&player);
            
            case 3 :

            case 4 :
        }
    } while(trigger == 0);
    
}
