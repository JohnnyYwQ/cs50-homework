#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// declare an array store every alpha's index
const int alphabet[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                          1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    // prompt usr for input
    string player_1 = get_string("player1: ");
    string player_2 = get_string("player2: ");

    // calulate score of two player
    // declare players' score
    int score_1 = 0;
    int score_2 = 0;
    for (int i = 0, n = strlen(player_1); i < n; i++)
    {
        // check if player_1[i] is alpha then turn it to uppercase
        if (isalpha(player_1[i]))
        {
            score_1 += alphabet[toupper(player_1[i]) - 'A'];
        }
    }
    for (int i = 0, n = strlen(player_2); i < n; i++)
    {
        // check if player_2[i] is alpha then turn it to uppercase
        if (isalpha(player_2[i]))
        {
            score_2 += alphabet[toupper(player_2[i]) - 'A'];
        }
    }

    // compare then print
    if (score_1 > score_2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score_1 < score_2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("tie\n");
    }
}
