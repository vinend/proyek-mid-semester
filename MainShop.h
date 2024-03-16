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