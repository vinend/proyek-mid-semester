#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "MainShop.h"

struct itemsTypes{
    float weights;
    float price;
    float dps;
    float durability;
    float effectDuration;
    char description[500];
    char type[300];
    char name[300];
};

struct itemInventory{
    float money;
    int carryLoad;
    int numberOfItems;
    struct itemsTypes *items; 
};

void viewInventory(struct itemInventory player) {
    printf("Jumlah uang yang dimiliki : %.2f\n", player.money);
    printf("Carry weight tersisa: %d\n", player.carryLoad); 

    if(player.numberOfItems == 0) {
        printf("Anda Saat Ini Tidak Punya Item!\n");
        return;
    }

    for(int i = 0; i < player.numberOfItems; i++) {
        
        if(strcmp(player.items[i].type, "Weapon") == 0) {
            printf("%s %s %.2f %s\n", player.items[i].name, player.items[i].type, player.items[i].dps, player.items[i].description);
        } else if(strcmp(player.items[i].type, "Armor") == 0) {
            printf("%s %s %.2f %s\n", player.items[i].name, player.items[i].type, player.items[i].durability, player.items[i].description);
        } else {
            printf("%s %s %.2f %s\n", player.items[i].name, player.items[i].type, player.items[i].effectDuration, player.items[i].description);
        }
    }
}

void initializeShopItems(struct itemInventory *shop, int jumlahItem) {
    shop->carryLoad = 100000;
    shop->money = 10000;
    shop->numberOfItems = jumlahItem;

     shop->items = (struct itemsTypes*)malloc(sizeof(struct itemsTypes));

     for(int i = 0; i < jumlahItem; i++) {
        printf("Masukkan nama item: "); scanf(" %[^\n]", shop->items[i].name);
        printf("Masukkan type item: "); scanf(" %[^\n]", shop->items[i].type);
        printf("Masukkan Weight Items"); scanf("%f", shop->items[i].weights);
        if(strcmp(shop->items[i].type, "Weapon") == 0) {
            printf("Masukkan Damage Weapon: "); scanf("%f", shop->items[i].dps);
        } else if(strcmp(shop->items[i].type, "Armor") == 0) {
            printf("Masukkan Durability Armor: "); scanf("%f", shop->items[i].durability);
        } else {
            printf("Masukkan Durasi Potion: "); scanf("%f", shop->items[i].dps);
        }
        printf("Masukkan Deskripsi Singkat Item: "); scanf(" %[^\n]", shop->items[i].description);

        system("cls");
     }
}

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
        printf(" |  3  | Sorting Inventory                         |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  4  | Searching Inventory                       |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  5  | Exit Program                              |\n");
        printf(" +-----+-------------------------------------------+\n");

        printf("Masukkan Pilihan: "); scanf("%d", &pilihan);

        switch(pilihan) {
            case 1 : MainSHOP(&player, &shop);
            
            case 2 : viewInventory(&player);
            
            case 3 :

            case 4 :
        }
    } while(trigger == 0);
    
}
