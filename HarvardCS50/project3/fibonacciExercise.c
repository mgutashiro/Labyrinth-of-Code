#include <cs50.h>
#include <stdio.h>

int fibonacci(int n);

int main(void)
{
    int n = get_int("Fibonacci number: ");

    // print output
    printf("The %i Fibonacci number is %i\n", n, fibonacci(n));
}

// calculate fibonacci sequence
int fibonacci(int n)
{
    // base case
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    // recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}