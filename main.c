#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "MainShop.h"
#include "ViewInventory.h"
#include "struct.h"

int main() {
    int trigger = 0, pilihan;

    struct itemInventory *player = malloc(sizeof(struct itemInventory));

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

        switch (pilihan) {
            case 1:
                MainSHOP(player);
                break;
            case 2:
                viewInventory(player);
                break;
            // Cases 3 and 4 need to be implemented
            case 5:
                trigger = 1; // Set trigger to exit loop
                break;
            // Implement a default case if needed
        }
    } while (trigger == 0);
    
}
