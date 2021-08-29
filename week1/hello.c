#include <cs50.h>
#include <stdio.h>

int main(void)

{
    //prompt user for name
    string name = get_string("what is your name?\n");
    
    //greet user
    printf("Hello, %s\n", name);
}