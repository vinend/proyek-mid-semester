#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ProcessData(char *line, itemsTypes **Weapon, itemsTypes **Armor, int *JumlahW, int *JumlahA) {
    itemsTypes newItem;
    // Attempt to parse the line with sscanf. Ensure the format matches the expected input.
    int result = sscanf(line, "%d,%[^,],%f,%f,%f,%f,%[^,\n]", &newItem.Kode, newItem.name, &newItem.weights, &newItem.price, &newItem.dps, &newItem.durability, newItem.description);

    if (result == 7) { // Successfully parsed all fields
        // Allocate or resize the items array based on Kode
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

void mainIsiShop(itemsTypes **Weapon, itemsTypes **Armor,  int *JumlahW, int *JumlahA) {
    FILE *file = fopen("MainShop.txt", "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }
    char line[400];
    while (fgets(line, sizeof(line), file)) {
        ProcessData(line, Weapon, Armor, JumlahW, JumlahA);
    }

    fclose(file);
}