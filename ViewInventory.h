// Header File Untuk Melihat Inventory dalam "PROGRAM MANAGEMENT INVENTORY DAN SHOP DALAM GAME RPG"
// Versi 1.5

// Pendeklarasian library-library yang akan digunakan dan juga pendeklarasian struct di header terpisah
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "struct.h"

// Pendeklarasian semua prototype function yang berlaku di dalam header file ini
int itemTypePriority(const char* itemType);
float getItemPrimaryAttribute(const itemsTypes* item);
void sortirNama(itemInventory* player, int urutan);
void sortirTipeItem(itemInventory* player);
void sortirNilaiAtribut(itemInventory* player, int urutan);
void sortirBeratItem(itemInventory* player, int urutan);
void sortirHargaItem(itemInventory* player, int urutan);
void menuSortirInventory(itemInventory* player);
void string_to_lower(char *str);
void searchingNama(itemInventory* player, char* namaItem);
void searchingTipe(itemInventory* player, int pilihan);
int searchDPS(itemInventory* player);
int searchDurability(itemInventory* player);
int searchBerat(itemInventory* player);
int searchHarga(itemInventory* player);
void searchingInventory(itemInventory* player);

// Function utama dalam header file ini, menu keseluruhan inventory management untuk player
void viewInventory(itemInventory *player) {

    // Pendeklarasian int trigger dan pilihan untuk menginisiasi pemilihan dalam program dan juga trigger untuk mematikan fungsi utama header file ini
    int trigger = 0, pilihan;

    // Penunjukkan isi inventory pada player dalam while loop, yang akan berjalan terus menerus sampai trigger > 1
    do {
    
    // Menunjukkan uang yang sedang dimiliki oleh player
    printf("Jumlah uang yang dimiliki : %.2f\n", player->money);

    // Menunjukkan carry load yang tersisa dalam player
    printf("Carry weight tersisa: %.2f\n", player->carryLoad);

    // Ketika player tidak punya item, maka akan otomatis masuk ke dalam main menu
    if(player->numberOfItems == 0) {
        printf("Anda Saat Ini Tidak Punya Item!\n");
        return;
    }

// Print tabel dimana semua info dan data dari item yang ada di dalam inventory akan di display
printf("%-20s %-10s %-15s %-10s %-10s %-50s\n", "Name", "Type", "Attribute", "Weights", "Price", "Description");
printf("----------------------------------------------------------------------------------------------------------\n");

for(int i = 0; i < player->numberOfItems; i++) {
    char attributeString[20]; 
    if(player->items[i].Kode == 0) { 
        snprintf(attributeString, sizeof(attributeString), "%.2f DPS", player->items[i].dps);
    } else if(player->items[i].Kode == 1) { 
        snprintf(attributeString, sizeof(attributeString), "%.2f HP", player->items[i].durability);
    } else { 
        snprintf(attributeString, sizeof(attributeString), "%s", "N/A");
    }

    printf("%-20s %-10s %-15s %-10.2f %-10.2f %-50s\n", 
           player->items[i].name, 
           player->items[i].type, 
           attributeString, 
           player->items[i].weights, 
           player->items[i].price, 
           player->items[i].description);
}

    // Menu untuk pilihan yang bisa dilakukan di dalam header file ini mengenai inventory management (sortir inventory / searching inventory)
    printf("1. Sort Items\n2.Search for Items\n3.Back To Main Menu\nPilihan: "); scanf("%d", &pilihan); system("cls");

    switch(pilihan) {

        // Jika player memilih sortir inventory, maka struct player akan dipassing ke dalam fungsi menu utama dalam sorting inventory
        case 1 : system("cls"); menuSortirInventory(player);
        break;

        // Jika player memilih searching inventory, maka struct player akan dipassing ke dalam fungsi menu utama dalam searching inventory
        case 2 : system("cls"); searchingInventory(player);
        break;
        case 3 : trigger++;
        break;

        default : printf("Masukkan input yang valid!"); getch(); system("cls");
    }

    } while(trigger == 0);
}


// Fungsi untuk mengganti priority item dan tipe item dalam pensortiran tipe
int itemTypePriority(const char* itemType) {
    if(strcmp(itemType, "Weapon") == 0) return 1;
    else if(strcmp(itemType, "Armor") == 0) return 2;
    else return 3;
}

