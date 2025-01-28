#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
char player = 'X';
char computer = 'O';

void resetBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
};

void printBoard()
{
    printf("\n|-----|-----|-----|\n");
    for (int i = 0; i < 3; i++)
    {
        printf("|");
        for (int j = 0; j < 3; j++)
        {
            printf("  %c  |", board[i][j]);
        }
        printf("\n|-----|-----|-----|\n");
    }
};

int checkFreeSpaces()
{
    // chances
    // printf("free space");
    int chances = 9;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                chances--;
            }
        }
    }
    return chances;
};
void playerMove()
{
    int R;
    int C;
    do
    {
        printf("your move(ROW): ");
        scanf("%d", &R);
        printf("your move(COLM): ");
        scanf("%d", &C);
        if (R >= 0 && R < 4 && C >= 0 && C < 4)
        {
            R--;
            C--;
            if (board[R][C] == ' ')
            {
                board[R][C] = player;
                break;
            }
            else
            {
                printf("already taken this move!\n");
            }
        }
        else
        {
            printf("Invalid value please insert (1-3)\n");
        }

    } while (board[R][C] != ' ');
};

char checkWinner()
{
    // ROW
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }
    // column
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }
    return ' ';
};

void computerMove()
{
    srand(time(0));
    int RC;
    int CC;

    if (checkFreeSpaces() > 0)
    {
        do
        {
            RC = rand() % 3;
            CC = rand() % 3;

        } while (board[RC][CC] != ' ');
        board[RC][CC] = computer;
    }
};

void printWinner(char winner)
{
    if (winner == 'X')
    {
        printf("You are the winner!");
    }
    else if (winner == 'O')
    {
        printf("You lose!.. Try again!");
    }
    else
    {
        printf("It`s a tie!");
    }
};

int main()
{
    char winner = ' ';
    resetBoard();
    while (winner == ' ' && checkFreeSpaces() != 0)
    {
        printf("%d", checkFreeSpaces());
        printBoard();
        playerMove();

        winner = checkWinner();
        if (winner != ' ' || checkFreeSpaces() == 0)
        {
            break;
        }
        computerMove();
        winner = checkWinner();
        if (winner != ' ' || checkFreeSpaces() == 0)
        {
            break;
        }
    }
    printBoard();
    printWinner(winner);

    return 0;
}
