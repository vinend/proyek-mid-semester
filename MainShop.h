#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "struct.h"

void PilihWeapon(int PilihanWeapon){

}

void PilihArmor(){

}


int MainSHOP(itemInventory *player[], itemsTypes Weapon[], itemsTypes Armor[], int JumlahW, int JumlahA){
    int PilihanArmorWeapon, PilihanWeapon, PilihanArmor;
    for (int i = 0; i < JumlahW; i++) {
        printf("\n 1tem %d: Name: %s, Weights :%.2f, Price :%.2f, DPS: %.2f, Durability : %.2f, Desc : %s \n", i, Weapon[i].name, Weapon[i].weights, Weapon[i].price, Weapon[i].dps, Weapon[i].durability, Weapon[i].description);
    }
    for(int i = 0; i < JumlahA; i++){
        printf("\n Nigger Item %d: Name: %s, Weights :%.2f, Price :%.2f, DPS: %.2f, Durability : %.2f, Desc : %s \n", i, Armor[i].name, Armor[i].weights, Armor[i].price, Armor[i].dps, Armor[i].durability, Armor[i].description);
    }
    scanf("%d", &PilihanArmorWeapon);
    scanf("%d", &PilihanArmorWeapon); // Correct usage of scanf
    switch (PilihanArmorWeapon) {
        case 1:
            printf("Masukkan Pilihan Weapon: "); // Prompt for user input
            scanf("%d", &PilihanWeapon); // Correct usage of scanf
            PilihWeapon(PilihanWeapon);
            break;
        case 2:
            printf("Masukkan Pilihan Armor: "); // Prompt for user input
            scanf("%d", &PilihanArmor); // Correct usage of scanf
            // Implementation of PilihArmor should be done here if necessary
            break;
    }
}