// Fungsi untuk mendapatkan niai dari attribute pada item dalam pensortiran berdasarkan attribute
float getItemPrimaryAttribute(const itemsTypes* item) {
    if(strcmp(item->type, "Weapon") == 0) return item->dps;
    else if(strcmp(item->type, "Armor") == 0) return item->durability;
}

// Fungsi yang berfungsi untuk sorting nama secara ascending maupun descending, fungsi akan passing urutan juga, untuk menentukan ascending / descending
void sortirNama(itemInventory* player, int urutan) {
    for(int i = 0; i < player->numberOfItems - 1; i++) {
        for(int j = 0; j < player->numberOfItems - i - 1; j++) {
            // urutan bernilai satu maka akan Ascending
            if(urutan == 1 && strcmp(player->items[j].name, player->items[j + 1].name) > 0) {
                itemsTypes temp = player->items[j];
                player->items[j] = player->items[j + 1];
                player->items[j + 1] = temp;
            }
            // urutan bernilai nol maka akan Descending
            else if(urutan == 0 && strcmp(player->items[j].name, player->items[j + 1].name) < 0) {
                itemsTypes temp = player->items[j];
                player->items[j] = player->items[j + 1];
                player->items[j + 1] = temp;
            }
        }
    }
}

// Fungsi untuk melakukan penyortiran item sesuai dengan tipe itemnya
void sortirTipeItem(itemInventory* player) {

    // Akan iterasi seluruh item yang ada dan akan cek priority listnya dimana, priority utama adalah weapon dan armor, dimana mereka akan saling dikelompokkan
    for(int i = 0; i < player->numberOfItems; i++) {
        for(int j = 0; j < player->numberOfItems - 1 - i; j++) {

            // Menentukan item priority
            int priorityCurrent = itemTypePriority(player->items[j].type);
            int priorityNext = itemTypePriority(player->items[j + 1].type);

            // Sinyal dimana apakah fungsi perlu melakukan swap atau tidak
            int needSwap = (priorityCurrent > priorityNext) || (priorityCurrent == priorityNext && strcmp(player->items[j].name, player->items[j + 1].name) > 0);

            // Perlakuan swap pada item-item
            if(needSwap) {
                itemsTypes temp = player->items[j];
                player->items[j] = player->items[j + 1];
                player->items[j + 1] = temp;
            }
        }
    }
}

