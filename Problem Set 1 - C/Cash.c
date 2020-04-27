#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float cash;
    int change;
    int count = 0; //This variable allow us to count the number of change that we should return.
    do
    {
        cash = get_float("Cash owed: "); // Getting the amount of money to change.
    }
    while (cash <= 0);
    change = round(cash * 100); //Rounding the cents to the nearest penny(integer).

    while (change >= 25) //This while loop allows us to use as many 25 coins as possible.
    {
        change = change - 25;
        count++;
    }
    while (change >= 10)//This while loop allows us to use as many 10 coins as possible.
    {
        change = change - 10;
        count++;
    }
    while (change >= 5)//This while loop allows us to use as many 5 coins as possible.
    {
        change = change - 5;
        count++;
    }
    while (change >= 1)//This while loop allows us to use as many 1 coins as possible.
    {
        change = change - 1;
        count++;
    }
    printf("%i\n", count);
}
