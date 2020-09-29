#include "stdio.h"

typedef unsigned long uint32;

void main( void )
{
	uint32 u32BitsValue = 0;
	uint32 u32VarOperation = 0;
	uint32 u32CorrVariable = 0;
	uint32 u32AnsVariable = 0;

	printf("De cuantos Bits es la variable elegida: ");
	scanf("%d", &u32BitsValue);

	if ( u32BitsValue == 8 || u32BitsValue == 16 || u32BitsValue == 32 )
	{
		while ( 1 )
		{
			printf("1.- Operacion AND.\n");
			printf("2.- Operacion  OR.\n");
			printf("3.- Operacion XOR.\n");
			printf("Seleccionar la operacion que se desee: ");
			scanf("%d", &u32VarOperation);

			if ( u32VarOperation < 1 || u32VarOperation > 3 )
			{
				printf("Error: La operacion debe estar en el campo de opciones mostradas.\n");
			}
			else
			{
				printf("Corrimiento de la operacion deseado: ");
				scanf("%d", &u32CorrVariable);

				if ( u32CorrVariable < u32BitsValue)
				{
					if ( u32VarOperation == 1 )
					{
						u32AnsVariable &= ~( 1 << u32CorrVariable );
					}
					else if ( u32VarOperation == 2 )
					{
						u32AnsVariable |= ( 1 << u32CorrVariable );
					}
					else
					{
						u32AnsVariable ^= ( 1 << u32CorrVariable );
					}

					printf("Valor de la Variable: %d", u32AnsVariable);
				}
				else
				{
					printf("Error: El corrimiento deseado es mayor a los Bits seleccionados.\n");
				}
			}
		}
	}
	else
	{
		printf("Error: El tamaño de la variable deseada debe de ser entre 8, 16 y 32.\n");
	}
}