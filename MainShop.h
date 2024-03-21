#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "struct.h"

// Function untuk memasukkan Data Weapon ke Data Player
void MasukkanDataWeapon(itemInventory *player, itemsTypes Weapon[], int *Weight, int *NomorData, int i) {
    int Beban = Weapon[i-1].weights;
    int Harga = Weapon[i-1].price;

    // Error Handling jika beban melebihi atau uang kurang dari barang yang dibeli
    if(*Weight + Beban > player->carryLoad){
        printf("Beban terlalu besar !\n");
        getch();
        return;
    }
    else if(player->money < Weapon[i-1].price){
        printf("Uang tidak cukup !\n");
        getch();
        return;
    }

    // Memasukkan data ke dalam Player
    player->items = (itemsTypes*)realloc(player->items, (player->numberOfItems + 1) * sizeof(itemsTypes));
    player->items[player->numberOfItems] = Weapon[i-1];
    *Weight += Beban;
    player->money -= Harga;
    player->numberOfItems++;
    player->carryLoad -=Beban;
    (*NomorData)++;
}

// Menampilkan Data Weapon
void TampilkanWeapon(itemsTypes Weapon[], int PilihanWeapon, int Weight){
    system("cls");
    printf("Nama Weapon  : %s\n", Weapon[PilihanWeapon-1].name);
    printf("Berat Weapon : %.0f Kg\n", Weapon[PilihanWeapon-1].weights);
    printf("Harga Weapon : %.0f Dollar\n", Weapon[PilihanWeapon-1].price);
    printf("DPS Weapon   : %.0f DPS\n", Weapon[PilihanWeapon-1].dps);
    printf("Desc Weapon  : \n%s \n", Weapon[PilihanWeapon-1].description);
    printf("Apakah Anda ingin membeli Weapon ini ? (Yes = 1, No = 2)\n");
    printf("Masukkan Pilihan Anda : ");
}

// Function untuk memilih Weapon
void PilihWeapon(itemInventory *player, int JumlahW, itemsTypes Weapon[], int *Weight, int *NomorData){
    int PilihanWeapon, PilihanBeli;
    do {
        system("cls");

        // Error Handling jika beban melebihi dari beban maksimum atau uang kurang dari 100
        if(player->carryLoad < 2){
            return;
        }
        else if(player->money < 100){
            return;
        }

        // Print pilihan
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
        printf("Uang sekarang : %.2f\n", player->money);
        printf("Beban yang sisa sekarang : %.2f\n", player->carryLoad);

        // Memilih Pilihan Weapon
        scanf("%d", &PilihanWeapon);
        if(PilihanWeapon >= 1 && PilihanWeapon <= JumlahW) {
            TampilkanWeapon(Weapon, PilihanWeapon, *Weight);
            scanf("%d", &PilihanBeli);
            if(PilihanBeli == 1){
                MasukkanDataWeapon(player, Weapon, Weight, NomorData, PilihanWeapon);
            }
            else if (PilihanBeli == 2){
                break;
            }
            else{
                printf("Pilihan salah ! Silahkan masukkan ulang\n");
                getch();
            }
        } else if(PilihanWeapon == 7) {
            break;
        } else {
            printf("Pilihan salah ! Silahkan masukkan ulang\n");
            getch();
        }
    } while(PilihanWeapon != 7);
}

// Menampilkan Data Armor
void TampilkanArmor(itemsTypes Armor[], int PilihanArmor){
    system("cls");
    printf("Nama Armor  : %s\n", Armor[PilihanArmor-1].name);
    printf("Berat Armor : %.0f Kg\n", Armor[PilihanArmor-1].weights);
    printf("Harga Armor : %.0f Dollar\n", Armor[PilihanArmor-1].price);
    printf("DPS Armor   : %.0f HP\n", Armor[PilihanArmor-1].durability);
    printf("Desc Armor : \n%s \n", Armor[PilihanArmor-1].description);
    printf("Apakah Anda ingin membeli Armor ini ? (Yes = 1, No = 2, Back To Menu : 3)\n");
    printf("Masukkan Pilihan Anda : ");
}

// Function untuk memasukkan Data Armor ke Data Player
void MasukkanDataArmor(itemInventory *player, itemsTypes Armor[], int *Weight, int NomorData, int i){
    int Beban, Harga;
    Harga = Armor[i-1].price;
    Beban = Armor[i-1].weights;

    // Error Handling jika beban melebihi atau uang kurang dari barang yang dibeli
    if(*Weight + Beban > player->carryLoad){
        printf("Beban terlalu besar !\n");
        getch();
        return;
    }
    else if(player->money < Armor[i-1].price){
        printf("Uang tidak cukup !\n");
        getch();
        return;
    }

    // Memasukkan data ke dalam Player
    player->items = (itemsTypes*)realloc(player->items, (player->numberOfItems + 1) * sizeof(itemsTypes));
    player->items[player->numberOfItems] = Armor[i-1];
    *Weight += Beban;
    player->money -= Harga;
    player->numberOfItems++;
    player->carryLoad -=Beban;
    NomorData++;
}

// Function untuk memilih Armor
void PilihArmor(itemInventory *player, int JumlahA, itemsTypes Armor[], int *Weight, int NomorData){
    int PilihanArmor, PilihanBeli;
    do {
        system("cls");

        // Error Handling jika beban melebihi dari beban maksimum atau uang kurang dari 100
        if(player->carryLoad < 2){
            return;
        }
        else if(player->money < 100){
            return;
        }

        // Print pilihan
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
        printf("Uang sekarang : %.2f\n", player->money);
        printf("Beban yang sisa sekarang : %.2f\n", player->carryLoad);

        // Memilih Pilihan Armor
        scanf("%d", &PilihanArmor);
        if(PilihanArmor >= 1 && PilihanArmor <= JumlahA) {
            TampilkanArmor(Armor, PilihanArmor);
            scanf("%d", &PilihanBeli);
            if(PilihanBeli == 1){
                MasukkanDataArmor(player, Armor, Weight, NomorData, PilihanArmor);
            }
            else if (PilihanBeli == 2){
                break;
            }
            else{
                printf("Pilihan salah ! Silahkan masukkan ulang\n");
                getch();
            }
        } else if(PilihanArmor == 6) {
            break;
        } else {
            printf("Pilihan salah ! Silahkan masukkan ulang\n");
            getch();
        }
    } while(PilihanArmor != 6);
}

// Main untuk Header Shop
int MainSHOP(itemInventory *player, itemsTypes Weapon[], itemsTypes Armor[], int JumlahW, int JumlahA, int Weight){
    int PilihanArmorWeapon, NomorData = 0;
    do{
        system("cls");

        // Error Handling jika beban melebihi dari beban maksimum atau uang kurang dari 100
        if(player->carryLoad < 2){
            printf("Beban melebihi maxload !");
            getch();
            break;
        }
        else if(player->money < 100){
            printf("Uang Kurang !");
            getch();
            break;
        }

        // Print pilihan
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

        // Memilih Pilihan Armor atau Weapon
        scanf("%d", &PilihanArmorWeapon); 
        switch (PilihanArmorWeapon) {
        case 1:
            MilihWeapon : 
            PilihWeapon(player, JumlahW, Weapon, &Weight, &NomorData);
            break;
        case 2:
            MilihArmor :
            PilihArmor(player, JumlahA, Armor, &Weight, NomorData);
            break;
        case 3:
            break;
        }
    }while(PilihanArmorWeapon !=3);
}
