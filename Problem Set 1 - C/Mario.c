#include <cs50.h>
#include <stdio.h>

int main(void)
{
    
    int height;

    do
    {
        height = get_int("Height: "); //get the user input for the height
    }
    while (height < 1 || height > 8);
    for (int i = 0; i < height; i++)
    {
        for (int j = i + 1 ; j < height; j++)
        {
            printf(" "); // create spaces using loop
        }
        for (int k = 0; k <= i  ; k++)
        {
            printf("#"); // create hashes using loop
        }   
        printf("\n"); 
    }


}