// Fungsi untuk melakukan penyortiran item sesuai dengan nilai attributenya
void sortirNilaiAtribut(itemInventory* player, int urutan) {

    // Jika nilai urutan yang dipassing dari fungsi adalah satu, maka dia akan melakukan sorting nilai pada attribute secara ascending
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

    // Jika nilai urutan yang dipassing dari fungsi adalah selain satu, maka dia akan melakukan sorting nilai pada attribute secara descending
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


// Fungsi untuk melakukan penyortiran item sesuai dengan berat item
void sortirBeratItem(itemInventory* player, int urutan) {

    // Jika nilai urutan yang dipassing dari fungsi adalah satu, maka dia akan melakukan sorting berat secara ascending
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

    // Jika nilai urutan yang dipassing dari fungsi adalah selain satu, maka dia akan melakukan sorting berat secara descending
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

// Fungsi melakukan penyortiran item sesuai dengan harga item
void sortirHargaItem(itemInventory* player, int urutan) {

    // Jika nilai urutan yang dipassing dari fungsi adalah satu, maka dia akan melakukan sorting harga secara ascending
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

    // Jika nilai urutan yang dipassing dari fungsi adalah selain satu, maka dia akan melakukan sorting berat secara descending
    else {
        for(int i = 0; i < player->numberOfItems; i++) {
            for(int j = 0; j < player->numberOfItems - 1 -i; j++) { 
                if(player->items[j].price < player->items[j + 1].price) {
                    itemsTypes temp = player->items[j];
                    player->items[j] = player->items[j + 1];
                    player->items[j + 1] = temp;
                }
            }
        }
    }
}

// Fungsi utama dalam pemilihan jenis penyortiran pada program
void menuSortirInventory(itemInventory* player) {
    int pilihan, urutan;

    // Tampilan menu pada penyortiran di dalam program
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

        // Case 1 dimana akan dipassing nilai struct dan pilihan ke dalam sortirNama 
        case 1 : 
        do {
            printf("Ascending / Descending? (1 / 0): ");
            scanf("%d", &urutan);
            if (urutan != 1 && urutan != 0) {
            system("cls");
                printf("Invalid input. Silahkan masukkan 1 untuk Ascending or 0 untuk Descending: ");
            }
        } while(urutan != 1 && urutan != 0);
        sortirNama(player, urutan);
        break;

        // Case 2 dimana akan dipassing nilai struct player ke dalam sortirTipeItem 
        case 2 : sortirTipeItem(player); break;

        // Case 3 dimana akan dipassing nilai struct dan pilihan ke dalam sortirNilaiAttribute 
        case 3 : 
        printf("Ascending / Descending? (1 / 0): ");
        do {
            scanf("%d", &urutan);
            if (urutan != 1 && urutan != 0) {
                printf("Invalid input. Silahkan masukkan 1 untuk Ascending or 0 untuk Descending: ");
            }
        } while(urutan != 1 && urutan != 0);
        sortirNilaiAtribut(player, urutan);
        break;

        // Case 4 dimana akan dipassing nilai struct dan pilihan ke dalam sortirBeratItem 
        case 4 :
        printf("Ascending / Descending? (1 / 0): ");
        do {
            scanf("%d", &urutan);
            if (urutan != 1 && urutan != 0) {
                printf("Invalid input. Silahkan masukkan 1 untuk Ascending or 0 untuk Descending: ");
            }
        } while(urutan != 1 && urutan != 0);
        sortirBeratItem(player, urutan);
        break;

        // Case 5 dimana akan dipassing nilai struct dan pilihan ke dalam sortirHargaItem 
        case 5 : 
        printf("Ascending / Descending? (1 / 0): ");
        do {
            scanf("%d", &urutan);
            if (urutan != 1 && urutan != 0) {
                printf("Invalid input. Silahkan masukkan 1 untuk Ascending or 0 untuk Descending: ");
            }
        } while(urutan != 1 && urutan != 0);
        sortirHargaItem(player, urutan);
        break;
    }

}

// Fungsi untuk lower semua character dalam string menggunakan library string.h
void string_to_lower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Fungsi yang melakukan searching nama pada item-item yang ada di inventory
void searchingNama(itemInventory* player, char* namaItem) {
    // Buffer untuk nama item yang akan di lower, sehingga searching bersifat non case sensitive
    char namaItemLower[100];

    // Lower nama item yang dicari
    string_to_lower(namaItem);

    // Print tabel dan content-nya sesuai dengan searching nama yang diterapkan
    printf("%-20s %-10s %-15s %-10s %-10s %-50s\n", "Name", "Type", "Attribute", "Weights", "Price", "Description");
    printf("----------------------------------------------------------------------------------------------------------\n");
    for(int i = 0; i < player->numberOfItems; i++) {
        strcpy(namaItemLower, player->items[i].name);
        string_to_lower(namaItemLower);

        // Penerapan searching menggunakan strstr untuk mencari apakah ada string di dalam string, jika ada maka data tersebut akan di print
        if(strstr(namaItemLower, namaItem) != NULL) {
            char attributeString[20]; 
            if(player->items[i].Kode == 0) { 
                snprintf(attributeString, sizeof(attributeString), "%.2f DPS", player->items[i].dps);
            } else if(player->items[i].Kode == 1) { 
                snprintf(attributeString, sizeof(attributeString), "%.2f HP", player->items[i].durability);
            } else { 
                snprintf(attributeString, sizeof(attributeString), "%s", "N/A");
            }

    
            printf("%-20s %-10s %-15s %-10.2f %-10.2f %-50s\n", 
                player->items[i].name, 
                player->items[i].type, 
                attributeString, 
                player->items[i].weights, 
                player->items[i].price, 
                player->items[i].description);
        }
    } 

    printf("Press Any Button to Continue"); getch(); system("cls");
}

// Fungsi untuk melakuakn searching sesuai dengan tipe yang dipilih
void searchingTipe(itemInventory* player, int pilihan) {

    printf("%-20s %-10s %-15s %-10s %-10s %-50s\n", "Name", "Type", "Attribute", "Weights", "Price", "Description");
    printf("----------------------------------------------------------------------------------------------------------\n");

    // Jika pilihan bernilai satu maka fungsi akan menjalankan dan menunjukkan data yang memiliki type weapon
    if(pilihan == 1) {
        for(int i = 0; i < player->numberOfItems; i++) {
            if(strcmp(player->items[i].type, "Weapon") == 0) {
                char attributeString[20]; 
                if(player->items[i].Kode == 0) { 
                    snprintf(attributeString, sizeof(attributeString), "%.2f DPS", player->items[i].dps);
                } else if(player->items[i].Kode == 1) { 
                    snprintf(attributeString, sizeof(attributeString), "%.2f HP", player->items[i].durability);
                } else { 
                    snprintf(attributeString, sizeof(attributeString), "%s", "N/A");
                }

        
                printf("%-20s %-10s %-15s %-10.2f %-10.2f %-50s\n", 
                    player->items[i].name, 
                    player->items[i].type, 
                    attributeString, 
                    player->items[i].weights, 
                    player->items[i].price, 
                    player->items[i].description);
            }
        }
    }

    // Jika pilihan bernilai dua maka fungsi akan menjalankan dan menunjukkan data yang memiliki type armor
    else if(pilihan == 2) {
        for(int i = 0; i < player->numberOfItems; i++) {
            if(strcmp(player->items[i].type, "Armor") == 0) {
                char attributeString[20]; 
                if(player->items[i].Kode == 0) { 
                    snprintf(attributeString, sizeof(attributeString), "%.2f DPS", player->items[i].dps);
                } else if(player->items[i].Kode == 1) { 
                    snprintf(attributeString, sizeof(attributeString), "%.2f HP", player->items[i].durability);
                } else { 
                    snprintf(attributeString, sizeof(attributeString), "%s", "N/A");
                }

        
                printf("%-20s %-10s %-15s %-10.2f %-10.2f %-50s\n", 
                    player->items[i].name, 
                    player->items[i].type, 
                    attributeString, 
                    player->items[i].weights, 
                    player->items[i].price, 
                    player->items[i].description);
            }
        }
    }

    // Jika nilai pilihan tidak 1 ataupun 2, maka fungsi akan menjallankan dan menunjukkan data yang memiliki tipe other
    else  {
        for(int i = 0; i < player->numberOfItems; i++) {
            if(strcmp(player->items[i].type, "Other") == 0) {
                char attributeString[20]; 
                if(player->items[i].Kode == 0) { 
                    snprintf(attributeString, sizeof(attributeString), "%.2f DPS", player->items[i].dps);
                } else if(player->items[i].Kode == 1) { 
                    snprintf(attributeString, sizeof(attributeString), "%.2f HP", player->items[i].durability);
                } else { 
                    snprintf(attributeString, sizeof(attributeString), "%s", "N/A");
                }

        
                printf("%-20s %-10s %-15s %-10.2f %-10.2f %-50s\n", 
                    player->items[i].name, 
                    player->items[i].type, 
                    attributeString, 
                    player->items[i].weights, 
                    player->items[i].price, 
                    player->items[i].description);
            }
        }
    }

    printf("Press Any Button to Continue!"); getch(); system("cls");
}

// Fungsi untuk searching item sesuai dengan dps yang ditentukan
int searchDPS(itemInventory* player) {
    float batasAtas, batasBawah;

    // Do while dimana batas atas harus diatas batas bawah ketika ingin melanjutkan sorting (error handling)
    do {
        // Menentukan batas atas dan batas bawah dps 
        printf("Masukkan Batas Atas: "); scanf("%f", &batasAtas);
        printf("Masukkan Batas Bawah: "); scanf("%f", &batasBawah);

        if(batasAtas < batasBawah) {
            system("cls"); printf("Batas atas harus diatas batas bawah!"); getch(); system("cls");
        }
    } while(batasAtas < batasBawah);

    // Display tabel dimana dia akan mencari item yang berada di batas atas bawah dan dibawah batas atas dan print data item tersebut
    printf("%-20s %-10s %-15s %-10s %-10s %-50s\n", "Name", "Type", "Attribute", "Weights", "Price", "Description");
    printf("----------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < player->numberOfItems; i++){
        if(strcmp(player->items[i].type, "Weapon") == 0 && player->items[i].dps >= batasBawah && player->items[i].dps <= batasAtas){
                char attributeString[20]; 
                if(player->items[i].Kode == 0) { 
                    snprintf(attributeString, sizeof(attributeString), "%.2f DPS", player->items[i].dps);
                } else if(player->items[i].Kode == 1) { 
                    snprintf(attributeString, sizeof(attributeString), "%.2f HP", player->items[i].durability);
                } else { 
                    snprintf(attributeString, sizeof(attributeString), "%s", "N/A");
                }

        
                printf("%-20s %-10s %-15s %-10.2f %-10.2f %-50s\n", 
                    player->items[i].name, 
                    player->items[i].type, 
                    attributeString, 
                    player->items[i].weights, 
                    player->items[i].price, 
                    player->items[i].description);
        }
    }

    printf("Press Any Button to Continue!"); getch(); system("cls");

}

// Fungsi untuk searching item sesuai dengan durability yang ditentukan
int searchDurability(itemInventory* player) {
    float batasAtas, batasBawah;

    // Do while dimana batas atas harus diatas batas bawah ketika ingin melanjutkan sorting (error handling)
    do {
        // Menentukan batas atas dan batas bawah dari durability yang ingin dicari
        printf("Masukkan Batas Atas: "); scanf("%f", &batasAtas);
        printf("Masukkan Batas Bawah: "); scanf("%f", &batasBawah);

        if(batasAtas < batasBawah) {
            system("cls"); printf("Batas atas harus diatas batas bawah!"); getch(); system("cls");
        }
    } while(batasAtas < batasBawah);

    // Print semua data yang berada diantara batas atas dan juga batas bawah
    printf("%-20s %-10s %-15s %-10s %-10s %-50s\n", "Name", "Type", "Attribute", "Weights", "Price", "Description");
    printf("----------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < player->numberOfItems; i++){
        if(strcmp(player->items[i].type, "Armor") == 0 && player->items[i].durability >= batasBawah && player->items[i].durability <= batasAtas){
                char attributeString[20]; 
                if(player->items[i].Kode == 0) { 
                    snprintf(attributeString, sizeof(attributeString), "%.2f DPS", player->items[i].dps);
                } else if(player->items[i].Kode == 1) { 
                    snprintf(attributeString, sizeof(attributeString), "%.2f HP", player->items[i].durability);
                } else { 
                    snprintf(attributeString, sizeof(attributeString), "%s", "N/A");
                }

        
                printf("%-20s %-10s %-15s %-10.2f %-10.2f %-50s\n", 
                    player->items[i].name, 
                    player->items[i].type, 
                    attributeString, 
                    player->items[i].weights, 
                    player->items[i].price, 
                    player->items[i].description);
        }
    }

    printf("Press Any Button to Continue!"); getch(); system("cls");
}

// Searching berdasarkan berat item dalam inventory player
int searchBerat(itemInventory* player) {
    float batasAtas, batasBawah;

    // Do while dimana batas atas harus diatas batas bawah ketika ingin melanjutkan sorting (error handling)
    do {
        // Input batas atas dan batas bawah dari berat item yang ingin dicari
        printf("Masukkan Batas Atas: "); scanf("%f", &batasAtas);
        printf("Masukkan Batas Bawah: "); scanf("%f", &batasBawah);

        if(batasAtas < batasBawah) {
            system("cls"); printf("Batas atas harus diatas batas bawah!"); getch(); system("cls");
        }
    } while(batasAtas < batasBawah);

    // Program akan print data yang dimana jumlah beratnya berada diantara batas atas dan batas bawah 
    printf("%-20s %-10s %-15s %-10s %-10s %-50s\n", "Name", "Type", "Attribute", "Weights", "Price", "Description");
    printf("----------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < player->numberOfItems; i++){
        if(player->items[i].weights >= batasBawah && player->items[i].weights <= batasAtas){
                char attributeString[20]; 
                if(player->items[i].Kode == 0) { 
                    snprintf(attributeString, sizeof(attributeString), "%.2f DPS", player->items[i].dps);
                } else if(player->items[i].Kode == 1) { 
                    snprintf(attributeString, sizeof(attributeString), "%.2f HP", player->items[i].durability);
                } else { 
                    snprintf(attributeString, sizeof(attributeString), "%s", "N/A");
                }

        
                printf("%-20s %-10s %-15s %-10.2f %-10.2f %-50s\n", 
                    player->items[i].name, 
                    player->items[i].type, 
                    attributeString, 
                    player->items[i].weights, 
                    player->items[i].price, 
                    player->items[i].description);
        }
    }

    printf("Press Any Button to Continue!"); getch(); system("cls");
}

// Searching berdasarkan harga item pada inventory
int searchHarga(itemInventory* player) {
    float batasAtas, batasBawah;

    // Do while dimana batas atas harus diatas batas bawah ketika ingin melanjutkan sorting (error handling)
    do {
        // Input batas atas dan batas bawah dari harga yang ingin dicari dalam inventory
        printf("Masukkan Batas Atas: "); scanf("%f", &batasAtas);
        printf("Masukkan Batas Bawah: "); scanf("%f", &batasBawah);

        if(batasAtas < batasBawah) {
            system("cls"); printf("Batas atas harus diatas batas bawah!"); getch(); system("cls");
        }
    } while(batasAtas < batasBawah);

    // Print data-data yang sudah memenuhi batas atas dan batas bawah harganya
    printf("%-20s %-10s %-15s %-10s %-10s %-50s\n", "Name", "Type", "Attribute", "Weights", "Price", "Description");
    printf("----------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < player->numberOfItems; i++){
        if(player->items[i].price >= batasBawah && player->items[i].price <= batasAtas){
                char attributeString[20]; 
                if(player->items[i].Kode == 0) { 
                    snprintf(attributeString, sizeof(attributeString), "%.2f DPS", player->items[i].dps);
                } else if(player->items[i].Kode == 1) { 
                    snprintf(attributeString, sizeof(attributeString), "%.2f HP", player->items[i].durability);
                } else { 
                    snprintf(attributeString, sizeof(attributeString), "%s", "N/A");
                }

        
                printf("%-20s %-10s %-15s %-10.2f %-10.2f %-50s\n", 
                    player->items[i].name, 
                    player->items[i].type, 
                    attributeString, 
                    player->items[i].weights, 
                    player->items[i].price, 
                    player->items[i].description);
        }
    }

    printf("Press Any Button to Continue!"); getch(); system("cls");
}

// Fungsi menu utama dalam menentukan opsi searching pada inventory
void searchingInventory(itemInventory* player) {
    int pilihan, pilihanType, urutan;
    char namaItem[100];

    // Menu utama dalam searching pada fungsi inventory
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
    
    // Switch untuk pemilihan jenis searching apa yang ingin dilakuakn
      switch(pilihan) {
        // Case 1 menerapkan searching nama, sehingga player harus memberikan nama item terlebih dahulu yang ingin di search
        case 1 : 
        printf("Masukkan nama item: "); scanf(" %[^\n]", namaItem);
        searchingNama(player, namaItem);
        getch();
        break;

        // Case dua akan menurun menjadi sub switch, dimana dia akan memilih menampilkan weapon, armor, atau item dengan tipe other
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
            case 1 : system("cls"); searchingTipe(player, 1); getch(); system("cls"); break;

            case 2 : system("cls"); searchingTipe(player, 2); getch(); system("cls"); break;

            case 3 : system("cls"); searchingTipe(player, 3); getch(); system("cls"); break;
            
            default : printf("Masukkan input yang valid!"); getch(); system("cls");
        }

        break;

        // Case ketiga diturunkan menjadi sub switch juga sesuai dengan dps dan durability
        case 3 :
        printf(" +-------------------------------------------------+\n");
        printf(" |                  Search Item                    |\n");
        printf(" +-------------------------------------------------+\n");
        printf(" | No. |                Description                |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  1  | Search by DPS                             |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  2  | Search By Durability                      |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf("Masukkkan Pilihan: "); scanf("%d", &pilihanType);

        switch(pilihanType) {
            case 1 : system("cls"); searchDPS(player); getch(); system("cls"); break;

            case 2 : system("cls"); searchDurability(player); getch(); system("cls"); break;

            default : printf("Masukkan input yang valid!"); getch(); system("cls");

        }

        break; 

        // Case 4 dimana player akan menjalankan fungsi searchBerat untuk searching dengan berat
        case 4 : system("cls"); searchBerat(player); getch(); system("cls"); break;

        // Case 5 dimana player akan menjalankan fungsi searchHarga untuk searching dengan harga
        case 5 : system("cls"); searchHarga(player); getch(); system("cls"); break;

        default : printf("Masukkan input yang valid!"); getch(); system("cls");
    }

}