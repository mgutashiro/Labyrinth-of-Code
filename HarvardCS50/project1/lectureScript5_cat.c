#include <cs50.h>
#include <stdio.h>

int get_n(void);
void meow(int times);


int main(void)
{
    // get a number from user
    int n = get_n();
    meow(n);
}

// to get int that's 0 or a positive and not negativd
int get_n(void)
{
    int n;
    do
    {
        n = get_int("What's n? ");
    }
    while (n < 0);
    return n;
}

void meow(int times)
{
    // meow some # of times
    for (int i = 0; i < times; i++)
    {
        printf("meow\n");
    }
}
