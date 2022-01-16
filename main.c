#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
Elijah Hoover
1-15-22
terminal window RPG
*/

struct playerClass
{
    int xCord;
    int yCord;
    int attack;
    int defense;
    int health;
};
/*
struct enemyClass
{
    char enemyName;
    int xCord;
    int yCord;
    int attack;
    int defense;
    int health;
};
*/
typedef enum
{
    North='w',
    East='d',
    South='s',
    West='a'
}direction;

void testGrid();
char getPlayerInput();
void initializeMapGrid(char grid[9][9]);
void printMap(char grid[9][9], struct playerClass* Character);
void setLocation(char grid[9][9], struct playerClass* Character, direction cardinal);
void movePlayer(char grid[9][9], struct playerClass* Character);
void initializePlayer(struct playerClass* Character);
int main()
{
    //prints a 9x9 grid for the main play area, emulating an overhead view
    //testGrid();

    //initializes player at center of map
    struct playerClass hero;
    //hero.xCord = 4;
    //hero.yCord = 4;
    initializePlayer(&hero);
    //initializes the map
    char mapGrid[9][9];
    initializeMapGrid(mapGrid);
    printMap(mapGrid,&hero);

    //printf("Before Player Input");
    //char cardinalDirection;
    //cardinalDirection = getPlayerInput();
    //printf("After Player Input");
    //setLocation(mapGrid,hero,cardinalDirection);

    //Where the player needs to go for the program to end

    int goalXCord;
    int goalYCord;

    goalXCord=0;
    goalYCord=0;
    while((hero.xCord!=goalXCord) && (hero.yCord != goalYCord))
    {
        movePlayer(mapGrid,&hero);
        printMap(mapGrid, &hero);
    }

    return 0;
}

void testGrid()
{
    //a 9x9 test grid is printed
    for(int screenrow=0;screenrow<9;screenrow++)
        printf("o o o o o o o o o\n");// o's
}
//initializes the map grid and sets all spaces to neutral tiles
void initializeMapGrid(char grid[9][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
            grid[i][j] = 'o';
    }
}
//Prints every grid space, i=y cord, j=x cord
void printMap(char grid[9][9],struct playerClass* Character)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(Character->xCord==j && Character->yCord==i)
            {
                //if the coordinates match, then prints an x for the player
                printf("x ");
                if(j==8)
                    printf("\n");
            }
            else
            {
                if(j!=8)
                    printf("%c ",grid[i][j]);
                else
                    printf("%c\n",grid[i][j]);
            }
        }
    }
}
//calculates where the player will land after inputting a direction
void setLocation(char grid[9][9], struct playerClass* Character, direction cardinal)
{
    if(cardinal==North)
    {
        Character->yCord=Character->yCord-1;
        printf("New Y: %d\n",(Character)->yCord);
    } else if(cardinal==South)
    {
        Character->yCord=Character->yCord+1;
        printf("New Y: %d\n",Character->yCord);
    } else if(cardinal==East)
    {
        Character->xCord=Character->xCord+1;
        printf("New X: %d\n",Character->xCord);
    } else if(cardinal==West)
    {
        Character->xCord=Character->xCord-1;
        printf("New X: %d\n",Character->xCord);
    }
}
//gets players input
char getPlayerInput()
{
    char playerInput;
    scanf(" %c", &playerInput);
    //printf("Inputted:%c\n",playerInput);
    return playerInput;
}

void movePlayer(char grid[9][9], struct playerClass* Character)
{
    char cardinalDirection;
    cardinalDirection = getPlayerInput();
    setLocation(grid,Character,cardinalDirection);
}
void initializePlayer(struct playerClass* Character)
{
    Character->xCord = 4;
    Character->yCord = 4;
    Character->health=5;
    Character->attack=5;
    Character->defense=5;
}
