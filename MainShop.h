#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "struct.h"

void PilihWeapon(int PilihanWeapon){

}

void PilihArmor(){

}


int MainSHOP(itemInventory *player[], itemsTypes Weapon[]){
    int PilihanArmorWeapon, PilihanWeapon, PilihanArmor;
    for (int i = 0; i < 2; i++) {
        printf("\nItem %d: Name: %s, DPS: %.2f\n", i, Weapon[i].name, Weapon[i].dps);
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
