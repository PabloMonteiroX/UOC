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

/*Description: C program that calculates the Kinetic Energy (KE) of a moving
 object using the formula KE = 1/2 · m · v².*/

#include <stdio.h>

#define HALF 0.5F

float ft_kinetic_energy(float mass, float velocity);

int main(void)
{
    float energy = 0.0F;
    float mass = 0.0F;
    float velocity = 0.0F;
    
    printf("INPUT\n");
    
    printf("MASS?\n");
    scanf("%f", &mass);
    
    printf("VELOCITY?\n");
    scanf("%f", &velocity);
    
    energy = ft_kinetic_energy(mass, velocity);
    
	printf("OUTPUT\n");
    printf("KINETIC ENERGY: %.2f\n", energy);
    
	return 0;
}

float ft_kinetic_energy(float mass, float velocity) //KE = 1/2 · m · v²
{
    return (HALF * mass * velocity * velocity);
}