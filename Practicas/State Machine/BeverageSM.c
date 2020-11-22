#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "BeverageSM.h"

uint8 u8Vodka = STOCK_VODKA;
uint8 u8DryVermouth = STOCK_DRYVERMOUTH;
uint8 u8Bitters = SOCK_BITTERS;
uint8 u8Champagne = STOCK_CHAMPAGNE;
uint8 u8Brandy = STOCK_BRANDY;
uint8 u8Coffee = STOCK_COFFEE;
uint8 u8IrishLiqueur = STOCK_IRISHLIQUEUR;
uint8 u8TripleSec = STOCK_TRIPLESEC;
uint8 u8OrangeJuice = STOCK_ORANGEJUICE;

void main ( void )
{	
	SM_allOptions enCurrentDrink = enMenu;
	uint8 u8StockChecked = 0;
	uint8 u8DrinkSelected = 0;
	uint8 u8FinalWeightChecked = 0;
	uint8 u8InitialWeightChecked = 0;
	uint8 u8GlassWeight = INITIAL_WEIGHT;
	
	while ( 1 )
	{
		switch ( enCurrentDrink )
		{
			case enMenu:
			{
				u8DrinkSelected = u8DrinkSelection();

				if( u8DrinkSelected != 0 && u8DrinkSelected < DRINK_CHOICES)
				{
					u8InitialWeightChecked = u8InitialWeightCheck( u8GlassWeight );
					if( u8InitialWeightChecked == TRUE  )
					{
						ShowIngredients( u8DrinkSelected );
						enCurrentDrink = enServingDrink;
					}
					else
					{
						/*Nothing To Do*/
					}
				}
				else
				{
					enCurrentDrink = enMenu;
				}

				break;
			}
			case enServingDrink:
			{
				u8StockChecked = u8CheckStockOf( u8DrinkSelected );
				if( u8StockChecked == TRUE )
				{
					ServeDrink( u8DrinkSelected );
					printf("\nHope you enjoy your drink!\n");
					enCurrentDrink = enWaitUntilDrinkServed;
				}
				else
				{
					printf("\nIngredients are missing can not complete the order.\n");
					enCurrentDrink = enMenu;
				}
				break;
			}

			case enWaitUntilDrinkServed:
			{
				u8FinalWeightChecked = u8FinalWeightCheck( u8GlassWeight );
				if( u8FinalWeightChecked == TRUE )
				{
					enCurrentDrink = enMenu;	
				}
				else
				{
					/*Nothing to do, remain in this state*/
				}
				break;
			}
			default:
				break;
		}
	}
}

/*Functions*/

uint8 u8DrinkSelection()
{
	uint8 u8InputAction = 0;

	fflush(stdin);
	printf("\nPress 1 to -> Select Martini\n");
	printf("Press 2 to -> Select Champagne Cocktail\n");
	printf("Press 3 to -> Select Creamy Irish Coffee\n");
	printf("Press 4 to -> Select Mimosa\n");
	printf("Enter selection: ");
	scanf("%d", &u8InputAction);

	if ( u8InputAction == MARTINI )
	{
		printf("\nDrink Selected - Martini\n");
		return u8InputAction;
	}
	else if ( u8InputAction == CHAMPAGNE_COCKTAIL )
	{
		printf("\nDrink Selected - Champagne Cocktail\n");
		return u8InputAction;
	}
	else if ( u8InputAction == CREAMY_IRISH_COFFEE )
	{
		printf("\nDrink Selected - Creamy Irish Coffee\n");
		return u8InputAction;
	}
	else if ( u8InputAction == MIMOSA )
	{
		printf("\nDrink Selected - Mimosa\n");
		return u8InputAction;
	}
	else
	{
		printf("\nOption selected does not exist.\n");
		u8InputAction = 0;
		return u8InputAction;
	}
}

void ShowIngredients( uint8 u8DrinkSelected )
{
	if( u8DrinkSelected == MARTINI )
	{
		printf("\nIngredients\n");
		printf("3 Oz Gin or Vodka\n");
		printf("1/2 Oz Dry Vermouth\n");
		printf("(Optional) - Adding Pimiento-stuffed Olives\n");
	}
	else if( u8DrinkSelected == CHAMPAGNE_COCKTAIL )
	{
		printf("\nIngredients\n");
		printf("6 Dashes Bitters\n");
		printf("1/2 Oz Brandy\n");
		printf("1/2 Cup Chilled Champagne\n");
		printf("(Optional) - Adding Fresh Rosemary Sprig and Fresh/Frozen Cranberriess\n");
	}
	else if( u8DrinkSelected == CREAMY_IRISH_COFFEE )
	{
		printf("\nIngredients\n");
		printf("3 Cups Hot Strong Brewed Coffee\n");
		printf("4 Oz Irish Cream Liqueur\n");
		printf("(Optional) - Adding Sweetened Whipped Cream and Chocolate Shavings\n");
	}
	else if( u8DrinkSelected == MIMOSA )
	{
		printf("\nIngredients\n");
		printf("2 Oz Champagne or Other Sparkling Wine\n");
		printf("1/2 Oz Triple Sec\n");
		printf("2 Oz Orange Juice\n");
		printf("(Optional) - Adding Orange Slice\n");
	}
	else
	{
		/*Nothing To Do*/
	}
}

