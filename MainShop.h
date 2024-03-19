#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "struct.h"

void MasukkanDataWeapon(itemInventory *player, itemsTypes Weapon[], int i) {
    // Assuming player[NomorData] is a valid pointer to an itemInventory and
    // itemsTypes Weapon[] is an array of weapon structs.
    int Beban, Harga;
    float dps;
    Harga = Weapon[i-1].price;
    Beban = Weapon[i-1].weights;
    dps = Weapon[i-1].dps;
    player->items = (itemsTypes*)realloc(player->items, (player->numberOfItems + 1) * sizeof(itemsTypes));
    strcpy(player->items[player->numberOfItems].name, Weapon[i-1].name);
    strcpy(player->items[player->numberOfItems].description, Weapon[i-1].description);
    player->items[player->numberOfItems].dps = Weapon[i-1].dps; 
    player->items[player->numberOfItems].durability = Weapon[i-1].durability;
    player->items[player->numberOfItems].Kode = Weapon[i-1].Kode;
    player->items[player->numberOfItems].price = Weapon[i-1].price;
    player->items[player->numberOfItems].weights= Weapon[i-1].weights;
    player->carryLoad += Beban;
    player->money -= Harga;
    player->numberOfItems++;
}

void TampilkanWeapon(itemsTypes Weapon[], int PilihanWeapon){
    system("cls");
    printf("Nama Weapon  : %s\n", Weapon[PilihanWeapon-1].name);
    printf("Berat Weapon : %.0f Kg\n", Weapon[PilihanWeapon-1].weights);
    printf("Harga Weapon : %.0f Dollar\n", Weapon[PilihanWeapon-1].price);
    printf("DPS Weapon   : %.0f \n", Weapon[PilihanWeapon-1].dps);
    printf("Desc Weapon : \n%s \n", Weapon[PilihanWeapon-1].description);
    printf("Apakah Anda ingin membeli Weapon ini ? (Yes = 1, No = 2)\n");
    printf("Masukkan Pilihan Anda : ");
}

void PilihWeapon(itemInventory *player, int JumlahW, itemsTypes Weapon[]){
    int i, PilihanWeapon, PilihanBeli;
    PilihWeapon :
    system("cls");
    PilihanWeapon = 0;
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
        switch (PilihanWeapon){
            case 1 : 
            case 2 : 
            case 3 :  
            case 4 :
            case 5 :
            case 6 :
            TampilkanWeapon(Weapon, PilihanWeapon);
            scanf("%d", &PilihanBeli);
            PilihBeli :
            switch (PilihanBeli){
                case 1 :
                printf("nigga");   
                MasukkanDataWeapon(player, Weapon, PilihanWeapon);
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

void TampilkanArmor(itemsTypes Armor[], int PilihanArmor){
    system("cls");
    printf("Nama Armor  : %s\n", Armor[PilihanArmor-1].name);
    printf("Berat Armor : %.0f Kg\n", Armor[PilihanArmor-1].weights);
    printf("Harga Armor : %.0f Dollar\n", Armor[PilihanArmor-1].price);
    printf("DPS Armor   : %.0f \n", Armor[PilihanArmor-1].dps);
    printf("Desc Armor : \n%s \n", Armor[PilihanArmor-1].description);
    printf("Apakah Anda ingin membeli Armor ini ? (Yes = 1, No = 2, Back To Menu : 3)\n");
    printf("Masukkan Pilihan Anda : ");
}
void MasukkanDataArmor(itemInventory *player, itemsTypes Armor[], int i){
    int Beban, Harga;
    Harga = Armor[i-1].price;
    Beban = Armor[i-1].weights;
    strcpy(Armor[i-1].name, player->items[player->numberOfItems].name);
    strcpy(Armor[i-1].description, player->items[player->numberOfItems].description);
    player->items[player->numberOfItems].dps = Armor[i-1].dps; 
    player->items[player->numberOfItems].durability = Armor[i-1].durability;
    player->items[player->numberOfItems].Kode = Armor[i-1].Kode;
    player->items[player->numberOfItems].price = Armor[i-1].price;
    player->items[player->numberOfItems].weights= Armor[i-1].weights;
}

void PilihArmor(itemInventory *player, int JumlahA, itemsTypes Armor[]){
    int i, PilihanArmor, PilihanBeli;
    PilihArmor :
    PilihanArmor = 0;
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
        switch (PilihanArmor){
            case 1 : 
            case 2 : 
            case 3 :  
            case 4 :
            case 5 :
            case 6 :
            TampilkanWeapon(Armor, PilihanArmor);
            scanf("%d", &PilihanBeli);
            PilihBeliArmor :
            switch (PilihanBeli){
                case 1 :    
                MasukkanDataWeapon(player, Armor, PilihanArmor);
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

int MainSHOP(itemInventory *player, itemsTypes Data[], int JumlahData){
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
            PilihWeapon(player, JumlahData, Data);
            break;
        case 2:
            MilihArmor :
            PilihArmor(player, JumlahData, Data);
            break;
        case 3:
            break;
    }
}
