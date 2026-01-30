#include<stdio.h>
#include<stdlib.h>
int N;
int board[50];

int is_valid(int row, int col)
{
    for(int i=0;i< row; i++)
    {
        if(board[i] == col || abs(board[i] - col)== abs(i-row))
        {
            return 0;
        }
    }
    return 1;
}

int nQs(int row)
{
    if(row >=N)
    {
        return 1;
    }

    for(int col=0; col <N; col++)
    {
        if(is_valid(row,col))
        {
            board[row] = col;
            if(nQs(row + 1))
            {
                return 1;
            }
            board[row] =-1;
        }
    }
    return 0;
}

void Soln()
{
    for(int i=0; i< N;i++)
    {
        for(int j=0;j< N;j++)
        {
            if(board[i]==j)
            {
                printf("Q ");
            }
            else{
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main()
{
    printf("How many Queen you want to place Your Majesty: ");
    scanf("%d", &N);
    for(int i=0;i<N;i++)
    {
        board[i]=-1;
    }
    if(nQs(0))
    {

        printf("Got a place for %d QUEENS:\n",N);
        Soln();
    }
    else{
        printf("Can't place %d, Queens\n",N);
    }
    return 0;
}
