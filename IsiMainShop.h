#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ProcessData(char *line, itemsTypes **items, int *count) {
    itemsTypes newItem;
    // Adjust sscanf to properly parse your data structure.
    sscanf(line, "%[^,],%f,%f,%f,%f,%[^\n]", newItem.name, &newItem.weights, &newItem.price, &newItem.dps, &newItem.durability, newItem.description);

    // Dynamically allocate or resize the items array
    itemsTypes *tempItems = realloc(*items, (*count + 1) * sizeof(itemsTypes));
    if (tempItems == NULL) {
        perror("Unable to allocate memory");
        exit(EXIT_FAILURE);
    }
    *items = tempItems;

    // Add the new item to the array
    (*items)[*count] = newItem;
    (*count)++;
}

void mainIsiShop(itemsTypes **items, int *count) {
    FILE *file = fopen("MainShop.txt", "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    char line[400];
    while (fgets(line, sizeof(line), file)) {
        ProcessData(line, items, count);
    }

    fclose(file);
}
