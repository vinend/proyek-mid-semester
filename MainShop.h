#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "struct.h"

void PilihWeapon(itemInventory *player[], int JumlahW, itemsTypes Weapon[], int Weight, int NomorData){
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
            case 2 : 
            case 3 :  
            case 4 :
            case 5 :
            case 6 :
            TampilkanWeapon(Weapon, PilihanWeapon, Weight);
            scanf("%d", &PilihanBeli);
            PilihBeli :
            switch (PilihanBeli){
                case 1 :    
                MasukkanDataWeapon(player, Weapon, Weight, NomorData, PilihanBeli);
                break;
                case 2 : goto PilihWeapon;
                break;
                deafult :  
                printf("Pilihan salah ! Silahkan masukkan ulang");
                goto PilihBeli;
                }
            break;
            case 7 :
            break;
            default : printf("Pilihan salah ! Silahkan masukkan ulang");
            goto PilihWeapon;
        }
}

void TampilkanWeapon(itemsTypes Weapon[], int PilihanWeapon, int Weight){
    system("cls");
    printf("Nama Weapon  : %s\n", Weapon->name);
    printf("Berat Weapon : %.0f Kg\n", Weapon->weights);
    printf("Harga Weapon : %.0f Dollar\n", Weapon->price);
    printf("DPS Weapon   : %.0f \n", Weapon->dps);
    printf("Desc Weapon : \n%s \n", Weapon->description);
    printf("Apakah Anda ingin membeli Weapon ini ? (Yes = 1, No = 2)\n");
    printf("Masukkan Pilihan Anda : ");
}

void MasukkanDataWeapon(itemInventory *player[], itemsTypes Weapon[], int Weight, int NomorData, int i){
    int Beban, Harga;
    Harga = Weapon[i-1].price;
    Beban = Weapon[i-1].weights;
    *player[NomorData]->items = Weapon[i-1];
    player[NomorData]->carryLoad += Beban;
    player[NomorData]->money -= Harga;
    player[NomorData]->numberOfItems++;
}

void PilihArmor(itemInventory *player[], int JumlahA, itemsTypes Armor[], int Weight, int NomorData){
    int i, PilihanArmor, PilihanBeli;
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
        PilihArmor :
        switch (PilihanArmor){
            case 1 : 
            case 2 : 
            case 3 :  
            case 4 :
            case 5 :
            case 6 :
            TampilkanWeapon(Armor, PilihanArmor, Weight);
            scanf("%d", &PilihanBeli);
            PilihBeliArmor :
            switch (PilihanBeli){
                case 1 :    
                MasukkanDataWeapon(player, Armor, Weight, NomorData, PilihanBeli);
                break;
                case 2 : goto PilihArmor;
                break;
                deafult :  
                printf("Pilihan salah ! Silahkan masukkan ulang");
                goto PilihBeliArmor;
                }
            break;
            case 7 :
            break;
            default : printf("Pilihan salah ! Silahkan masukkan ulang");
            goto PilihArmor;
        }
}

void TampilkanArmor(itemsTypes Armor[], int PilihanArmor){
    system("cls");
    printf("Nama Armor  : %s\n", Armor->name);
    printf("Berat Armor : %.0f Kg\n", Armor->weights);
    printf("Harga Armor : %.0f Dollar\n", Armor->price);
    printf("DPS Armor   : %.0f \n", Armor->dps);
    printf("Desc Armor : \n%s \n", Armor->description);
    printf("Apakah Anda ingin membeli Armor ini ? (Yes = 1, No = 2, Back To Menu : 3)\n");
    printf("Masukkan Pilihan Anda : ");
}
void MasukkanDataArmor(itemInventory *player[], itemsTypes Armor[], int Weight, int NomorData, int i){
    int Beban, Harga;
    Harga = Armor[i-1].price;
    Beban = Armor[i-1].weights;
    *player[NomorData]->items = Armor[i-1];
    player[NomorData]->carryLoad += Beban;
    player[NomorData]->money -= Harga;
    player[NomorData]->numberOfItems++;
}


int MainSHOP(itemInventory *player[], itemsTypes Weapon[], itemsTypes Armor[], int JumlahW, int JumlahA, int Weight){
    int PilihanArmorWeapon, NomorData = 0;
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
            PilihWeapon(player, JumlahW, Weapon, Weight, NomorData);
            break;
        case 2:
            MilihArmor :
            PilihArmor(player, JumlahA, Armor, Weight, NomorData);
            break;
        case 3:
            break;
    }
}
