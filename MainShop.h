#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct{
    typedef struct items Sword;
}WeaponShop;

typedef struct{
    typedef struct items Armor;
}ArmorShop;

void PilihWeapon(int PilihanWeapon, WeaponShop MilihWeapon){

}

void PilihArmor(){

}

int MainSHOP(){
    int PilihanArmorWeapon, PilihanWeapon, PilihanArmor;
    WeaponShop *MilihWeapon = (WeaponShop*)malloc(sizeof(WeaponShop));
    ArmorShop *MilihArmor = (ArmorShop*)malloc(sizeof(ArmorShop));
    scanf("%d", &PilihanArmorWeapon);
    switch (PilihanArmorWeapon){
        case 1 : 
            scanf("PilihanWeapon");
            PilihWeapon(PilihanWeapon, MilihWeapon);
            break;
        case 2 : 
            scanf("PilihanArmor");
            break;
    }   
}