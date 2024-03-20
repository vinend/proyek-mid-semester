#ifndef STRUCTCUSTOM
#define STRUCTCUSTOM

// Struct untuk satu item
typedef struct {
    int Kode;
    float weights;
    float price;
    float dps;
    float durability;
    char description[500];
    char type[300];
    char name[300];
}itemsTypes;

// Struct untuk menyimpan suatu data untuk inventory
typedef struct {
    float money;
    float carryLoad;
    int numberOfItems;
    itemsTypes *items; 
}itemInventory;


#endif