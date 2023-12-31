#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
char state[10][20];//Save game state
int H[20];//co-ordinate of snake, long = y
int Z[20];//co-ordinate of snake, wide = x
int h, v;//co-ordinate of food
char ch = 'd';//save the present direction of snake
int len = 3;//length of snake's head
char f;//Save the direction variable
//Function of make color
void SET_COLOR(int color)
{
	WORD wColor;
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
}
//Function of appear food on random posistion
void getFood()
{
    h = rand() % 10;//Create the location of food inside from 0 -> 9
    v = rand() % 20;//Create the location of food inside from 0 -> 19
    if(state[h][v] == 1)//if the location of food is coincides with the location of snake
    {
        getFood();//then relocate the posistion of food
    }
	SET_COLOR(10);
    state[h][v] = 'o';//else, this is the posistion
}
//Function of print play state
void printState(int speed)
{
	for(int i = 0; i < len; i++)
	{
		SET_COLOR(14);
		state[H[i]][Z[i]] = '#';//the posistion that the snake has go through is mark by number 1 - is Char of 'start of heading'
	}
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			printf("%c", state[i][j]);
		}
		printf("\n");
	}
	//make move animation for snake
	Sleep(speed); //Pause the program in 0.5s to create late effect between frame
	system("cls");
}
//Function of check to see if any key are available
void getKey()
{
	if(_kbhit())//_khbit() is function of check to see if any key are available
	{
		ch = _getch();//get char is pressed
		if(ch == f)
		{
			getKey();
		}
		else if((ch == 100 && f != 97)||(ch == 97 && ch != 100)||(ch == 115 && ch != 119)||(ch != 115 && ch == 119))
		{
			f = ch;
		}
		else
			getKey();
	}
}
//Fucntion of left direction
void left()
{
	int newHeadX = Z[len - 1] - 1;
    int newHeadY = H[len - 1];
    // Check if the new head position collides with the snake's body
    for (int i = 0; i < len - 1; i++)
    {
        if (newHeadX == Z[i] && newHeadY == H[i])
        {
            SET_COLOR(4);
            printf("You touched the body!\n");
            return;
        }
    }
	state[H[0]][Z[0]] = '-';//assign '-' into snake's head location before move
	for(int i = 0; i < len - 1; i++)//start a loop to move the snake to the left side
	{
		Z[i] = Z[i + 1];
		H[i] = H[i + 1]; 
	}
	Z[len - 1] = newHeadX;//move snake's head into left side
}
//Function of right direction
void right()
{
	int newHeadX = Z[len - 1] + 1;
    int newHeadY = H[len - 1];
    // Check if the new head position collides with the snake's body
    for (int i = 0; i < len - 1; i++)
    {
        if (newHeadX == Z[i] && newHeadY == H[i])
        {
            SET_COLOR(4);
            printf("You touched the body!\n");
            return;
        }
    }
	state[H[0]][Z[0]] = '-';//assign '-' into snake's head location before move
	for(int i = 0; i < len - 1; i++)//start a loop to move the snake to the left side
	{
		Z[i] = Z[i + 1];
		H[i] = H[i + 1]; 
	}
	Z[len - 1] = newHeadX;//move snake's head into right side	
}
//Function of up direction
void up()
{
	int newHeadX = Z[len - 1];
    int newHeadY = H[len - 1] - 1;
    // Check if the new head position collides with the snake's body
    for (int i = 0; i < len - 1; i++)
    {
        if (newHeadX == Z[i] && newHeadY == H[i])
        {
            SET_COLOR(4);
            printf("You touched the body!\n");
            return;
        }
    }
	state[H[0]][Z[0]] = '-';//assign '-' into snake's head location before move
	for(int i = 0; i < len - 1; i++)//start a loop to move the snake to the up side
	{
		Z[i] = Z[i + 1];
		H[i] = H[i + 1]; 
	}
	H[len - 1] = newHeadY;//move snake's head into up side
}
//Function of down direction
void down()
{
	int newHeadX = Z[len - 1];
    int newHeadY = H[len - 1] + 1;
    // Check if the new head position collides with the snake's body
    for (int i = 0; i < len - 1; i++)
    {
        if (newHeadX == Z[i] && newHeadY == H[i])
        {
            SET_COLOR(4);
            printf("You touched the body!\n");
            return;
        }
    }
	state[H[0]][Z[0]] = '-';//assign '-' into snake's head location before move
	for(int i = 0; i < len - 1; i++)//start a loop to move the snake to the down side
	{
		Z[i] = Z[i + 1];
		H[i] = H[i + 1]; 
	}
	H[len - 1] = newHeadY;//move snake's head into down side
}
int main()
{
		int speed;
		printf("Enter the level of difficult: ");
		scanf("%d", &speed);
		if(speed < 100 || speed > 1000)
		{
			SET_COLOR(4);
			printf("The difficult level is not valid!");
			return 0;
		}
		f = ch;//initialization first direction
		for(int i = 0; i < 10; i++)
		{
			for(int j = 0; j < 20; j++)
			{
				state[i][j] = '-';//initialization the play state with '-'
			}
		}
		for(int i = 0; i < 10; i++)//initialization array to save snake location
		{
			Z[i] = 0;
			H[i] = 0;
		}
		for(int i = 0; i < len; i++)//initialization first length and location of snake
			Z[i] = i;
		getFood();
		printf("Enter the point that you want to win: ");
		int point;
		scanf("%d", &point);
		getchar();
		while(len <= point)
		{
			getKey();
			if(state[h][v] != 'o')
			{
				getFood();
			}
			switch(f)
			{
				case 'w':
					if(H[len - 1] - 1 < 0)
					{
						SET_COLOR(4);
						printf("You're touch the wall!\n");
					}
					else if(H[len - 1] - 1 == h && Z[len - 1] == v)//if the snake eat food
					{
						H[len] = h;
						Z[len] = v;
						len++;
						break;
					} 
					up();
					break;
				case 's':
					if(H[len - 1] + 1 >= 10)
					{
						SET_COLOR(4);
						printf("You're touch the wall!\n");
						return 0;
					}
					else if(H[len - 1] + 1 == h && Z[len - 1] == v)//if the snake eat food
					{
						H[len] = h;
						Z[len] = v;
						len++;
						break;
					} 
					down();
					break;
				case 'a':
					if(Z[len - 1] - 1 < 0)
					{
						SET_COLOR(4);
						printf("You're touch the wall!\n");
						return 0;
					}
					else if(H[len - 1] == h && Z[len - 1] - 1 == v)//if the snake eat food
					{
						H[len] = h;
						Z[len] = v;
						len++;
						break;
					} 
					left();
					break;
				case 'd':
					if(Z[len - 1] + 1 >= 20)
					{
						SET_COLOR(4);
						printf("You're touch the wall!\n");
						return 0	;
					}
					else if(H[len - 1] == h && Z[len - 1] + 1== v)//if the snake eat food
					{
						H[len] = h;
						Z[len] = v;
						len++;
						break;
					} 
					right();
					break;
			}
			printState(speed);
		}
		printf("You Win!\n");
		system("Pause");
	return 0;
}