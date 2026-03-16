/* ************************************************************************** */
/*                                                                            */
/*    UUU   UUU    OOOOO      CCCCC             Ingeniería Informática        */
/*    UUU   UUU   OOOOOOO    CCCCCCC            Fundamentos de Programación   */
/*    UUU   UUU  OOO   OOO  CCC                 PEC3 - 20252                  */
/*    UUU   UUU  OOO   OOO  CCC                                               */
/*    UUU   UUU  OOO   OOO  CCC                 File: main.c                  */
/*     UUU UUU    OOOOOOO    CCCCCCC            Author: Pablo Monteiro        */
/*      UUUUU      OOOOO      CCCCC             Created: 2026/03/12           */
/*                                                                            */
/* ************************************************************************** */

/* Description: This program reads stock data from a file, stores it in a
matrix, and processes the information to display the results. */

#include <stdio.h>

#define MAX_LEN (15 + 1)
#define ROWS 3
#define COLS 3
#define STOCK_OUT 0
#define ZONE_WARNING 15
#define LOW_INVENTORY 100

typedef enum {TSTOCK_OUT, TZONE_WARNING, TLOW_INVENTORY, TOPERATIONAL} tState;

int main(void) {
/* ------------------------- Variable declarations -------------------------- */
    tState state;
    FILE   *file;
    char   filename[MAX_LEN];
    int    stock[ROWS][COLS];
    int    zone0Total;
    int    zone1Total;
    int    zone2Total;
    int    total;
/* ----------------------------- Input section ------------------------------ */
    printf("INPUT\n");
    printf("FILENAME?\n");
    scanf("%15s", filename);

    file = fopen(filename, "r");
    fscanf(file, "%d %d %d", &stock[0][0], &stock[0][1], &stock[0][2]);
    fscanf(file, "%d %d %d", &stock[1][0], &stock[1][1], &stock[1][2]);
    fscanf(file, "%d %d %d", &stock[2][0], &stock[2][1], &stock[2][2]);
    fclose(file);
/* --------------------------- Processing section --------------------------- */
    /* calculate total rows */
    zone0Total = stock[0][0] + stock[0][1] + stock[0][2];
    zone1Total = stock[1][0] + stock[1][1] + stock[1][2];
    zone2Total = stock[2][0] + stock[2][1] + stock[2][2];
    /* calculate total matrix */
    total = zone0Total + zone1Total + zone2Total;

    if (stock[0][0] == STOCK_OUT ||
        stock[0][1] == STOCK_OUT ||
        stock[0][2] == STOCK_OUT ||
        stock[1][0] == STOCK_OUT ||
        stock[1][1] == STOCK_OUT ||
        stock[1][2] == STOCK_OUT ||
        stock[2][0] == STOCK_OUT ||
        stock[2][1] == STOCK_OUT ||
        stock[2][2] == STOCK_OUT) {

        state = TSTOCK_OUT;

    } else if (zone0Total < ZONE_WARNING ||
               zone1Total < ZONE_WARNING ||
               zone2Total < ZONE_WARNING) {

        state = TZONE_WARNING;

    } else if (total < LOW_INVENTORY) {

        state = TLOW_INVENTORY;

    } else {

        state = TOPERATIONAL;
    }
/* ----------------------------- Output section ----------------------------- */
    printf("OUTPUT\n");

    switch (state) {

        case TSTOCK_OUT:
            printf("STOCK OUT\n");
            break;

        case TZONE_WARNING:
            printf("ZONE WARNING\n");
            break;

        case TLOW_INVENTORY:
            printf("LOW INVENTORY\n");
            break;

        default:
            printf("OPERATIONAL\n");
    }
    return 0;
}
