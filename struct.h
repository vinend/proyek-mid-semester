#ifndef STRUCTCUSTOM
#define STRUCTCUSTOM

typedef struct itemTypes{
    float weights;
    float price;
    float dps;
    float durability;
    float effectDuration;
    char description[500];
    char type[300];
    char name[300];
}itemsTypes;

struct itemInventory{
    float money;
    int carryLoad;
    int numberOfItems;
    itemsTypes *items; 
};

typedef struct{
    itemsTypes *Sword;
    itemsTypes *Bow;
}WeaponShop;

typedef struct{
    itemsTypes *Helmet;
    itemsTypes *Vests;
    itemsTypes *Leggings;
    itemsTypes *Helmet;
}ArmorShop;
#endif