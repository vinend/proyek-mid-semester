// PROGRAM MANAGEMENT INVENTORY DAN SHOP DALAM GAME RPG
// VERSI 1.5

// Anggota :
// 1. Andi Muhammad Alvin Farhansyah - 2306161933
// 2. Alexander Christhian - 2306267025

// Pendeklarasian Library Yang Dipakai di dalam program ini
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// Pendeklarasian file-file header untuk fungsi program dan juga struct pada program
#include "MainShop.h"
#include "IsiMainShop.h"
#include "struct.h"
#include "ViewInventory.h"

// Main Function Mulai
int main() {

    // Pendeklarasian semua hal yang perlu dideklarasikan di awal, seperti trigger, player, list weapon, dan list armor
    int trigger = 0, pilihan, jumlahItem = 0, JumlahW = 0, JumlahA = 0, i, Weight = 0;
    itemInventory *player = (itemInventory*)malloc(sizeof(itemInventory));
    itemsTypes *Weapon =(itemsTypes*)malloc(sizeof(itemsTypes));
    itemsTypes *Armor =(itemsTypes*)malloc(sizeof(itemsTypes));
    player->items = NULL;
    player->numberOfItems = 0;    
    
    // Pemasukkan Jumlah Uang yang bisa di spend dalam program ini
    printf("Masukkan Jumlah Uang Anda : ");
    scanf("%f", &player->money);
    printf("Masukkan Carry Load Player: ");
    scanf("%f", &player->carryLoad);
    system("cls");

    // Pengisian Main Shop, melalui list eksternal via MainShop.txt
    mainIsiShop(&Weapon, &Armor, &JumlahW, &JumlahA);

    // Printing menu di dalam do while dengan trigger yang bisa menutupnya
    do { 
        system("cls");
        printf("\n");
        printf(" +-------------------------------------------------+\n");
        printf(" |         SELAMAT DATANG DI SHOP ITEM LIYUE       |\n");
        printf(" +-------------------------------------------------+\n");
        printf(" | No. |                Description                |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  1  | Shop for Items                            |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  2  | View Inventory                            |\n");
        printf(" +-----+-------------------------------------------+\n");
        printf(" |  3  | Exit Program                              |\n");
        printf(" +-----+-------------------------------------------+\n");

        printf("Masukkan Pilihan: "); scanf("%d", &pilihan);

        switch(pilihan) {
            // Pilihan case 1 dimana main function akan passing semua parameter dari player dan keperluan shop dalam untuk melakukan pembelanjaan dalam mengisi inventory
            case 1 : 
            MainSHOP(player, Weapon, Armor, JumlahW, JumlahA, Weight);
            break;

            // Pilihan case 2 dimana main function akan passing parameter untuk player dalam melihat, sorting, ataupun searching inventory player
            case 2 : 
            viewInventory(player); getch();
            break;

            // Pilihan case 3 dimana trigger akan ditambah satu sehingga mengakhiri loop main dan mengakhiri program
            case 3 :
                system("cls");
                printf("Terima Kasih! Press any button to continue!");
                getch();
                trigger++;
                break;

            default :
                system("cls"); printf("Input Tidak Benar"); getch();
                break;

        }
    } while(trigger == 0);
    
    // Free semua variabel malloc
    free(player);
    free(Weapon);
    free(Armor);
}
