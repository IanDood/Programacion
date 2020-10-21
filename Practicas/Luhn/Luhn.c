#include "stdio.h"
#include "Luhn.h"

void main ( void )
{
	/*Card Digits*/
	uint8 au8CardNumber[16] = {6,9,1,7,8,6,7,8,9,2,1,2,3,4,6,5};

	/*Card Information*/
	printf("\nAccount Digit (15 Numbers): ");
	for ( int i = 0; i < ACCOUNT_NUMBER; i++)
	{
		printf("%d ", au8CardNumber[i]);
	}
	printf("\nValidation Number (Last): %d\n", au8CardNumber[15]);
	printf("Card Digits (Complete): ");
	for ( int i = 0; i < CARD_SIZE; i++)
	{
		printf("%d ", au8CardNumber[i]);
	}

	/*Checking for Card Validation*/
	uint8 u8Check = u8LuhnCheck(&au8CardNumber[0]);
	if( u8Check == 0 )
	{
		printf("\nCARD NUMBER (PAN) VALID\n");
	}
	else
	{
		printf("\nCARD NUMBER (PAN) INVALID\n");
	}
}

uint8 u8LuhnCheck ( uint8 *pu8Data )
{
	uint8 u8Check = 0;
	uint16 u16OddSum = 0;
	uint16 u16EvenSum = 0;
	uint16 u16TotalSum = 0;
	uint16 u16TotalSum1 = 0;
	uint8 u8CardSize = CARD_SIZE;
	uint8 *pu8Validation = pu8Data;

	while ( u8CardSize != 0 )
	{
		pu8Validation = pu8Data;

		if ( u8CardSize % 2 == 0 )
		{
			u16EvenSum += *pu8Validation; 
		}
		else
		{
			*pu8Validation = *pu8Validation * 2;

			if ( *pu8Validation < NUMBER_TRESHOLD )
			{
				/*Nothing to do*/
			}
			else
			{
				*pu8Validation = ( *pu8Validation % 10 ) + 1;
			}
			u16OddSum += *pu8Validation; 
		}
		u16TotalSum = u16OddSum + u16EvenSum;

		pu8Data++;
		u8CardSize--;
	}

	/*Checking Operations*/
	
	printf("\n\nEven Sum Total: %d\n", u16EvenSum);
	printf("Odd Sum Total: %d\n", u16OddSum);
	printf("Total of Sum: %d\n", u16TotalSum);
	
	u8Check = u16TotalSum % 10;

	return u8Check;
}