#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    int countL = 0; // Declaring the variable where im going to store the number of characters.
    int countS = 1; // Declaing the variable where im going to store the number of spaces.
    int countP = 0; // Declaring the variable where im going to store the number of phrases.

    string text = get_string("Text: "); // Taking the text input from the user.
    int n = strlen(text); // Calculating the lenght of the text sumbitted by the user.

    for (int i = 0; i < n; i++) // Starting a for loop
    {
        char c = text[i];
        if (isalpha(text[i]) != 0) // Checking if the item in the array is a carachter.
        {
            countL++; // If so then add it to the character counter.
        }

        else if (isspace(text[i]) != 0 && text[i + 1]  != ' ') // Checking if the item in the array is a space.
        {
            countS++; // If so then add it to the space counter.
        }

        else if (text[i] == '.' || text[i] == '?' || text[i] == '!') 
        {
            countP++; // If so then add it to the points counter.
        }
    }
    float AvL = countL * 100.0 / countS; // Calcualting the average number of letters per 100 words in the text
    float AvS = countP * 100.0 / countS; //S is the average number of sentences per 100 words in the text.

    int grade = round(0.0588 * AvL - 0.296 * AvS - 15.8); // Using the formula to calculate re readability.

    if (grade >= 16)
    {
        printf("Grade 16+\n"); // Text to print if the grade is equal or more than 16.
    }

    else if (grade <= 1)
    {
        printf("Before Grade 1\n"); // Text to print if the grade is equal or less than 1.
    }

    else
    {
        printf("Grade %i\n", grade); // Text to print based on the grade value.
    }

}
