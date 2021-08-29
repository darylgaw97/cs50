#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

char capital[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char small[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string s);
int main(void)
{
    //inputs form player 1 and 2
    string word1 = get_string("type something:");
    string word2 = get_string("type something:");
    
    //score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    
    //announce winner
    if (score1 > score2)
    {
        printf("Player 1 wins!");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!");
    }
}

int compute_score(string s)
{
    //type out letters one by one
    int string_length = strlen(s);
    int sum = 0;
    char a;
    for (int i = 0; i < string_length; i++)
    {
        if (s[i] > 64 && s[i] < 91) //checking if letter is a capital letter
        {
            int j;
            for (j = 0; s[i] != capital[j];)
            {
                j++;
            }
            a = POINTS[j]; //assigning points to letter
        }
        else if (s[i] > 96 && s[i] < 123) //checking if letter is small letter
        {
            int j;
            for (j = 0; s[i] != small[j];)
            {
                j++;
            }
            a = POINTS[j]; //assigning points to letter
        }
        else //meaning the character is not a letter
        {
            a = 0; //no point given to non-letter characters
        }
        sum = sum + a; //calculating word score by adding individual letter scores
        
    }
    return sum;
}
