#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "struct.h"

typedef struct{
    itemsTypes *Sword;
}WeaponShop;

typedef struct{
    itemsTypes *Armor;
}ArmorShop;

void PilihWeapon(int PilihanWeapon, WeaponShop MilihWeapon[]){

}

void PilihArmor(){

}

void initializeShopItems(struct itemInventory *shop, int jumlahItem) {
    shop->carryLoad = 100000;
    shop->money = 10000;
    shop->numberOfItems = jumlahItem;

     shop->items = (struct itemsTypes*)malloc(jumlahItem * sizeof(itemsTypes));

     for(int i = 0; i < jumlahItem; i++) {
        system("cls");
        printf("Masukkan nama item: "); scanf(" %[^\n]", shop->items[i].name);
        printf("Masukkan type item: "); scanf(" %[^\n]", shop->items[i].type);
        printf("Masukkan Weight Items"); scanf("%f", shop->items[i].weights);
        if(strcmp(shop->items[i].type, "Weapon") == 0) {
            printf("Masukkan Damage Weapon: "); scanf("%f", shop->items[i].dps);
        } else if(strcmp(shop->items[i].type, "Armor") == 0) {
            printf("Masukkan Durability Armor: "); scanf("%f", shop->items[i].durability);
        } else {
            printf("Masukkan Durasi Potion: "); scanf("%f", shop->items[i].dps);
        }
        printf("Masukkan Deskripsi Singkat Item: "); scanf(" %[^\n]", shop->items[i].description);
        printf("Masukkan Harga Item: "); scanf("%f", shop->items[i].price);

        system("cls");
     }
}

int MainSHOP(struct itemInventory* player){
    int PilihanArmorWeapon, PilihanWeapon, PilihanArmor;

    WeaponShop *MilihWeapon = (WeaponShop*)malloc(sizeof(WeaponShop));
    ArmorShop *MilihArmor = (ArmorShop*)malloc(sizeof(ArmorShop));
    scanf("%d", &PilihanArmorWeapon);
    scanf("%d", &PilihanArmorWeapon); // Correct usage of scanf
    switch (PilihanArmorWeapon) {
        case 1:
            printf("Masukkan Pilihan Weapon: "); // Prompt for user input
            scanf("%d", &PilihanWeapon); // Correct usage of scanf
            PilihWeapon(PilihanWeapon, MilihWeapon);
            break;
        case 2:
            printf("Masukkan Pilihan Armor: "); // Prompt for user input
            scanf("%d", &PilihanArmor); // Correct usage of scanf
            // Implementation of PilihArmor should be done here if necessary
            break;
    }
}