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
    char description[500];
    char type[300];
    char name[300];
}items;

typedef struct{
    int money;
    int carryLoad;
    int numberOfItems;
    items *items;
}inventory;


int main() {
    int trigger = 0, pilihan;

    inventory player, shop;

    do { 
        system("cls");
        printf("\n");
        printf(" +-------------------------------------------------+\n");
        printf(" |         SELAMAT DATANG DI SHOP SENJATA LIYUE    |\n");
        printf(" +-------------------------------------------------+\n");
        printf(" | No. |                Description                |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  1  | View Inventory                            |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  2  | Beli Senjata                              |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  3  | Sorting Inventory                         |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  4  | Searching Inventory                       |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  5  | Exit Program                              |\n");
        printf(" +-----+-------------------------------------------+\n");

        printf("Masukkan Pilihan: "); scanf("%d", &pilihan);

        switch(pilihan) {
            case 1 :
            
            case 2 :
            
            case 3 :

            case 4 :
        }
    } while(trigger == 0);
    
}