#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get program inputs from user
    // -------------------------------------------------
    int start_size;
    int end_size;

    do
    {
        start_size = get_int("Start size: ");
    } while(start_size < 8);

    do
    {
        end_size = get_int("End size: ");
    } while(end_size < start_size);


    // Run calculations
    // -------------------------------------------------
    int year = 0;
    int population = start_size;
    int new_population;
    int dead_population;

    while (population < end_size)
    {
        new_population = population / 3;
        dead_population = population / 4;

        population = population + new_population - dead_population;
        year += 1;
    }

    printf("Years: %i\n", year);

}