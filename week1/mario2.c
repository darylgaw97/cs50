#include <stdio.h>
#include <cs50.h>

int main(void)

{
    // prompt user input
    int y;
    do
    {
        y = get_int("height:");
    }
    while (y < 1 || y > 8);

    int r = y-1;
    for ( int i = y; i > 0; i--)
    {
        //building left pyramid
        for (int j = r; j > 0; j--)
        {
        printf(" ");
        }
        for (int k = r; k < y; k++)
        {
            printf("#");
        }

        //creating gap
        
        printf("  ");
        
        //building right pyramid
        for (int a = r; a < y; a++)
        {
             printf("#");
        }
        printf("\n");
        r--;
    }
}