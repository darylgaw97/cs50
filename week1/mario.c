#include <stdio.h>
#include <cs50.h>

int main(void)

{
    //prompt user for input

    int y;
    do
    {
        y = get_int("height:");
    }
    while (y < 1 || y > 8);

    //build blocks
        int r = y-1;

        //build (vertical)
        for (int i = 0 ; i < y; i++)
        {
            //build horizontal
                //number of dots
                for (int j = r; j > 0; j--)
                {
                 printf(" ");

                }
                //number of hashes
                for (int k = r; k < y; k++)
                {
                    printf("#");
                }
                printf("\n");
                r--;
        }
}
