#include <cs50.h>
#include <stdio.h>
#include <string.h>

// setting max # of candidates
#define MAX 9

// setting up structure for name and vote #
typedef struct
{
    string name;
    int votes;
} candidate;

// array of candidates
candidate candidates[MAX];

// number of candidates
int candidate_count;

// prototype of functions 
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // population array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // looping over all vectors
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // check for invalid vote
        if(!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }
    // print winner of election
    print_winner();

}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int totalVotes = 0;

    // double checking the winner
    for (int i =0; i < candidate_count; i++)
    {
        if (candidates[i].votes > totalVotes)
        {
            totalVotes = candidates[i].votes;
        }
    }

    // display winner of election
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == totalVotes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}