/*
Develop a modular C program to manage a team of 11 cricket players and 
calculate the average runs of the team. Create a structure Player with the following members:
•	player_name
•	jersey_number
•	runs_scored
Create an array of 11 players. Write a program that:
1.	Reads the details of all 11 players.
2.	Calculates and displays the average runs scored by the team.
Function prototype:
void readPlayers(int n, Player p[]);
float calculateAverageRuns(int n, Player p[]);
*/
#include<stdio.h>

typedef struct{
    char player_name[200];
	int jersey_number;
	int runs_scored;
}Player;

void readPlayers(int n, Player p[]);
float calculateAverageRuns(int n, Player p[]);

int main()
{
    int n=11;
    Player p[n];
    readPlayers(n, p);
    float avg_runs = calculateAverageRuns(n,p);
    printf("The average runs scored by team is %.2f ",avg_runs);

    return 0;
}

void readPlayers(int n, Player p[])
{
    for(int i=0;i<n;i++)
    {
    printf("Entre the name of player.\n");
    scanf("%s",p[i].player_name);

    printf("Entre the jersey number of player.\n");
    scanf("%d",&p[i].jersey_number);

    printf("Entre the runs of player.\n");
    scanf("%d",&p[i].runs_scored);

    }
}

float calculateAverageRuns(int n, Player p[])
{
    float sum=0;
    for(int i=0;i<n;i++)
    {
        sum = p[i].runs_scored + sum;
    }
    return (float)(sum/n);
}
