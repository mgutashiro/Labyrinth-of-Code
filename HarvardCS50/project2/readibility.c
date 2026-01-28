#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //asking users to inputting text
    string text = get_string("Paste Text to Evaluate: ");

    // letter count of text
    int letters = count_letters(text);

    // word count of text
    int words = count_words(text);

    // sentence count
    int sentences = count_sentences(text);


    // calculating index of text
    //average number of letters 
    float L = ((float) letters / (float) words) * 100.0;
    //average number of sentences
    float S = ((float) sentences / (float) words) * 100.0;

    // Coleman-Liau index calculation
    int index = (int) round(0.0588 * L - 0.296 * S - 15.8);

    // outputting  
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    // return # of letters
    int letters = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if(isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    // return # of word count
    int words = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if(text[i] == ' ')
        {
            words++;
        }
    }
    return words + 1;
}

int count_sentences(string text)
{
    // return # of sentences
    int sentences = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if(text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;

}