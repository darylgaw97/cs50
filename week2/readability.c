#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

float count_letters(string text);
float count_words(string text);
float count_sentences(string text);
float colemanliauindex(float letters, float words, float sentences);
int main(void)
{
    string text = get_string("text: ");
    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);
    float index = colemanliauindex(letters, words, sentences);
    index = round(index);

    //printing reading grade
    if (index >= 1 && index <= 16)
    {
        printf("Grade %i\n", (int)index);
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
}

//count letters
float count_letters(string text)
{
    float string_length = strlen(text);
    float sum = 0;
    for (int i = 0; i < string_length; i++)
    {
        if isalpha(text[i])
        {
            sum = sum + 1;
        }
    }
    return sum;
}

//count words
float count_words(string text)
{
    int string_length = strlen(text);
    float sum = 1;
    for (int i = 0; i < string_length; i++)
    {
        if isspace(text[i])
        {
            sum = sum + 1;
        }
    }
    return sum;
}

//count sentences
float count_sentences(string text)
{
    int string_length = strlen(text);
    int x = 0;
    int sum = 0;
    for (int i = 0; i < string_length; i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sum = sum + 1;
            while (text[i] == 46)
            {
                i++;
            }
        }
    }
    return sum;
    printf("sentences: %i", sum);
}

//calculating coleman liau index
float colemanliauindex(float letters, float words, float sentences)
{
    //calculating L
    float L;
    if (words < 100)
    {
        float x = 100 / words;
        L = (letters * x);
    }
    if (words > 100)
    {
        float x = words / 100;
        L = (letters / x);
    }
    if (words == 100)
    {
        L = letters / words;
    }
    //calculating S
    float S;
    if (words < 100)
    {
        float x = 100 / words;
        S = (sentences * x);
    }
    if (words > 100)
    {
        float x = words / 100;
        L = (sentences / x);
    }
    if (words == 100)
    {
        S = sentences / words;
    }
    //calculating index
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    index = round(index);
    return index;
}
