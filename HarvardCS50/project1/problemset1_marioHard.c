#include <cs50.h>
#include <stdio.h>

void print_row(int bricks, int height);

int main(void)
{
    // for incorrect input
    int height;
    do
    {
        height = get_int("What is height of pyramid? ");
    }
    while (height <= 0 || height > 8);

    // prompt user to input height
    for (int i = 0; i < height; i++)
    {
        print_row(i + 1, height);
    }
}

// inputting number of bricks
void print_row(int bricks, int height)
{
    int spaces = height - bricks;

    // left spaces
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }

    // left pyramid
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }

    // middle gap
    printf("  ");

    // right pyramid
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    printf("\n");
}
