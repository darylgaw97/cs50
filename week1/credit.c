#include <cs50.h>
#include <stdio.h>

int main(void)

{
    //prompt credit card number
    long n = get_long("credit card number:");
    long cardtype = n;
    long visa = n;
    
    //checking card validity
    int oddsum = 0;
    int evensum = 0;

    while (n > 0)
    {
        int odd;
        odd = n % 10;
        n = n / 10;
        oddsum = oddsum + odd;

        int even;
        even = (n % 10) * 2;
        n = n / 10;
        if (even > 2)
        {
            if (even >= 10)
            {
                even = (even % 10) + 1;
            }
            else
            {
                even = (even % 10);
            }

        }
        evensum = evensum + even;
    }
    int endnumber;
    endnumber = oddsum + evensum;
    while (endnumber > 10)
    {
        endnumber = endnumber % 10;
    }
    int validity;
    if (endnumber == 0)
    {
        validity = 1;
    }
    else
    {
        validity = 0;
    }
    
    // determine the type of card
    while (cardtype >= 100)
    {
        cardtype = cardtype / 10;
    }
    
    if (cardtype == 34 || cardtype == 37)
    {
        cardtype = 1;
    }
    else if (cardtype == 51 || cardtype == 52 || cardtype == 53 || cardtype == 54 || cardtype == 55)
    {
        cardtype = 2;
    }
    else
    {
        cardtype = cardtype / 10;
        if (cardtype == 4)
        {
            cardtype = 3;
        }
        else 
        {
            cardtype = 0;
        }
    }
    
    //display answer
    if (cardtype == 0)
    {
        printf("INVALID\n");
    }
    
    if (cardtype == 1)
    {
        if (validity == 1)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    if (cardtype == 2)
    {
        if (validity == 1)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    if (cardtype == 3)
    {
        if (visa / 10000000000 > 0)
        {
            if (validity == 1)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
}