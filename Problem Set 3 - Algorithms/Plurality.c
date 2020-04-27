#include <cs50.h>
#include <stdio.h>
#include <string.h>


#define MAX 9 // defining a new type of data structure


typedef struct
{
    string name; 
    int votes;
}
candidate;


candidate candidates[MAX];


int candidate_count; // Create a variabile to store the count of candidates


bool vote(string name); // Calling the secondary function at the top of the program 
void print_winner(void); // Calling the secondary function at the top of the program 

int main(int argc, string argv[]) // Declaring main function
{

    if (argc < 2) // Check if the input contain less than 2 values
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }


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

    int voter_count = get_int("Number of voters: "); // Ask the user for the number of voters


    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");


        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }


    print_winner();
}


bool vote(string name) // Declaring a new function
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0) // Compraing the 2 strings
        {
            candidates[i].votes++;
            return true;
        }

    }
    return false;
}


void print_winner(void) // Define the function that can print the winner
{ 
    int swap_counter = -1;
    string winning_candidate = "";
    int winning_votes;
    if (swap_counter != 0)
    {
        for (int i = candidate_count; i > 0; i--)
        {

            if (candidates[i].votes < candidates[i - 1].votes)
            {
                swap_counter = 0;
                candidates[i] = candidates[i - 1];
                candidates[i - 1] = candidates[i];
                winning_votes = candidates[i].votes;
                swap_counter++;
            }

        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (winning_votes == candidates[i].votes)
        {
            winning_candidate = candidates[i].name;
            printf("%s\n", winning_candidate);
        }

    }

    return;
}
