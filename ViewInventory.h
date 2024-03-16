#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void viewInventory(struct itemInventory player) {
    printf("Jumlah uang yang dimiliki : %.2f\n", player->money);
    printf("Carry weight tersisa: %.2f\n", player.carryLoad);

    if(player.numberOfItems == 0) {
        printf("Anda Saat Ini Tidak Punya Item!");
        return;
    }

    for(int i = 0; i < player.numberOfItems; i++) {

        if(strcpy(player.items[i].type, "Weapon") ) {
            printf("%s %s %.2f %.2f %s", player.items[i].name, player.items[i].type, player.items[i].dps, player.items[i].description);
        }

        else if(strcpy(player.items[i].type, "Armor")) {
            printf("%s %s %.2f %.2f %s", player.items[i].name, player.items[i].type, player.items[i].durability, player.items[i].description);
        }

        else {
            printf("%s %s %.2f %.2f %s", player.items[i].name, player.items[i].type, player.items[i].effectDuration, player.items[i].description);
        }
    }
}