#ifndef STRUCTCUSTOM
#define STRUCTCUSTOM

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

typedef struct {
    float money;
    float carryLoad;
    int numberOfItems;
    itemsTypes *items; 
}itemInventory;


#endif