#include "stdio.h"
#include "GENFUN.h"

void main ( void )
{
	/*Needed extra variables*/
	uint8 au8CaseTesting1[5] = "Akira";
	uint8 au8CaseTesting2[11] = "Higashikata";
	uint8 au8CaseTesting3[12] = "Senjougahara";
	uint8 au8CaseTesting4[13] = "Levi Ackerman";
	uint8 au8CaseTesting5[15] = "Giorno Giovanna";
	uint8 au8ArrayAveraging[3] = {5,10,15};
	uint8 au8ArrayLists[10] = {5,12,16,3,20,59,7,5,1,6};
	uint8 au8Randomizer[255];
	uint8 u8Variable = 0;

	/*Testing CapsOn*/
	printf("\nTesting GENFUN_vCapsOn\n");
	printf("Array Before CapsOn: %s\n", au8CaseTesting1);
	GENFUN_vCapsOn(&au8CaseTesting1[0], 5);
	printf("Array After CapsOn: %s\n", au8CaseTesting1);

	/*Testing CapsOff*/
	printf("\nTesting GENFUN_vCapsOff\n");
	printf("Array Before CapsOff: %s\n", au8CaseTesting1);
	GENFUN_vCapsOff( &au8CaseTesting1[0], 5);
	printf("Array After CapsOff: %s\n", au8CaseTesting1);

	/*Testing GetOcurrence*/
	printf("\nTesting GENFUN_u8GetOccurence\n");
	printf("Array Being Analyzed: %s\n", au8CaseTesting2);
	printf("Target being searched for is: '%c'\n", ASCII_CHARACTER_TARGETED);
	uint8 u8Ocurrence = GENFUN_u8GetOccurence(&au8CaseTesting2[0], ASCII_CHARACTER_TARGETED, 11); 
	printf("Total Repetition of the Target: %d\n", u8Ocurrence);

	/*Testing GetAverage*/
	printf("\nTesting GENFUN_u8GetAverage\n");
	printf("Array Being Averaged: ");
	for ( u8Variable = 0; u8Variable < NUMBERS_BEING_AVERAGED; u8Variable++ )
	{
		printf("%d ", au8ArrayAveraging[u8Variable]);
	}
	uint8 u8Averaged = GENFUN_u8GetAverage(&au8ArrayAveraging[0], 3);
	printf("\nAverage of Array Obtained: %d\n", u8Averaged);

	/*Testing MemSet*/
	printf("\nTesting GENFUN_u8MemSet\n");
	printf("Array Before MemSet: %s\n", au8CaseTesting3);
	printf("Character being used for MemSet: '%c'\n", ASCII_CHARACTER_OVERWRITE);
	GENFUN_u8MemSet(&au8CaseTesting3[0], ASCII_CHARACTER_OVERWRITE, 12);
	printf("Array After MemSet: %s\n", au8CaseTesting3);

	/*Testing MemCopy*/
	printf("\nTesting GENFUN_u8MemCopy\n");
	printf("First Array Before MemCopy: %s\n", au8CaseTesting4);
	printf("Second Array Before MemCopy: %s\n", au8CaseTesting5);
	GENFUN_u8MemCopy(&au8CaseTesting4[0], &au8CaseTesting5[0], 15);
	printf("First Array After MemCopy: %s\n", au8CaseTesting4);
	printf("First Array After MemCopy: %s\n", au8CaseTesting5);

	/*Testing SortList*/
	printf("\nTesting GENFUN_vSortList\n");
	printf("Array Before SortList: ");
	for ( u8Variable = 0; u8Variable < LIST_TOTAL; u8Variable++ )
	{
		printf("%d ", au8ArrayLists[u8Variable]);
	}
	GENFUN_vSortList(&au8ArrayLists, &au8ArrayLists, 10);
	printf("\nArray After SortList: ");
	for ( u8Variable = 0; u8Variable < LIST_TOTAL; u8Variable++ )
	{
		printf("%d ", au8ArrayLists[u8Variable]);
	}

	/*Testing SoftSignal*/
	printf("\n\nTesting GENFUN_vSoftSignal\n");
	printf("\nSignal Being Softenend:\n");
	srand(time(0));
	for ( u8Variable = 0; u8Variable < VARIABLE_CHAR_HIGH_TRESHOLD - 1; u8Variable++ )
	{   
    	au8Randomizer[u8Variable] = rand() % VARIABLE_CHAR_HIGH_TRESHOLD;
	}
	for ( u8Variable = 0; u8Variable < VARIABLE_CHAR_HIGH_TRESHOLD - 1; u8Variable++ )
	{
		printf("%d ", au8Randomizer[u8Variable]);
	}
	GENFUN_vSoftSignal(&au8Randomizer, &au8Randomizer);
	printf("\n\nSoftened Signal:\n");
	for ( u8Variable = 0; u8Variable < VARIABLE_CHAR_HIGH_TRESHOLD - 1; u8Variable++ )
	{
		printf("%d ", au8Randomizer[u8Variable]);
	}

	/*Testing Filter Signal*/
	printf("\n\nTesting GENFUN_vFilterSignal\n");
    printf("\nSignal Being Filtered from %d to %d:\n", LOW_TRESHOLD_SIGNALS, HIGH_TRESHOLD_SIGNALS);
    for ( u8Variable = 0; u8Variable < VARIABLE_CHAR_HIGH_TRESHOLD - 1; u8Variable++ )
    {
        au8Randomizer[u8Variable] = rand() % VARIABLE_CHAR_HIGH_TRESHOLD;
    }
    for ( u8Variable = 0; u8Variable < VARIABLE_CHAR_HIGH_TRESHOLD - 1 ; u8Variable++ )
    {
        printf("%d ", au8Randomizer[u8Variable]);
    }
    GENFUN_vFilterSignal(&au8Randomizer, &au8Randomizer, HIGH_TRESHOLD_SIGNALS , LOW_TRESHOLD_SIGNALS);
    printf("\n\nFiltered Signal:\n");
    for ( u8Variable = 0; u8Variable < VARIABLE_CHAR_HIGH_TRESHOLD - 1; u8Variable++ )
    {
        printf("%d ", au8Randomizer[u8Variable]);
    }
}

