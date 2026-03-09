/* ************************************************************************** */
/*                                                                            */
/*    UUU   UUU    OOOOO      CCCCC             Ingeniería Informática        */
/*    UUU   UUU   OOOOOOO    CCCCCCC            Fundamentos de Programación   */
/*    UUU   UUU  OOO   OOO  CCC                 PEC1 - 20252                  */
/*    UUU   UUU  OOO   OOO  CCC                                               */
/*    UUU   UUU  OOO   OOO  CCC                 File: main.c                  */
/*     UUU UUU    OOOOOOO    CCCCCCC            Author: Pablo Monteiro        */
/*      UUUUU      OOOOO      CCCCC             Created: 2026/02/26           */
/*                                                                            */
/* ************************************************************************** */

/* Description: C program that calculates the Kinetic Energy (KE) of a moving
 object using the formula KE = 1/2 · m · v². */

/* Standard input/output library */
#include <stdio.h>

/* Factor 1/2 used in KE */
#define HALF 0.5F

int main(void)
{
	/* Definition of variables */
	float energy;
	float mass;
	float velocity;

	/* Initialization of variables */
	energy = 0.0F;
	mass = 0.0F;
	velocity = 0.0F;

	/* Input data */
	printf("INPUT\n");

	printf("MASS?\n");
	scanf("%f", &mass);

	printf("VELOCITY?\n");
	scanf("%f", &velocity);

	/* Process data */
	energy = HALF * mass * velocity * velocity;

	/* Output data */
	printf("OUTPUT\n");
	printf("KINETIC ENERGY: %.2f\n", energy);

	/* End of program */
	return 0;
}
