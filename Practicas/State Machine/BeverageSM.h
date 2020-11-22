/*Variables*/

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

typedef enum
{
	enMenu = 0,
	enServingDrink,
	enWaitUntilDrinkServed,
	enMaxStates
}SM_allOptions;

typedef enum
{
	enIce = 0,
    enAlcohol,
    enDelay,
    enMaxIngredients
}tenIngredients;

/*Defines*/

#define MARTINI					1
#define CHAMPAGNE_COCKTAIL		2
#define CREAMY_IRISH_COFFEE		3
#define MIMOSA					4
#define DRINK_CHOICES			5
#define STOCK_VODKA				22	//Servings
#define STOCK_DRYVERMOUTH		136	//Servings
#define SOCK_BITTERS			21	//Servings
#define STOCK_CHAMPAGNE			22	//Servings
#define STOCK_BRANDY			136	//Servings
#define STOCK_COFFEE			4	//Servings
#define STOCK_IRISHLIQUEUR		17	//Servings
#define STOCK_TRIPLESEC			136	//Servings
#define STOCK_ORANGEJUICE		64	//Servings
#define INITIAL_WEIGHT			0
#define FINAL_WEIGHT			5
#define TRUE					1
#define FALSE					0

/*Prototypes*/

void ServeDrink( uint8 u8DrinkSelected );
void ShowIngredients( uint8 u8DrinkSelected );
void delay ( uint16 u16Time );
uint8 u8DrinkSelection();
uint8 u8CheckStockOf( uint8 u8DrinkSelected );
uint8 u8InitialWeightCheck( uint8 u8GlassWeight );
uint8 u8FinalWeightCheck( uint8 u8GlassWeight );