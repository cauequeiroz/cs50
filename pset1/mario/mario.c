#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get wall size from user
    // ----------------------------------------------------------------
    int size;
    do {
        size = get_int("Height: ");
    } while (size < 1 || size > 8);

    // Generate wall
    // ----------------------------------------------------------------
    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
            if (j>= (size-i-1))
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }

        printf("  ");

        for (int j=0; j<size; j++)
        {
            if (j<=i)
            {
                printf("#");
            }
        }

        printf("\n");
    }

}