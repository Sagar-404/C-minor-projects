#include <stdio.h>

int outcome(char list[])
{
    // for player 1
    if (list[0] == 'X' && list[1] == 'X' && list[2] == 'X')
    {
        return 1;
    }
    if (list[3] == 'X' && list[4] == 'X' && list[5] == 'X')
    {
        return 1;
    }
    if (list[6] == 'X' && list[7] == 'X' && list[8] == 'X')
    {
        return 1;
    }
    if (list[0] == 'X' && list[3] == 'X' && list[6] == 'X')
    {
        return 1;
    }
    if (list[1] == 'X' && list[4] == 'X' && list[7] == 'X')
    {
        return 1;
    }
    if (list[2] == 'X' && list[5] == 'X' && list[8] == 'X')
    {
        return 1;
    }
    if (list[6] == 'X' && list[4] == 'X' && list[2] == 'X')
    {
        return 1;
    }
    if (list[0] == 'X' && list[4] == 'X' && list[8] == 'X')
    {
        return 1;
    }
    // for player 2
    if (list[0] == 'O' && list[1] == 'O' && list[2] == 'O')
    {
        return 2;
    }
    if (list[3] == 'O' && list[4] == 'O' && list[5] == 'O')
    {
        return 2;
    }
    if (list[6] == 'O' && list[7] == 'O' && list[8] == 'O')
    {
        return 2;
    }
    if (list[0] == 'O' && list[3] == 'O' && list[6] == 'O')
    {
        return 2;
    }
    if (list[1] == 'O' && list[4] == 'O' && list[7] == 'O')
    {
        return 2;
    }
    if (list[2] == 'O' && list[5] == 'O' && list[8] == 'O')
    {
        return 2;
    }
    if (list[6] == 'O' && list[4] == 'O' && list[2] == 'O')
    {
        return 2;
    }
    if (list[0] == 'O' && list[4] == 'O' && list[8] == 'O')
    {
        return 2;
    }
}

int input(int array[], int *ptr, char list[], int *n)
{

    for (int i = 0; *ptr != *n; i++)
    {
        int player_input = 0;
        if (*ptr == 0 || *ptr == 20 || *ptr == 40 || *ptr == 60 || *ptr == 80)
        {
            printf("Player 1 turn\n");
        }
        if (*ptr == 10 || *ptr == 30 || *ptr == 50 || *ptr == 70)
        {
            printf("Player 2 turn\n");
        }

        scanf("%d", &player_input);
        if (player_input >= 1 && player_input <= 9)
        {
            for (int i = 0; i < 9; i++)
            {
                if (player_input == array[i])
                {
                    *ptr += 10;
                    array[i] = 0;
                    if (*ptr == 10 || *ptr == 30 || *ptr == 50 || *ptr == 70 || *ptr == 90)
                    {
                        list[i] = 'X';
                    }
                    if (*ptr == 20 || *ptr == 40 || *ptr == 60 || *ptr == 80)
                    {
                        list[i] = 'O';
                    }
                }
            }
        }
        else
        {
            *ptr += 0;
            printf("\nEnter a valid number\n");
        }
    }
    return 0;
}

void game(int array[])
{
    printf("\n ==== LAY-OUT ====\n\n");
    printf("     %d | %d | %d \n", array[0], array[1], array[2]);
    printf("    ---|---|---\n");
    printf("     %d | %d | %d \n", array[3], array[4], array[5]);
    printf("    ---|---|---\n");
    printf("     %d | %d | %d \n", array[6], array[7], array[8]);
    printf("\n ==== LAY-OUT ====\n\n");
}

void board(char array[])
{
    printf("\n == TIK TAC TOE == \n\n");
    printf("     %c | %c | %c \n", array[0], array[1], array[2]);
    printf("    ---|---|---\n");
    printf("     %c | %c | %c \n", array[3], array[4], array[5]);
    printf("    ---|---|---\n");
    printf("     %c | %c | %c \n", array[6], array[7], array[8]);
    printf("\n == TIK TAC TOE == \n\n");
}

int main()
{
    int score = 0;
    int draw = 0;
    int *p_draw = &draw;
    int help = 0;
    int *p_help = &help;
    char list[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int *p_score = &score;
    int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    game(values);
    board(list);
    for (int i = 1; i < 10; i++)
    {
        int out = outcome(list);
        *p_draw = out;
        if (out == 1)
        {
            printf(" !! Player 1 Won !!\n");
            break;
        }
        if (out == 2)
        {
            printf(" !! Player 2 Won !!\n");
            break;
        }

        *p_help += 10;
        input(values, p_score, list, p_help);
        // game(values);
        board(list);
    }
    if (*p_score == 90 && draw != 1 && draw != 2)
    {
        printf("=====> DRAW <=====\n\n");
    }
}
