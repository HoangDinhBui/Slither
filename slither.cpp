#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
char state[10][20];//Save game state
int H[20];//co-ordinate of snake
int Z[20];//co-ordinate of snake
int h, v;//co-ordinate of food
char ch = 'd';//save the present direction of snake
int len = 3;//length of snake's head
char f;//Save the direction variable
void getFood()
{
    h = rand() % 10;//Create the location of food inside from 0 -> 9
    v = rand() % 20;//Create the location of food inside from 0 -> 19
    if(state[h][v] == 1)//if the location of food is coincides with the location of snake
    {
        getFood();//then relocate the posistion of food
    }
    state[h][v] = 3;//else, this is the posistion
}
