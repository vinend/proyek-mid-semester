#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "struct.h"

void PilihWeapon(itemInventory *player[],int JumlahW, itemsTypes Weapon[]){
    int i, PilihanWeapon, PilihanBeli;
    system("cls");
        printf(" +-------------------------------------------------+\n");
        printf(" |          PILIH SENJATA MEMATIKAN ANDA           |\n");
        printf(" +-------------------------------------------------+\n");
        printf(" | No. |              Nama Weapon                  |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  1  | Old Sword                                 |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  2  | Iron Guard Sword                          |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  3  | Hard Diamond Sword                        |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  4  | Fire Magma Sword                          |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  5  | Sword of Doom                             |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  6  | Umbrella                                  |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  7  | Back To Shop Menu                         |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf("Masukkan Pilihan Weapon: "); // Prompt for user input
        scanf("%d", &PilihanWeapon); // Correct usage of scanf
        PilihWeapon :
        switch (PilihanWeapon){
            case 1 : 
            TampilkanWeapon(Weapon, PilihanWeapon);
            scanf("%d", &PilihanBeli);
            break;
            case 2 : 
            TampilkanWeapon(Weapon, PilihanWeapon);
            break;
            case 3 :  
            TampilkanWeapon(Weapon, PilihanWeapon); 
			break; 
            case 4 :
            TampilkanWeapon(Weapon, PilihanWeapon);
            break;
            case 5 :
            TampilkanWeapon(Weapon, PilihanWeapon);
            break;
            case 6 :
            TampilkanWeapon(Weapon, PilihanWeapon);
            break;
            case 7 :
            break;
        }
}

void TampilkanWeapon(itemsTypes Weapon[], int PilihanWeapon){
    system("cls");
    printf("Nama Weapon  : %s\n", Weapon->name);
    printf("Berat Weapon : %.0f Kg\n", Weapon->weights);
    printf("Harga Weapon : %.0f Dollar\n", Weapon->price);
    printf("DPS Weapon   : %.0f \n", Weapon->dps);
    printf("Desc Weapon : \n%s \n", Weapon->description);
    printf("Apakah Anda ingin membeli Weapon ini ? (Yes = 1, No = 2, Back To Menu : 3)\n");
    printf("Masukkan Pilihan Anda : ");
}

void PilihArmor(itemInventory *player[], int JumlahA, itemsTypes Armor[]){
    int i, PilihanArmor;
    system("cls");
        printf(" +-------------------------------------------------+\n");
        printf(" |   PILIH ARMOR YANG KUAT UNTUK MELINDUNGI ANDA   |\n");
        printf(" +-------------------------------------------------+\n");
        printf(" | No. |               Nama Armor                  |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  1  | Leather Armor                             |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  2  | Iron Chain Armor                          |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  3  | Dragon Skin Armor                         |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  4  | Shadow Armor                              |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  5  | Manchester United Jersey                  |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  6  | Back To Shop Menu                         |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf("Masukkan Pilihan Armor: "); // Prompt for user input
        scanf("%d", &PilihanArmor); // Correct usage of scanf
}

void TampilkanArmor(){
    
}


int MainSHOP(itemInventory *player[], itemsTypes Weapon[], itemsTypes Armor[], int JumlahW, int JumlahA){
    int PilihanArmorWeapon;
    ShopMenu :
        printf(" +-------------------------------------------------+\n");
        printf(" |                 Mau Beli Apa ?                  |\n");
        printf(" +-------------------------------------------------+\n");
        printf(" | No. |               Pilihan                     |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  1  | Weapon                                    |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  2  | Armor                                     |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  3  | Back to Main Menu                         |\n");
        printf(" +-----+-------------------------------------------+\n");
    scanf("%d", &PilihanArmorWeapon); // Correct usage of scanf
    switch (PilihanArmorWeapon) {
        case 1:
            MilihWeapon : 
            PilihWeapon(player, JumlahW, Weapon);
            break;
        case 2:
            MilihArmor :
            PilihArmor(player, JumlahA, Armor);
            break;
        case 3:
            break;
    }
}
