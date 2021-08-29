#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <getopt.h>
#include <ctype.h>

// defining pattern types
char *patterns = "abc";
void make_triangle(int n, char pattern);
int numlength(long number);

int main(int argc, char **argv)
{
    // checking for correct command-line input
    if (argc != 3 || atoi(argv[2]) == 0)
    {
        printf("Error!\nUsage: ./pascals_triangle.c -option <number>\n");
        return (1);
    }
    int n = atoi(argv[2]);
    // use getopt() to extract options from command-line input
    char pattern = getopt(argc, argv, patterns);
    if (pattern == '?')
    {
        printf("Invalid pattern!\nPatterns: a, b, c\n");
        return (2);
    }
    printf("Pattern: %c\n\n", pattern);
    make_triangle(n, pattern);
}

void make_triangle(int n, char pattern)
{
    long triangle[n][n];
    int longest = 0;

    // creating pascals triangle based on height of n
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (j == 0 || j == i)
                triangle[i][j] = 1;
            else
            {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
                if (numlength(triangle[i][j]) > longest)
                    longest = numlength(triangle[i][j]);
            }
        }
    }

    // printing the triangle based on the printing pattern chosen
    switch(pattern)
    {
        // left-indented
        case 'a':
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < i + 1; j++)
                {
                    printf("%li ", triangle[i][j]);
                    int indent = longest - numlength(triangle[i][j]);
                    for (int tab = 0; tab < indent; tab++)
                    {
                        printf(" ");
                    }
                }
                printf("\n");
            }
            break;

        // middle-indented
        case 'b':
            for (int i = 0; i < n; i++)
            {
                for (int s = n; s > i + 1; s--)
                {
                    printf(" ");
                }
                for (int l = 0; l < longest / 2 * (n - i); l++)
                {
                    printf(" ");
                }
                for (int j = 0; j < i + 1; j++)
                {
                    int indent = longest - numlength(triangle[i][j]);
                    for (int tab = 0; tab < indent; tab++)
                    {
                        printf(" ");
                    }
                    printf("%li ", triangle[i][j]);
                    if (longest % 2 == 0 && n != 2)
                        printf(" ");
                }
                printf("\n");
            }
            break;
    }
}

int numlength(long number)
{
    int length = 1;
    while (number / 10 != 0)
    {
        number /= 10;
        length++;
    }
    return length;
}