#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "Mines.h"

void main ( void )
{
	uint8 au8Mines[MINES_MAP_SIZE][MINES_MAP_SIZE] = {{BASE_VALUE}};
	uint8 u8DifficultySelected = 0;
	uint8 u8MinesRow = 0;
	uint8 u8MinesColumn = 0;
	uint8 u8MinesChecked = 0;
    uint8 u8OptionSelected = 0;
    uint8 u8WinningCondition = 0;
    uint8 u8Bombs = 0;

    while ( u8OptionSelected == 0 )
    {
    	system ( "cls" );
	    printf("\nPress 1 to -> Easy (10 Mines) - Git Gud\n");
	    printf("Press 2 to -> Medium (20 Mines) - A Little Challenge For Whoever Wants To Accept It\n");
	    printf("Press 3 to -> Hard (30 Mines) - The Real Challenge, Are You Really Ready?\n");
	    printf("\nEnter selection: ");
	    scanf("%d", &u8DifficultySelected);

	    if ( u8DifficultySelected == 1 )
	    {
	    	u8Bombs = EASY_MODE;
	    	u8OptionSelected = 1;
	    }
	    else if ( u8DifficultySelected == 2 )
	    {
	    	u8Bombs = MEDIUM_MODE;
	    	u8OptionSelected = 1;
	    }
	    else if ( u8DifficultySelected == 3 )
	    {
	    	u8Bombs = HARD_MODE;
	    	u8OptionSelected = 1;
	    }
	    else
	    {
	    	printf("\nThis option does not exist, choose another one.\n");
	    }
	}

	for(int i = 0; i < 15; i++)
	{
		for(int j = 0; j < 15; j++)
		{
			au8Mines[i][j] = BASE_VALUE;
		}
	}

   	srand(time(NULL));

   	MinesDifficulty( au8Mines, u8DifficultySelected );
   	system ( "cls" );
    ShowMapMines( au8Mines );

   	while ( 1 )
    {
    	printf("\nWhich column will you choose: ");
        scanf("%d", &u8MinesColumn);
    	fflush( stdin );

    	printf("Which row will you choose: ");
        scanf("%d", &u8MinesRow);
        fflush( stdin );

        u8MinesChecked = CheckinMines(au8Mines, u8MinesRow, u8MinesColumn);
        if ( u8MinesChecked == EXPLODE )
        {
            system ( "cls" );
            ShowAllMapMines( au8Mines );
            printf("\nYou have lost, try again.");
            break;
        }
        else
        {
        	u8WinningCondition++;
            au8Mines[u8MinesRow][u8MinesColumn] = u8MinesChecked;
        }

        if ( u8WinningCondition == TOTAL_SPOTS - u8Bombs )
        {
        	system ( "cls" );
        	printf("\nCongratulations, you have won, hope you had a good time!");
        	break;
        }
        else
        {
        	/*Nothing to do*/
        }

        system ( "cls" );
        ShowMapMines( au8Mines );
    }

	printf("\nThanks for playing.\n");
}

void MinesDifficulty(uint8 au8Mines[MINES_MAP_SIZE][MINES_MAP_SIZE], uint8 u8DifficultySelected)
{
    uint8 u8MinesArrangement = 0, u8First = 0, u8Second = 0;

    if ( u8DifficultySelected == 1)
    {
    	u8MinesArrangement = EASY_MODE;
        printf("\nDifficulty Selected: Easy (10 Mines)\n\n");

        while( u8MinesArrangement != 0 )
        {
        	u8First = rand() % 14 + 1 ;
            u8Second = rand() % 14 + 1 ;

            if ( au8Mines[u8First][u8Second] == BASE_VALUE )
            {
                au8Mines[u8First][u8Second] = BOMB_VALUE;
                u8MinesArrangement--;
            }
            else
            {
                /*Nothing to do*/
            }
        } 
    }

    else if ( u8DifficultySelected == 2)
    {
    	u8MinesArrangement = MEDIUM_MODE;
    	printf("\nDifficulty Selected: Medium (20 Mines)\n\n");
    	

        while(u8MinesArrangement != 0)
        {
            u8First = rand() % 14 + 1 ;
            u8Second = rand() % 14 + 1;
            if ( au8Mines[u8First][u8Second] == BASE_VALUE )
            {
                au8Mines[u8First][u8Second] = BOMB_VALUE;
                u8MinesArrangement--;
            }
            else
            {
                /*Nothing to do*/
            }
        }
    }

    else if ( u8DifficultySelected == 3)
    {
    	u8MinesArrangement = HARD_MODE;
    	printf("\nDifficulty Selected: Hard (30 Mines)\n\n");
    	

        while(u8MinesArrangement != 0) 
        {
            u8First = rand() % 14 + 1;
            u8Second = rand() % 14 + 1;
            if ( au8Mines[u8First][u8Second] == BASE_VALUE )
            {
                au8Mines[u8First][u8Second] = BOMB_VALUE;
                u8MinesArrangement--;
            }
            else
            {
                /*Nothing to do*/
            }
        }
    }
    else
    {
    	/*Nothing to do*/
    }
}

