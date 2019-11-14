#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars; // do-while loop
    do 
    {
       dollars = get_float ("change owed: "); // user input of change
    }
    while (dollars < 0); // ensure positive amount entered
    
    int cents = round(dollars * 100); // convert dollars to cents
    int coins = 0; // store the number of coins
    while (cents >= 25)  // quarter loop
    {
        cents -= 25;
        coins++;  
    }
    while (cents >= 10) // dime loop
    {
        cents -= 10;
        coins++;
    }
    while (cents >= 5) // nickel loop
    {
        cents -= 5;
        coins++;
    }
    while (cents >= 1) // penny loop
    {
        cents -= 1;
        coins++;
    }
    printf ("%i\n", coins);
}
