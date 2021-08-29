#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    do
    {
        start = get_int("start size:");
    }
    while (start < 9);

    // TODO: Prompt for end size
    int end;
    do
    {
        end = get_int("end size:");
    }
    while (end < start);

    // TODO: Calculate number of years until we reach threshold
    int population;
    int birth;
    int death;
    
    population = start;
    
    int years;
    for (int n = 1; population < end; n++)
    {
        birth = population/3;
        death = population/4;
        population = population + birth - death;
        years = n;
    }
    // TODO: Print number of years
    printf("Years: %i", years);
    printf("\n");
}