void ShowMapMines(uint8 au8Mines[MINES_MAP_SIZE][MINES_MAP_SIZE])
{
	printf("\n");
	for ( int i = 0; i < MINES_MAP_SIZE; i++ )
	{
	  	printf("%d ", i);
	}

	printf("\n");
	printf("\n");

	for ( int i = 0; i < MINES_MAP_SIZE; i++ )
	{
		for ( int j = 0; j < MINES_MAP_SIZE; j++ )
		{
			if ( au8Mines[i][j] == BASE_VALUE )
			{
				printf("%c ", HASHTAG_ASCII_VALUE);
			}
			else if ( au8Mines[i][j] == BOMB_VALUE )
			{
				printf("%c ", HASHTAG_ASCII_VALUE);
			}
			else
			{
				printf("%d ", au8Mines[i][j] );
			}
		}
	    printf("	%d", i);   
		puts("");
	}
}

uint8 CheckinMines(uint8 au8Mines[MINES_MAP_SIZE][MINES_MAP_SIZE], uint8 u8MinesRow, uint8 u8MinesColumn)
{
	uint8 u8Counting = 0;

	if ( au8Mines[u8MinesRow][u8MinesColumn] == BOMB_VALUE )
	{
		return EXPLODE;
	}
	if ( au8Mines[u8MinesRow - 1][u8MinesColumn] == BOMB_VALUE )
	{
		u8Counting++;
	}
	if ( au8Mines[u8MinesRow - 1][u8MinesColumn + 1] == BOMB_VALUE )
	{
		u8Counting++;
	}
	if ( au8Mines[u8MinesRow][u8MinesColumn + 1] == BOMB_VALUE )
	{
		u8Counting++;
	}
	if ( au8Mines[u8MinesRow + 1][u8MinesColumn + 1] == BOMB_VALUE )
	{
		u8Counting++;
	}
	if ( au8Mines[u8MinesRow + 1][u8MinesColumn] == BOMB_VALUE )
	{
		u8Counting++;
	}
	if ( au8Mines[u8MinesRow + 1][u8MinesColumn - 1] == BOMB_VALUE )
	{
		u8Counting++;
	}
	if ( au8Mines[u8MinesRow][u8MinesColumn - 1] == BOMB_VALUE )
	{
		u8Counting++;
	}
	if ( au8Mines[u8MinesRow - 1][u8MinesColumn - 1] == BOMB_VALUE )
	{
		u8Counting++;
	}

	return u8Counting;
}

void ShowAllMapMines(uint8 au8Mines[MINES_MAP_SIZE][MINES_MAP_SIZE])
{
	printf("\n");
	for ( int i = 0; i < MINES_MAP_SIZE; i++ )
	{
	  	printf("%d ", i);
	}

	printf("\n");
	printf("\n");

	for ( int i = 0; i < MINES_MAP_SIZE; i++ )
	{
		for ( int j = 0; j < MINES_MAP_SIZE; j++ )
		{
			if ( au8Mines[i][j] == BASE_VALUE )
			{
				printf("%c ", HASHTAG_ASCII_VALUE);
			}
			else if ( au8Mines[i][j] == BOMB_VALUE )
			{
				printf("%c ", AT_ASCII_VALUE);
			}
			else
			{
				printf("%d ", au8Mines[i][j] );
			}
		}
	    printf("	%d", i);   
		puts("");
	}
}