#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "struct.h"

void viewInventory(struct itemInventory* player) {

    int trigger = 0, pilihan;

    do {

    printf("Jumlah uang yang dimiliki : %.2f\n", player->money);
    printf("Carry weight tersisa: %.2f\n", player->carryLoad);

    if(player->numberOfItems == 0) {
        printf("Anda Saat Ini Tidak Punya Item!");
        return;
    }

    printf("%-20s %-10s %-20s %-50s\n", "Name", "Type", "Attribute", "Description");
    printf("--------------------------------------------------------------------------------\n");
    
    
    for(int i = 0; i < player->numberOfItems; i++) {
        
        if(strcmp(player->items[i].type, "Weapon") == 0) {
            printf("%-20s %-10s %-20.2f DPS %-50s\n", player->items[i].name, "Weapon", player->items[i].dps, player->items[i].description);
        }
        else if(strcmp(player->items[i].type, "Armor") == 0) {
            printf("%-20s %-10s %-20.2f HP %-50s\n", player->items[i].name, "Armor", player->items[i].durability, player->items[i].description);
        }
        else {
            printf("%-20s %-10s %-20.2f S %-50s\n", player->items[i].name, "Other", player->items[i].effectDuration, player->items[i].description);
        }
    }

    printf("1. Sort Items\n2.Search for Items\n3.Back To Main Menu\nPilihan: "); scanf("%d", &pilihan); system("cls");

    switch(pilihan) {
        case 1 : menuSortirInventory(&player);

        case 2 :

        case 3 : trigger++;
    }

    } while(trigger == 0);
}

int itemTypePriority(const char* itemType) {
    if(strcmp(itemType, "Weapon") == 0) return 1;
    else if(strcmp(itemType, "Armor") == 0) return 2;
    else return 3;
}

float getItemPrimaryAttribute(const itemsTypes* item) {
    if(strcmp(item->type, "Weapon") == 0) return item->dps;
    else if(strcmp(item->type, "Armor") == 0) return item->durability;
    else return item->effectDuration;
}

void sortirNama(struct itemInventory* player, int urutan) {

    if(urutan = 1) {
        for(int i = 0; i < player->numberOfItems; i++) {
            for(int j = 0; j < player->numberOfItems - 1 -i; j++) {
                if(strcmp(player->items[j].name, player->items[j + 1].name) > 0) {
                    itemsTypes temp = player->items[j];
                    player->items[j] = player->items[j + 1];
                    player->items[j + 1] = temp;
                }
                
            }
        }
    }

    else {
        for(int i = 0; i < player->numberOfItems; i++) {
            for(int j = 0; j < player->numberOfItems - 1 -i; j++) {
                if(strcmp(player->items[j].name, player->items[j + 1].name) < 0) {
                    itemsTypes temp = player->items[j];
                    player->items[j] = player->items[j + 1];
                    player->items[j + 1] = temp;
                }
                
            }
        }
    }
}

void sortirTipeItem(struct itemInventory* player) {
   for(int i = 0; i < player->numberOfItems; i++) {
        for(int j = 0; j < player->numberOfItems - 1 - i; j++) {
            int priorityCurrent = itemTypePriority(player->items[j].type);
            int priorityNext = itemTypePriority(player->items[j + 1].type);

            
            int needSwap = (priorityCurrent > priorityNext) || (priorityCurrent == priorityNext && strcmp(player->items[j].name, player->items[j + 1].name) > 0);

            if(needSwap) {
                itemsTypes temp = player->items[j];
                player->items[j] = player->items[j + 1];
                player->items[j + 1] = temp;
            }
        }
    }
}

