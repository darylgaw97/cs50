#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

char upper[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char lower[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int main(int argc, string argv[])
{
    //checking for valid Key input from user
    if (argc == 1) //Error: No key entered
    {
        printf("Please input key!\n");
        return 1;
    }
    if (argc > 2) //Error: Invalid Key
    {
        printf("Please input valid key!\n"); 
        return 1;
    }
    if (strlen(argv[1]) != 26) //Error:  Key is not 26 characters long
    {
        printf("Key needs to be 26 characters long!\n");
        return 1;
    }
    //Key has 26 characters
    for (int i = 0; i < 26; i++) //checking if user input contains digits
    {
        if isdigit(argv[1][i])
        {
            printf("Key cannot contain digits\n!");
            return 1;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        argv[1][i] = toupper(argv[1][i]); //converting user input to lowercase for simplicity sake
    }
    for (int i = 0; i < 26; i++) // checking if user duplicated letters in Key
    {
        for (int j = i + 1;  j < 26; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("Key cannot contain repeating characters!\n");
                return 1;
            }
        }
    }
    
    //If code reaches this stage, the Key is deemed to be valid, proceeding to subsituting plaintext into ciphertext
    {
        string plaintext = get_string("Enter plaintext: ");
        int length = strlen(plaintext);
        printf("ciphertext: ");
        for (int i = 0; i < length; i++ ) //going through letters in plaintext one by one
        {
            if islower(plaintext[i])
            {
                int j = 0;
                while (plaintext[i] != lower[j])
                {
                    j++;
                }
                plaintext[i] = argv[1][j];
                printf("%c", tolower(argv[1][j]));
            }
            else if isupper(plaintext[i])
            {
                int j = 0;
                while (plaintext[i] != upper[j])
                {
                    j++;
                }
                plaintext[i] = argv[1][j];
                printf("%c", toupper(argv[1][j]));
            }
            else
            printf("%c", plaintext[i]);
        }
        printf("\n");
    }
}

