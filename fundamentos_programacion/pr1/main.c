/* ************************************************************************** */
/*                                                                            */
/*    UUU   UUU    OOOOO      CCCCC             Ingeniería Informática        */
/*    UUU   UUU   OOOOOOO    CCCCCCC            Fundamentos de Programación   */
/*    UUU   UUU  OOO   OOO  CCC                 PR1 - 20252                  */
/*    UUU   UUU  OOO   OOO  CCC                                               */
/*    UUU   UUU  OOO   OOO  CCC                 File: main.c                  */
/*     UUU UUU    OOOOOOO    CCCCCCC            Author: Pablo Monteiro        */
/*      UUUUU      OOOOO      CCCCC             Created: 2026/03/19           */
/*                                                                            */
/* ************************************************************************** */

/* This program performs a statistical analysis of power consumption from a
   Smart Grid system. It reads electrical readings and tariff codes from a text
   file, validates the data (discarding negativevalues), and calculates total
   consumption, averages, and peaks. */

#include <stdio.h>

#define ROUNDING_OFFSET 0.5
#define DECIMAL_FACTOR 100
#define MAX_READINGS 100
#define MAX_LEN 16

typedef enum {VALLEY, FLAT, PEAK} tTariffType;

int main(void) {
/* --------------------------- Variable declaration ------------------------- */
    double          invalidValues[MAX_READINGS];
    tTariffType     tariffData[MAX_READINGS];
    double          powerData[MAX_READINGS];
    int             invalidReadingsCount;
    int             validReadingsCount;
    char            filename[MAX_LEN];
    double          totalConsumption;
    int             tempTariffCode;
    int             totalElements;
    double          averagePower;
    double          tempAverage;
    FILE            *fileToRead;
    int             countValley;
    tTariffType     maxTariff;
    int             countFlat;
    int             countPeak;
    double          maxPower;
    int             i;
/* ---------------------------- Initialization ------------------------------ */
    maxTariff            = VALLEY;
    maxPower             = -1.0;
    totalConsumption     = 0.0;
    averagePower         = 0.0;
    tempAverage          = 0.0;
    totalElements        = 0;
    validReadingsCount   = 0;
    invalidReadingsCount = 0;
    countValley          = 0;
    countFlat            = 0;
    countPeak            = 0;
/* ----------------------------- Input section ------------------------------ */
    printf("--- Smart Grid Analysis System (PR1) ---\n");
    printf("LOAD DATA FROM FILE. ENTER FILE NAME >> ");

    scanf("%15s", filename);
    fileToRead = fopen(filename, "r");
    if (fileToRead == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        return 0;
    }
    fscanf(fileToRead, "%d", &totalElements);

    if (totalElements > MAX_READINGS) {

        totalElements = MAX_READINGS;
    }
    for (i = 0; i < totalElements; i++) {

        fscanf(fileToRead, "%lf %d", &powerData[i], &tempTariffCode);
        if (tempTariffCode == 1) {
            tariffData[i] = VALLEY;
        } else if (tempTariffCode == 2) {
            tariffData[i] = FLAT;
        } else {
            tariffData[i] = PEAK;
        }
    }
    fclose(fileToRead);
/* --------------------------- Processing section --------------------------- */
    for (i = 0; i < totalElements; i++) {

        if (powerData[i] >= 0) {

            totalConsumption += powerData[i];
            validReadingsCount++;

            if (powerData[i] > maxPower) {
                maxPower = powerData[i];
                maxTariff = tariffData[i];
            }

            if (tariffData[i] == VALLEY) {
                countValley++;
            } else if (tariffData[i] == FLAT) {
                countFlat++;
            } else {
                countPeak++;
            }
        } else {
            invalidValues[invalidReadingsCount] = powerData[i];
            invalidReadingsCount++;
        }
    }
    if (validReadingsCount > 0) {

        tempAverage = totalConsumption / validReadingsCount;
        averagePower = (int)(tempAverage * DECIMAL_FACTOR + ROUNDING_OFFSET) /
                       (double)DECIMAL_FACTOR;
    }
/* ----------------------------- Output section ----------------------------- */
    printf("\nProcessing %d records...\n", totalElements);
    printf("----------------------------------------\n");
    printf("ANALYSIS SUMMARY\n");
    printf("----------------------------------------\n");

    if (validReadingsCount > 0) {

        printf("Total consumption: %.2f kW\n", totalConsumption);
        printf("Average power: %.2f kW\n", averagePower);
        printf("Maximum peak: %.2f kW (Tariff: ", maxPower);

        if (maxTariff == VALLEY) {
            printf("VALLEY");
        } else if (maxTariff == FLAT) {
            printf("FLAT");
        } else {
            printf("PEAK");
        }

        printf(")\n\n");

        printf("Distribution by Tariff:\n");
        printf("- Valley intervals: %d\n", countValley);
        printf("- Flat intervals: %d\n", countFlat);
        printf("- Peak intervals: %d\n\n", countPeak);

        printf("Discarded readings: %d\n", invalidReadingsCount);

        for (i = 0; i < invalidReadingsCount; i++) {
            printf("%.2f kW\n", invalidValues[i]);
        }


    printf("----------------------------------------\n");

    } else {
        printf("No valid data found to perform analysis.\n");
    }
    return 0;
}