void GENFUN_vCapsOn ( uint8 *pu8Src, uint8 u8SizeOfList )
{
	while ( u8SizeOfList != 0 )
	{
		if ( *pu8Src > ASCII_LOW_TRESHOLD_OFF_ON && *pu8Src < ASCII_HIGH_TRESHOLD_OFF_ON )
		{
			*pu8Src -= ASCII_CONVERTION_FACTOR;
		}
		else
		{
			/*Nothing to do*/
		}
		pu8Src++;
		u8SizeOfList--;
	}
}

void GENFUN_vCapsOff ( uint8 *pu8Src, uint8 u8SizeOfList )
{
	while ( u8SizeOfList != 0 )
	{
		if ( *pu8Src > ASCII_LOW_TRESHOLD_ON_OFF && *pu8Src < ASCII_HIGH_TRESHOLD_ON_OFF )
		{
			*pu8Src += ASCII_CONVERTION_FACTOR;
		}
		else
		{
			/*Nothing to do*/
		}
		pu8Src++;
		u8SizeOfList--;
	}
}

uint8 GENFUN_u8GetOccurence ( uint8 *pu8Src, uint8 u8Target, uint8 u8SizeOfList )
{
	uint8 u8TargetOcurrence = 0;

	while ( u8SizeOfList != 0 )
	{
		if ( *pu8Src == u8Target )
		{
			u8TargetOcurrence++;
		}
		else
		{
			/*Nothing to do*/
		}
		pu8Src++;
		u8SizeOfList--;
	}

	return u8TargetOcurrence;
}

uint8 GENFUN_u8GetAverage ( uint8 *pu8Src, uint8 u8SizeOfList )
{
	uint8 u8ArraySum = 0;
	uint8 u8AverageResult = 0;
	uint8 u8First = 0;

	for ( u8First = 0; u8First < u8SizeOfList; u8First++ )
	{
		u8ArraySum += pu8Src[u8First];
	}

	u8AverageResult = u8ArraySum / u8SizeOfList;

	return u8AverageResult;
}

void GENFUN_u8MemSet ( uint8 *pu8Src, uint8 u8Char2Set, uint8 u8SizeOfList )
{
    uint8 *pu8Destination = pu8Src;

    while ( u8SizeOfList -- > 0 )
    {
        *pu8Destination++ = u8Char2Set;
    }
}

void GENFUN_u8MemCopy ( uint8 *pu8Src, uint8 *pu8Dest, uint8 u8SizeOfList )
{
	uint8 u8First = 0;

	for ( u8First = 0; u8First < u8SizeOfList; u8First++ )
    {
        pu8Src[u8First] = pu8Dest[u8First];
    } 
}

void GENFUN_vSortList ( uint8 *pu8Src, uint8 *pu8Dest, uint8 u8SizeOfList )
{
	uint8 u8ListVar = 0;
	uint8 u8First = 0;
	uint8 u8Second = 0;

    for ( u8First = 0; u8First < u8SizeOfList; u8First++ ) 
    {
        for ( u8Second = u8First + 1; u8Second < u8SizeOfList; u8Second++ )
        {
            if ( pu8Src[u8First] > pu8Src[u8Second] ) 
            {
                u8ListVar =  pu8Src[u8First];
                pu8Src[u8First] = pu8Src[u8Second];
                pu8Src[u8Second] = u8ListVar;
            }
            else
			{
				/*Nothing to do*/
			}
        }
    }
}

void GENFUN_vSoftSignal ( uint8 *pu8Src, uint8 *pu8Dest )
{
	for ( int i = 0; i < VARIABLE_CHAR_HIGH_TRESHOLD; i++ )
	{
		pu8Dest[i] = ( pu8Src[i] + pu8Src[i + 1]) / 2;
	}
}

void GENFUN_vFilterSignal ( uint8 *pu8Src, uint8 *pu8Dest, uint8 u8MaxVal, uint8 u8MinVal )
{
	for ( int i = 0; i < VARIABLE_CHAR_HIGH_TRESHOLD; i++ ) 
	{
		for ( int j = i + 1; j < VARIABLE_CHAR_HIGH_TRESHOLD; j++ )
		{
			if ( pu8Src[i] > HIGH_TRESHOLD_SIGNALS )  
			{
				pu8Src[i] = HIGH_TRESHOLD_SIGNALS;
			}
			else
			{
				/*Nothing to do*/
			}
		}
	}
}