void sortirNilaiAtribut(struct itemInventory* player, int urutan) {

    if(urutan == 1) {
    for(int i = 0; i < player->numberOfItems; i++) {
            for(int j = 0; j < player->numberOfItems - 1 - i; j++) {
                float attributeCurrent = getItemPrimaryAttribute(&player->items[j]);
                float attributeNext = getItemPrimaryAttribute(&player->items[j + 1]);
                if(attributeCurrent < attributeNext) { 
                    itemsTypes temp = player->items[j];
                    player->items[j] = player->items[j + 1];
                    player->items[j + 1] = temp;
                }
            }
        }
    }

    else {
        for(int i = 0; i < player->numberOfItems; i++) {
            for(int j = 0; j < player->numberOfItems - 1 - i; j++) {
                float attributeCurrent = getItemPrimaryAttribute(&player->items[j]);
                float attributeNext = getItemPrimaryAttribute(&player->items[j + 1]);
                if(attributeCurrent > attributeNext) { 
                    itemsTypes temp = player->items[j];
                    player->items[j] = player->items[j + 1];
                    player->items[j + 1] = temp;
                }
            }
        }
    }
}

void sortirBeratItem(struct itemInventory* player, int urutan) {

    if(urutan == 1) {
        for(int i = 0; i < player->numberOfItems; i++) {
            for(int j = 0; j < player->numberOfItems - 1 -i; j++) { 
                if(player->items[j].weights > player->items[j + 1].weights) {
                    itemsTypes temp = player->items[j];
                    player->items[j] = player->items[j + 1];
                    player->items[j + 1] = temp;
                }
            }
        }
    }

    else {
           for(int i = 0; i < player->numberOfItems; i++) {
            for(int j = 0; j < player->numberOfItems - 1 -i; j++) { 
                if(player->items[j].weights < player->items[j + 1].weights) {
                    itemsTypes temp = player->items[j];
                    player->items[j] = player->items[j + 1];
                    player->items[j + 1] = temp;
                }
            }
        }
    }
}

void sortirHargaItem(struct itemInventory* player, int urutan) {

    if(urutan == 1) {
        for(int i = 0; i < player->numberOfItems; i++) {
            for(int j = 0; j < player->numberOfItems - 1 -i; j++) { 
                if(player->items[j].price > player->items[j + 1].price) {
                    itemsTypes temp = player->items[j];
                    player->items[j] = player->items[j + 1];
                    player->items[j + 1] = temp;
                }
            }
        }
    }

    else {
        for(int i = 0; i < player->numberOfItems; i++) {
            for(int j = 0; j < player->numberOfItems - 1 -i; j++) { 
                if(player->items[j].price > player->items[j + 1].price) {
                    itemsTypes temp = player->items[j];
                    player->items[j] = player->items[j + 1];
                    player->items[j + 1] = temp;
                }
            }
        }
    }
}

void menuSortirInventory(struct itemInventory* player) {
    int pilihan, urutan;

    system("cls");
    printf("\n");
    printf(" +-------------------------------------------------+\n");
    printf(" |               Pilih Metode Sorting              |\n");
    printf(" +-------------------------------------------------+\n");
    printf(" | No. |                Description                |\n");
    printf(" +-----+-------------------------------------------+\n");
    printf(" |  1  | Sorting Berdasarkan Nama                  |\n");
    printf(" +-----+-------------------------------------------+\n");
    printf(" |  2  | Sorting Berdasarkan Tipe Item             |\n");
    printf(" +-----+-------------------------------------------+\n");
    printf(" |  3  | Sorting Berdasarkan Atribute Item         |\n");
    printf(" +-----+-------------------------------------------+\n");
    printf(" |  4  | Sorting Berdasarkan Berat Item            |\n");
    printf(" +-----+-------------------------------------------+\n");
    printf(" |  5  | Sorting Berdasarkan Harga Item            |\n");
    printf(" +-----+-------------------------------------------+\n");
    
    printf("Pilihan: "); scanf("%d", &pilihan); system("cls");

    switch(pilihan) {
        case 1 : printf("Ascending / Descending? (1 / 0): "); scanf("%d", urutan); sortirNama(&player, urutan);

        case 2 : sortirTipeItem(&player);

        case 3 : printf("Ascending / Descending? (1 / 0): "); scanf("%d", urutan); sortirNilaiAtribut(&player, urutan);

        case 4 : printf("Ascending / Descending? (1 / 0): "); scanf("%d", urutan); sortirBeratItem(&player, urutan);

        case 5 : printf("Ascending / Descending? (1 / 0): "); scanf("%d", urutan); sortirHargaItem(&player, urutan);
    }

}

searchingInventory() {

}
