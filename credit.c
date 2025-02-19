#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // setting up variables
    long n;
    int position = 1;
    long tsum = 0;
    long sum_odd = 0;
    int valid = 0;
    long count = 0;

    // asking user for their card number

    n = get_long("Number: ");

    if (n < 1e12 || n >= 1e16)
    {
        printf("INVALID\n");
        return 0;
    }

    long temp = n;
    // testing to see if card is valid or not
    tsum = 0;
    while (temp > 0)
    {
        int digit = (temp % 10);
        temp = temp / 10;
        if (position % 2 == 0)
        {
            int p = digit * 2;
            int psum = (p % 10) + (p / 10);
            tsum += psum;
        }
        else
        {
            tsum += digit;
        }
        position++;
    }
    if (tsum % 10 == 0)
    {
        valid = 1;
    }
    else
    {
        valid = 0;
    }

    long original_n = n;
    // counting how long the card number is
    while (n > 0)
    {
        n = n / 10;
        count++;
    }
    // seeing what the card number starts with
    n = original_n;
    while (n >= 100)
    {
        n = n / 10;
    }
    // stating what type of card, based on c length and and if its not valid
    if (valid == 0)
    {
        printf("INVALID\n");
    }
    else if (count == 15 && (n == 34 || n == 37))
    {
        printf("AMEX\n");
    }
    else if (count == 16 && (n >= 51 && n <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if (((count == 13 || count == 16)) && (n / 10 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
