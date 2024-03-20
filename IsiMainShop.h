#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//fucnction untuk memproses data bedasarkan weapon dan armor dari file MainShop.txt
void ProcessData(char *line, itemsTypes **Weapon, itemsTypes **Armor, int *JumlahW, int *JumlahA) {
    itemsTypes newItem;
    // Memastikan format sesuai dengan input
    int result = sscanf(line, "%d,%[^,],%f,%f,%f,%f,%[^,],%[^,\n]", &newItem.Kode, newItem.name, &newItem.weights, &newItem.price, &newItem.dps, &newItem.durability, newItem.description, newItem.type);

    if (result == 8) { 
        // Mengallocate sesuai dengan kode 0 untuk Weapon dan 1 untuk Armor
        itemsTypes *tempItems = NULL;
        if (newItem.Kode == 0) {
            tempItems = realloc(*Weapon, (*JumlahW + 1) * sizeof(itemsTypes));
            if (!tempItems) {
                perror("Unable to allocate memory for Weapon");
                exit(EXIT_FAILURE);
            }
            *Weapon = tempItems;
            (*Weapon)[*JumlahW] = newItem;
            (*JumlahW)++;
        } else {
            tempItems = realloc(*Armor, (*JumlahA + 1) * sizeof(itemsTypes));
            if (!tempItems) {
                perror("Unable to allocate memory for Armor");
                exit(EXIT_FAILURE);
            }
            *Armor = tempItems;
            (*Armor)[*JumlahA] = newItem;
            (*JumlahA)++;
        }
    } else {
        fprintf(stderr, "Error parsing line: %s\n", line);
    }
}

// Main untuk Isi Shop
void mainIsiShop(itemsTypes **Weapon, itemsTypes **Armor,  int *JumlahW, int *JumlahA) {
    //Membuka data untuk file handling
    FILE *file = fopen("MainShop.txt", "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }
    char line[400];
    // Memanggil function dengan jika dalam file masih ditemukan line maka akan terus berlanjut sampai line pada MainShop.txt habis
    while (fgets(line, sizeof(line), file)) {
        ProcessData(line, Weapon, Armor, JumlahW, JumlahA);
    }
    // Menutup file
    fclose(file);
}