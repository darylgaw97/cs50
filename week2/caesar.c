#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

//get key
int main(int argc, string argv[])
{
    int key;
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        for (int i = 0; i < strlen(argv[1]); i++) //checking if user input for argv[1] are digits
        {
            if isdigit(argv[1][i]) //'isdigit' can only check char by char hence looping through the string char by char here
            {
                continue;
            }
            else
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        key = atoi(argv[1]);
    }
    
    //get plaintext from user
    string plaintext = get_string("plaintext: ");
    
    //encipher and print out
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if islower(plaintext[i])
        {
            char cil = ((char)plaintext[i] - 97 + key) % 26 + 97;
            printf("%c", cil);
        }
        else if isupper(plaintext[i])
        {
            char ciu = ((char)plaintext[i] - 65 + key) % 26 + 65;
            printf("%c", ciu);
        }
        else
        {
            printf("%c", (char)plaintext[i]);
        }
    }
    printf("\n");
}
