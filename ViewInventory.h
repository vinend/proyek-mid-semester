#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "struct.h"

void viewInventory(itemInventory* player) {

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
            printf("%-20s %-10s %-20.2f S %-50s\n", player->items[i].name, "Other", "N/A", player->items[i].description);
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
}

void sortirNama(itemInventory* player, int urutan) {

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

void sortirTipeItem(itemInventory* player) {
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

void sortirNilaiAtribut(itemInventory* player, int urutan) {

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

void sortirBeratItem(itemInventory* player, int urutan) {

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

void sortirHargaItem(itemInventory* player, int urutan) {

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

void menuSortirInventory(itemInventory* player) {
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
        case 1 : printf("Ascending / Descending? (1 / 0): "); scanf("%d", &urutan); sortirNama(&player, urutan); break;

        case 2 : sortirTipeItem(&player); break;

        case 3 : printf("Ascending / Descending? (1 / 0): "); scanf("%d", &urutan); sortirNilaiAtribut(&player, urutan); break;

        case 4 : printf("Ascending / Descending? (1 / 0): "); scanf("%d", &urutan); sortirBeratItem(&player, urutan); break;

        case 5 : printf("Ascending / Descending? (1 / 0): "); scanf("%d", &urutan); sortirHargaItem(&player, urutan); break;
    }

}

void string_to_lower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void searchingNama(itemInventory* player, char namaItem) {
    char namaItemLower[100];

    string_to_lower(namaItem);

    printf("%-20s %-10s %-20s %-50s\n", "Name", "Type", "Attribute", "Description");
    printf("--------------------------------------------------------------------------------\n");

    for(int i = 0; i < player->numberOfItems; i++) {
        strcpy(namaItemLower, player->items[i].name);
        string_to_lower(namaItemLower);

        if(strstr(namaItemLower, namaItem) != NULL) {
            if(strcmp(player->items[i].type, "Weapon") == 0) {
                printf("%-20s %-10s %-20.2f DPS %-50s\n", player->items[i].name, "Weapon", player->items[i].dps, player->items[i].description);
            }
            else if(strcmp(player->items[i].type, "Armor") == 0) {
                printf("%-20s %-10s %-20.2f HP %-50s\n", player->items[i].name, "Armor", player->items[i].durability, player->items[i].description);
            }
            else {
                printf("%-20s %-10s %-20.2f S %-50s\n", player->items[i].name, "Other", "N/A", player->items[i].description);
            }
        }
    } 

    printf("Press Any Button to Continue"); getch(); system("cls");
}

void searchingTipe(itemInventory* player, int pilihan) {

    printf("%-20s %-10s %-20s %-50s\n", "Name", "Type", "Attribute", "Description");
    printf("--------------------------------------------------------------------------------\n");

    if(pilihan == 1) {
        for(int i = 0; i < player->numberOfItems; i++) {
            if(strcmp(player->items[i].type, "Weapon") == 0) {
                if(strcmp(player->items[i].type, "Weapon") == 0) {
                    printf("%-20s %-10s %-20.2f DPS %-50s\n", player->items[i].name, "Weapon", player->items[i].dps, player->items[i].description);
                }
                else if(strcmp(player->items[i].type, "Armor") == 0) {
                    printf("%-20s %-10s %-20.2f HP %-50s\n", player->items[i].name, "Armor", player->items[i].durability, player->items[i].description);
                }
                else {
                    printf("%-20s %-10s %-20.2f S %-50s\n", player->items[i].name, "Other", "N/A", player->items[i].description);
                }
            }
        }
    }

    
    if(pilihan == 2) {
        for(int i = 0; i < player->numberOfItems; i++) {
            if(strcmp(player->items[i].type, "Armor") == 0) {
                if(strcmp(player->items[i].type, "Weapon") == 0) {
                    printf("%-20s %-10s %-20.2f DPS %-50s\n", player->items[i].name, "Weapon", player->items[i].dps, player->items[i].description);
                }
                else if(strcmp(player->items[i].type, "Armor") == 0) {
                    printf("%-20s %-10s %-20.2f HP %-50s\n", player->items[i].name, "Armor", player->items[i].durability, player->items[i].description);
                }
                else {
                    printf("%-20s %-10s %-20.2f S %-50s\n", player->items[i].name, "Other", "N/A", player->items[i].description);
                }
            }
        }
    }

    
    if(pilihan == 3) {
        for(int i = 0; i < player->numberOfItems; i++) {
            if(strcmp(player->items[i].type, "Other") == 0) {
                if(strcmp(player->items[i].type, "Weapon") == 0) {
                    printf("%-20s %-10s %-20.2f DPS %-50s\n", player->items[i].name, "Weapon", player->items[i].dps, player->items[i].description);
                }
                else if(strcmp(player->items[i].type, "Armor") == 0) {
                    printf("%-20s %-10s %-20.2f HP %-50s\n", player->items[i].name, "Armor", player->items[i].durability, player->items[i].description);
                }
                else {
                    printf("%-20s %-10s %-20.2f S %-50s\n", player->items[i].name, "Other", "N/A", player->items[i].description);
                }
            }
        }
    }
}

int searchDPS(itemInventory* player) {
    float batasAtas, batasBawah;

    do {
        printf("Masukkan Batas Atas: "); scanf("%f", &batasAtas);
        printf("Masukkan Batas Bawah: "); scanf("%f", &batasBawah);

        if(batasAtas > batasBawah) {
            system("cls"); printf("Batas atas harus diatas batas bawah!"); getch(); system("cls");
        }
    } while(batasAtas > batasBawah);

    printf("%-20s %-10s %-20s %-50s\n", "Name", "Type", "Attribute", "Description");
    printf("--------------------------------------------------------------------------------\n");

    for (int i = 0; i < player->numberOfItems; i++){
        if(strcmp(player->items[i].type, "Weapon") == 1 && player->items[i].dps >= batasBawah && player->items[i].dps <= batasAtas){
                if(strcmp(player->items[i].type, "Weapon") == 0) {
                    printf("%-20s %-10s %-20.2f DPS %-50s\n", player->items[i].name, "Weapon", player->items[i].dps, player->items[i].description);
                }
                else if(strcmp(player->items[i].type, "Armor") == 0) {
                    printf("%-20s %-10s %-20.2f HP %-50s\n", player->items[i].name, "Armor", player->items[i].durability, player->items[i].description);
                }
                else {
                    printf("%-20s %-10s %-20.2f S %-50s\n", player->items[i].name, "Other", "N/A", player->items[i].description);
                }
        }
    }

}

int searchDurability(itemInventory* player) {
    float batasAtas, batasBawah;

    do {
        printf("Masukkan Batas Atas: "); scanf("%f", &batasAtas);
        printf("Masukkan Batas Bawah: "); scanf("%f", &batasBawah);

        if(batasAtas > batasBawah) {
            system("cls"); printf("Batas atas harus diatas batas bawah!"); getch(); system("cls");
        }
    } while(batasAtas > batasBawah);

    printf("%-20s %-10s %-20s %-50s\n", "Name", "Type", "Attribute", "Description");
    printf("--------------------------------------------------------------------------------\n");

    for (int i = 0; i < player->numberOfItems; i++){
        if(strcmp(player->items[i].type, "Armor") == 1 && player->items[i].dps >= batasBawah && player->items[i].dps <= batasAtas){
                if(strcmp(player->items[i].type, "Weapon") == 0) {
                    printf("%-20s %-10s %-20.2f DPS %-50s\n", player->items[i].name, "Weapon", player->items[i].dps, player->items[i].description);
                }
                else if(strcmp(player->items[i].type, "Armor") == 0) {
                    printf("%-20s %-10s %-20.2f HP %-50s\n", player->items[i].name, "Armor", player->items[i].durability, player->items[i].description);
                }
                else {
                    printf("%-20s %-10s %-20.2f S %-50s\n", player->items[i].name, "Other", "N/A", player->items[i].description);
                }
        }
    }
}

int searchBerat(itemInventory* player) {
    float batasAtas, batasBawah;

    do {
        printf("Masukkan Batas Atas: "); scanf("%f", &batasAtas);
        printf("Masukkan Batas Bawah: "); scanf("%f", &batasBawah);

        if(batasAtas > batasBawah) {
            system("cls"); printf("Batas atas harus diatas batas bawah!"); getch(); system("cls");
        }
    } while(batasAtas > batasBawah);

    printf("%-20s %-10s %-20s %-50s\n", "Name", "Type", "Attribute", "Description");
    printf("--------------------------------------------------------------------------------\n");

    for (int i = 0; i < player->numberOfItems; i++){
        if(player->items[i].weights >= batasBawah && player->items[i].weights <= batasAtas){
                if(strcmp(player->items[i].type, "Weapon") == 0) {
                    printf("%-20s %-10s %-20.2f DPS %-50s\n", player->items[i].name, "Weapon", player->items[i].dps, player->items[i].description);
                }
                else if(strcmp(player->items[i].type, "Armor") == 0) {
                    printf("%-20s %-10s %-20.2f HP %-50s\n", player->items[i].name, "Armor", player->items[i].durability, player->items[i].description);
                }
                else {
                    printf("%-20s %-10s %-20.2f S %-50s\n", player->items[i].name, "Other", "N/A", player->items[i].description);
                }
        }
    }
}

int searchHarga(itemInventory* player) {
    float batasAtas, batasBawah;

    do {
        printf("Masukkan Batas Atas: "); scanf("%f", &batasAtas);
        printf("Masukkan Batas Bawah: "); scanf("%f", &batasBawah);

        if(batasAtas > batasBawah) {
            system("cls"); printf("Batas atas harus diatas batas bawah!"); getch(); system("cls");
        }
    } while(batasAtas > batasBawah);

    printf("%-20s %-10s %-20s %-50s\n", "Name", "Type", "Attribute", "Description");
    printf("--------------------------------------------------------------------------------\n");

    for (int i = 0; i < player->numberOfItems; i++){
        if(player->items[i].price >= batasBawah && player->items[i].price <= batasAtas){
                if(strcmp(player->items[i].type, "Weapon") == 0) {
                    printf("%-20s %-10s %-20.2f DPS %-50s\n", player->items[i].name, "Weapon", player->items[i].dps, player->items[i].description);
                }
                else if(strcmp(player->items[i].type, "Armor") == 0) {
                    printf("%-20s %-10s %-20.2f HP %-50s\n", player->items[i].name, "Armor", player->items[i].durability, player->items[i].description);
                }
                else {
                    printf("%-20s %-10s %-20.2f S %-50s\n", player->items[i].name, "Other", "N/A", player->items[i].description);
                }
        }
    }
}

void searchingInventory(itemInventory* player) {
    int pilihan, pilihanType, urutan;
    char namaItem[100];

    system("cls");
    printf("\n");
    printf(" +-------------------------------------------------+\n");
    printf(" |               Pilih Metode Searching            |\n");
    printf(" +-------------------------------------------------+\n");
    printf(" | No. |                Description                |\n");
    printf(" +-----+-------------------------------------------+\n");
    printf(" |  1  | Searching Berdasarkan Nama                |\n");
    printf(" +-----+-------------------------------------------+\n");
    printf(" |  2  | Searching Berdasarkan Tipe Item           |\n");
    printf(" +-----+-------------------------------------------+\n");
    printf(" |  3  | Searching Berdasarkan Atribute Item       |\n");
    printf(" +-----+-------------------------------------------+\n");
    printf(" |  4  | Searching Berdasarkan Berat Item          |\n");
    printf(" +-----+-------------------------------------------+\n");
    printf(" |  5  | Searching Berdasarkan Harga Item          |\n");
    printf(" +-----+-------------------------------------------+\n");
    
    printf("Pilihan: "); scanf("%d", &pilihan); system("cls");

      switch(pilihan) {
        case 1 : printf("Masukkan nama item: "); scanf(" %[^\n]", &namaItem); searchingNama(&player, namaItem); break;

        case 2 :
        printf(" +-------------------------------------------------+\n");
        printf(" |                  Search Item                    |\n");
        printf(" +-------------------------------------------------+\n");
        printf(" | No. |                Description                |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  1  | Weapon                                    |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  2  | Armor                                     |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  3  | Other                                     |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf("Masukkkan Pilihan: "); scanf("%d", &pilihanType);

        switch(pilihanType) {
            case 1 : system("cls"); searchingTipe(&player, 1); system("cls"); break;

            case 2 : system("cls"); searchingTipe(&player, 2); system("cls"); break;

            case 3 : system("cls"); searchingTipe(&player, 3); system("cls"); break;
        }

        break;

        case 3 :
        printf(" +-------------------------------------------------+\n");
        printf(" |                  Search Item                    |\n");
        printf(" +-------------------------------------------------+\n");
        printf(" | No. |                Description                |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  1  | Search by DPS                               |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  2  | Search By Durability                       |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf("Masukkkan Pilihan: "); scanf("%d", &pilihanType);

        switch(pilihanType) {
            case 1 : system("cls"); searchDPS(&player); system("cls"); break;

            case 2 : system("cls"); searchDurability(&player); system("cls"); break;

        }

        break; 

        case 4 : system("cls"); searchBerat(&player); system("cls"); break;

        case 5 : system("cls"); searchHarga(&player); system("cls"); break;
    }

}
