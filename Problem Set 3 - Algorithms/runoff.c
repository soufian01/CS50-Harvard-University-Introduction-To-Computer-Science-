#include <cs50.h>
#include <stdio.h>
#include <string.h>


#define MAX_VOTERS 100 // Setting the maxium number of voters.
#define MAX_CANDIDATES 9 // Setting the maxium number of candidates.

int preferences[MAX_VOTERS][MAX_CANDIDATES];

typedef struct // Defining a new data structure.
{
    string name; // This DS contain name.
    int votes; // This DS contain votes.
    bool eliminated; // This DS contain eliminated status.
}
candidate;

candidate candidates[MAX_CANDIDATES]; // Array of the candidates.

int voter_count;
int candidate_count;
int rank_global;

// Protoypes of the functions.

bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[]) // Function to check che user input.
{
    if (argc < 2) // Check if the input contain less than 2 values.
    {
        printf("Usage: runoff [candidate ...]\n"); // If the input is not valid print how it have to be.
        return 1;
    }

    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: "); // Ask for the number of voters.
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    for (int i = 0; i < voter_count; i++)
    {

        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    while (true)
    {

        tabulate();

        bool won = print_winner();
        if (won)
        {
            break;
        }

        int min = find_min();
        bool tie = is_tie(min);

        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }


        eliminate(min);


        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

bool vote(int voter, int rank, string name) // This function is meant to record the preference if the vote is valid.
{

    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0) // Comparing the two strings.
        {
            preferences[voter][rank] = i;
            return true;
        }

    }
    return false;

}


void tabulate(void) // This function tabulate votes for non-eliminated candidates.
{

    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (candidates[preferences[i][j]].eliminated == false)
            {
                candidates[preferences[i][j]].votes++;
                break;
            }
            printf("%i\n", candidates[preferences[i][j]].votes);
        }
    }
    return;

}

bool print_winner(void) // This function prints the name of the winner, if there is one
{

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > (voter_count * 0.5))
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min[1] = {0};
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > min[0])
        {
            min[0] = candidates[i].votes;
        }
    }
    return min[0];
}


bool is_tie(int min) // This function return True if the election is tied between all candidates, false otherwise.
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes != min && candidates[i].eliminated == false)
        {
            return false;
        }
    }
    return true;
}

void eliminate(int min) // This function eliminate the candidates in the last place.
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
