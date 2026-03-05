/* ************************************************************************** */
/*                                                                            */
/*    UUU   UUU    OOOOO      CCCCC             Ingeniería Informática        */
/*    UUU   UUU   OOOOOOO    CCCCCCC            Fundamentos de Programación   */
/*    UUU   UUU  OOO   OOO  CCC                 PEC2 - 20252                  */
/*    UUU   UUU  OOO   OOO  CCC                                               */
/*    UUU   UUU  OOO   OOO  CCC                 File: main.c                  */
/*     UUU UUU    OOOOOOO    CCCCCCC            Author: Pablo Monteiro        */
/*      UUUUU      OOOOO      CCCCC             Created: 2026/03/05           */
/*                                                                            */
/* ************************************************************************** */

/*Description: Determines whether the irrigation system must be activated
based on soil humidity, plant type and outdoor temperature.*/

#include <stdio.h>
#include <stdbool.h>

#define EMERGENCY_HUMIDITY 10
#define SUCCULENT_HUMIDITY 20
#define SHRUB_HUMIDITY 40
#define TROPICAL_HUMIDITY 60
#define HEAT_TEMPERATURE 35
#define HEAT_HUMIDITY 50

#define SUCCULENT 0
#define SHRUB 1
#define TROPICAL 2

bool	activateIrrigation(float humidity, int plantType, float temperature);

int main(void)
{
	float humidity = 0.0F;
	int plantType = 0;
	float temperature = 0.0F;
	bool activate = false;

	printf("INPUT\n");

	printf("HUMIDITY PERCENTAGE?\n");
	scanf("%f", &humidity);

	printf("PLANT TYPE (0-SUCCULENT, 1-SHRUB, 2-TROPICAL)?\n");
	scanf("%d", &plantType);

	printf("OUTDOOR TEMPERATURE?\n");
	scanf("%f", &temperature);

	activate = activateIrrigation(humidity, plantType, temperature);

	printf("OUTPUT\n");
	printf("ACTIVATING IRRIGATION (0-FALSE, 1-TRUE): %d\n", activate);

	return 0;
}

bool	activateIrrigation(float humidity, int plantType, float temperature)
{
	return	(humidity < EMERGENCY_HUMIDITY) ||
			(plantType == SUCCULENT && humidity < SUCCULENT_HUMIDITY) ||
			(plantType == SHRUB && humidity < SHRUB_HUMIDITY) ||
			(plantType == TROPICAL && humidity < TROPICAL_HUMIDITY) ||
			(temperature > HEAT_TEMPERATURE && humidity < HEAT_HUMIDITY);
}
