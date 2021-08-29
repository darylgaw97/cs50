#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)

{
    //prompt input for change
    float change;
    do
    {
        change = get_float("change owed:");
    }
    while (change <= 0);
    
    //convert dollars to cents
    int cents;
    cents = round (change * 100);
    
    //counting number coins needed
    
    //number of quarters (25cents)
    int coins = 0;
    while (cents >= 25)
    {
        cents = cents - 25;
        coins++;
    }
    
    //number of dimes (10cents)
    while (cents >= 10)
    {
        cents = cents - 10;
        coins++;
    }
    
    //number of nickels (5cents)
    while (cents >= 5)
    {
        cents = cents - 5;
        coins++;
    }
    
    //number of pennies (1cent)
    while (cents >= 1)
    {
        cents = cents - 1;
        coins++;
    }
    
    printf("%i\n", coins);
}