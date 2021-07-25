#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");
    } while (dollars < 0);

    int cents = round(dollars * 100);
    int coins = 0;

    while (cents / 25 > 0)
    {
        cents -= 25;
        coins += 1;
    }

    while (cents / 10 > 0)
    {
        cents -= 10;
        coins += 1;
    }

    while (cents / 5 > 0)
    {
        cents -= 5;
        coins += 1;
    }

    while (cents / 1 > 0)
    {
        cents -= 1;
        coins += 1;
    }

    printf("%i\n", coins);
}