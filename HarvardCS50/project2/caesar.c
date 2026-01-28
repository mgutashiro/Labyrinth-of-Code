#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // making sure program was run with just one command argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // making sure every character in argv[1] is a digit
    // for loop here needed bc isdigit only checks one character
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert argv[1] from a `string` to an `int`
    int keynumber = atoi(argv[1]);

    // prompt user for plain text
    string plainText = get_string("plaintext: ");

    printf("ciphertext: ");
    // for each character in a plain text
    for (int i = 0, len = strlen(plainText); i<len; i++)
    {
        // rotate the characters
        char c = plainText[i];
        if (isupper(c))
        {
            // when 'A' is 0, rotate back to A
            char cypherText = (c - 'A' + keynumber) %26 + 'A';
            printf("%c", cypherText);
        }
        else if (islower(c))
        {
            char cypherText = (c - 'a' + keynumber) %26 + 'a';
            printf("%c", cypherText);
        }
        //for punctuations
        else
        {
            printf("%c", c);
        }
        
    }
    printf("\n");

}