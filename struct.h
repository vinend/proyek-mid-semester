typedef struct{
    float weights;
    float price;
    float dps;
    float durability;
    char description[500];
    char type[300];
    char name[300];
}items;

typedef struct{
    int money;
    int carryLoad;
    int numberOfItems;
    items *items;
}inventory;