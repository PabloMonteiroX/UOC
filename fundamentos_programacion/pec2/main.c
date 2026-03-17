#include <stdio.h> /* Standard input/output library */
#include <stdbool.h> /* Standard boolean type library */

/* Humidity thresholds */
#define EMERGENCY_HUMIDITY 10
#define SUCCULENT_HUMIDITY 20
#define SHRUB_HUMIDITY 40
#define TROPICAL_HUMIDITY 60
/* Heat condition thresholds */
#define HEAT_TEMPERATURE 35
#define HEAT_HUMIDITY 50
/* Plant types */
typedef enum {SUCCULENT, SHRUB, TROPICAL} tPlantType;

int main(void)
{
    /* Variable declarations */
    float humidity;
    tPlantType plantType;
    float temperature;
    bool  activate;

    /* Input section */
    printf("INPUT\n");
    printf("HUMIDITY PERCENTAGE?\n");
    scanf("%f", &humidity);

    printf("PLANT TYPE (0-SUCCULENT, 1-SHRUB, 2-TROPICAL)?\n");
    scanf("%u", &plantType);

    printf("OUTDOOR TEMPERATURE?\n");
    scanf("%f", &temperature);

    /* Processing section */
    activate = (humidity < EMERGENCY_HUMIDITY)
            || (plantType == SUCCULENT && humidity < SUCCULENT_HUMIDITY)
            || (plantType == SHRUB     && humidity < SHRUB_HUMIDITY)
            || (plantType == TROPICAL  && humidity < TROPICAL_HUMIDITY)
            || (temperature > HEAT_TEMPERATURE && humidity < HEAT_HUMIDITY);

    /* Output section */
    printf("OUTPUT\n");
    printf("ACTIVATING IRRIGATION (0-FALSE, 1-TRUE): %d\n", activate);

    return 0;
}
