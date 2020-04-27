#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])  // Create the function
{
    if (argc != 2) // Check the user input
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }

    for (int i = 0, l = strlen(argv[1]); i < l; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    int k = atoi(argv[1]);

    string plain = get_string("plaintext: "); // Getting the input from the user
    printf("ciphertext: ");



    for (int i = 0, l = strlen(plain); i < l; i++)
    {

        if (islower(plain[i])) // Check if the letter is lower
        {
            printf("%c", (plain[i] - 'a' + k) % 26 + 'a'); // Fromula given from the CS50 website
        }

        else if (isupper(plain[i])) // Check if the letter is upper
        {
            printf("%c", (plain[i] - 'A' + k) % 26 + 'A'); // Fromula given from the CS50 website
        }

        else
        {
            printf("%c", plain[i]);
        }
    }




    printf("\n");
}