uint8 u8CheckStockOf( uint8 u8DrinkSelected )
{
	if( u8DrinkSelected == MARTINI )
	{
		if ( u8Vodka > 0 && u8DryVermouth > 0)
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	else if( u8DrinkSelected == CHAMPAGNE_COCKTAIL )
	{
		if ( u8Bitters > 0 && u8Brandy > 0 && u8Champagne > 0)
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	else if( u8DrinkSelected == CREAMY_IRISH_COFFEE )
	{
		if ( u8Coffee > 0 && u8IrishLiqueur > 0)
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	else if( u8DrinkSelected == MIMOSA )
	{
		if ( u8Champagne > 0 && u8TripleSec > 0 && u8OrangeJuice > 0)
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		/*Nothing To Do*/
	}
}

void ServeDrink( uint8 u8DrinkSelected )
{
	if( u8DrinkSelected == MARTINI )
	{
		printf("\nServing 3 Oz of Gin/Vodka\n");
		for ( int i = 0; i < 3; i++)
		{
			printf("...\n");
			delay(1000);
		}
		printf("Served\n");

		printf("\nServing 1/2 Oz Dry Vermouth\n");
		for ( int i = 0; i < 3; i++)
		{
			printf("...\n");
			delay(1000);
		}
		printf("Served\n");

		printf("Process is Complete.\n");

		u8Vodka--;
		u8DryVermouth;
	}
	else if( u8DrinkSelected == CHAMPAGNE_COCKTAIL )
	{
		printf("\nServing 6 Dashes Bitters\n");
		for ( int i = 0; i < 3; i++)
		{
			printf("...\n");
			delay(1000);
		}
		printf("Served\n");

		printf("\nServing 1/2 Oz Brandy\n");
		for ( int i = 0; i < 3; i++)
		{
			printf("...\n");
			delay(1000);
		}
		printf("Served\n");

		printf("\nServing 1/2 Cup Chilled Champagne\n");
		for ( int i = 0; i < 3; i++)
		{
			printf("...\n");
			delay(1000);
		}
		printf("Served\n");

		printf("Process is Complete.\n");

		u8Bitters--;
		u8Brandy--;
		u8Champagne--;
	}
	else if( u8DrinkSelected == CREAMY_IRISH_COFFEE )
	{
		printf("\nServing 3 Cups Hot Strong Brewed Coffee\n");
		for ( int i = 0; i < 3; i++)
		{
			printf("...\n");
			delay(1000);
		}
		printf("Served\n");

		printf("\nServing 4 Oz Irish Cream Liqueur\n");
		for ( int i = 0; i < 3; i++)
		{
			printf("...\n");
			delay(1000);
		}
		printf("Served\n");

		printf("Process is Complete.\n");

		u8Coffee--;
		u8IrishLiqueur--;
	}
	else if( u8DrinkSelected == MIMOSA )
	{
		printf("\nServing 2 Oz Champagne/Other Sparkling Wine\n");
		for ( int i = 0; i < 3; i++)
		{
			printf("...\n");
			delay(1000);
		}
		printf("Served\n");

		printf("Serving 1/2 Oz Triple Sec\n");
		for ( int i = 0; i < 3; i++)
		{
			printf("...\n");
			delay(1000);
		}
		printf("Served\n");

		printf("Serving 2 Oz Orange Juice\n");
		for ( int i = 0; i < 3; i++)
		{
			printf("...\n");
			delay(1000);
		}
		printf("Served\n");

		printf("Process is Complete.\n");

		u8Champagne--;
		u8TripleSec--;
		u8OrangeJuice--;
	}
	else
	{
		/*Nothing To Do*/
	}
}

uint8 u8InitialWeightCheck( uint8 u8GlassWeight )
{
	u8GlassWeight = INITIAL_WEIGHT;

  	if( u8GlassWeight == INITIAL_WEIGHT)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

uint8 u8FinalWeightCheck( uint8 u8GlassWeight )
{
	u8GlassWeight = FINAL_WEIGHT;

  	if( u8GlassWeight == FINAL_WEIGHT)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void delay ( uint16 u16Time )
{
    clock_t goal = u16Time + clock();
    while ( goal > clock() );
}