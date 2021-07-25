#include <stdio.h>
#include <cs50.h>

void get_credit_card_brand(long number, long x, int counter);

int main(void)
{
    long number = get_long("Number: ");
    long x = 1;
    long y;
    int last_digit = 0;
    int counter = 0;
    int even_sum = 0;
    int odd_sum = 0;
    int product;

    // Crazy sum of all digits (Luhn’s Algorithm)
    // --------------------------------------------------------
    while (1)
    {
        y = number % (x*10);
        last_digit = (y - last_digit) / x;

        if (y == number && last_digit == 0)
        {
            break;
        }

        if (counter % 2 != 0)
        {
            product = last_digit * 2;


            if (product >= 10)
            {
                even_sum += product % 10;
                even_sum += (product - (product % 10)) / 10;
            }
            else
            {
                even_sum += product;
            }
        }
        else
        {
            odd_sum += last_digit;
        }

        x *= 10;
        counter += 1;
    }

    // Check if is a valid of invalid card
    // --------------------------------------------------------
    int sum_of_digits = even_sum + odd_sum;
    if (sum_of_digits % 10 == 0)
    {
        get_credit_card_brand(number, x, counter);
    }
    else
    {
        printf("INVALID\n");
    }
}

void get_credit_card_brand(long number, long x, int counter)
{
    if (number / (x/10) == 4)
    {
        if (counter == 13 || counter == 16)
        {
            printf("VISA\n");
        }
        else {
            printf("INVALID\n");
        }
    }
    else
    {
        int digits = number / (x/100);

        if ((digits == 34 || digits == 37) && counter == 15)
        {
            printf("AMEX\n");
        }
        else if ((digits >= 51 && digits <= 55) && counter == 16)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}