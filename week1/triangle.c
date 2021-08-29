#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool triangle(float x, float y, float z);

int main(void)
{
    float a = get_float("a:");
    float b = get_float("b:");
    float c = get_float("c:");
    bool valid = triangle(a, b, c);
    printf("%i", (int)valid);
}

bool triangle(float x, float y, float z)
{
    if (x + y <= z || x + z <= y || y + z <= x)
    {
        return false;
    }
    else
    {
        return true;
    }
}
