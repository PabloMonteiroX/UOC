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

#define MAX_LEN 16
#define ROWS 3
#define COLS 3
#define STOCK_OUT 0
#define ZONE_WARNING 15
#define LOW_INVENTORY 100

typedef enum {OPERATIONAL, OUT, WARNING, LOW,} tState;

int main(void) {
/* ------------------------- Variable declarations -------------------------- */
    tState state;
    FILE   *file;
    char   fname[MAX_LEN];
    int    stk[ROWS][COLS];
    int    row0;
    int    row1;
    int    row2;
    int    total;
/* ----------------------------- Input section ------------------------------ */
    printf("INPUT\n");
    printf("FILENAME?\n");
    scanf("%15s", fname);
    file = fopen(fname, "r");
    fscanf(file, "%d %d %d", &stk[0][0], &stk[0][1], &stk[0][2]);
    fscanf(file, "%d %d %d", &stk[1][0], &stk[1][1], &stk[1][2]);
    fscanf(file, "%d %d %d", &stk[2][0], &stk[2][1], &stk[2][2]);
    fclose(file);
/* --------------------------- Processing section --------------------------- */
    row0  = 0;
    row1  = 0;
    row2  = 0;
    total = 0;
    state = OPERATIONAL;
    row0  = stk[0][0] + stk[0][1] + stk[0][2];
    row1  = stk[1][0] + stk[1][1] + stk[1][2];
    row2  = stk[2][0] + stk[2][1] + stk[2][2];
    total = row0 + row1 + row2;

    if (stk[0][0] == STOCK_OUT ||
        stk[0][1] == STOCK_OUT ||
        stk[0][2] == STOCK_OUT ||
        stk[1][0] == STOCK_OUT ||
        stk[1][1] == STOCK_OUT ||
        stk[1][2] == STOCK_OUT ||
        stk[2][0] == STOCK_OUT ||
        stk[2][1] == STOCK_OUT ||
        stk[2][2] == STOCK_OUT) {

        state = OUT;

    } else if (row0 < ZONE_WARNING ||
               row1 < ZONE_WARNING ||
               row2 < ZONE_WARNING) {

        state = WARNING;

    } else if (total < LOW_INVENTORY) {

        state = LOW;

    } else {

        state = OPERATIONAL;
    }
/* ----------------------------- Output section ----------------------------- */
    printf("OUTPUT\n");

    switch (state) {

        case OUT:
            printf("STOCK OUT\n");
            break;

        case WARNING:
            printf("ZONE WARNING\n");
            break;

        case LOW:
            printf("LOW INVENTORY\n");
            break;

        default:
            printf("OPERATIONAL\n");
    }
    return 0;
}
