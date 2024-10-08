#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "MainShop.h"
#include "IsiMainShop.h"
#include "struct.h"
#include "ViewInventory.h"

int main() {
    int trigger = 0, pilihan, JumlahData = 0, i;
    itemInventory *player=(itemInventory*)malloc(sizeof(itemInventory));;
    player->items = NULL;
    itemsTypes *Data = (itemsTypes*)malloc(sizeof(itemsTypes));
    player->numberOfItems = 0;
    player->carryLoad = 150;
    printf("Masukkan Jumlah Uang Anda : ");
    scanf("%f", &player->money);
    system("cls");

    mainIsiShop(&Data, &JumlahData);

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
            case 1 : MainSHOP(player, Data, JumlahData);
            break;
            case 2 : viewInventory(player); getch();
            break;
            case 3 :
                system("cls");
                printf("Terima Kasih! Press any button to continue!");
                getch();
                trigger++;
                break;
            default :
                system("cls"); printf("Input Tidak Benar"); getch();
                break;
        }
    } while(trigger == 0);
    
}
