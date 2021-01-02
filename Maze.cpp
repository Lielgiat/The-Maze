#include "Maze.h"

// Get the location of the player and check if the player can't move, if all the rooms around him is taken,
// this happends when there is only walls and/or other players around him and block him,
// if he can't move - the function will return true (can't move).
bool Maze::cantMove(const int y, const int x) const
{// Down
	if ((this->_maze[y + 1][x] == '_') || ((this->_maze[y + 1][x] == 18) && ((this->_maze[y + 2][x] == 1) || (this->_maze[y + 2][x] == 2))))
	{// Up
		if ((this->_maze[y - 1][x] == '_') || ((this->_maze[y - 1][x] == 18) && ((this->_maze[y - 2][x] == 1) || (this->_maze[y - 2][x] == 2))))
		{// Right
			if ((this->_maze[y][x + 1] == '|') || ((this->_maze[y][x + 1] == 29) && ((this->_maze[y][x + 2] == 1) || (this->_maze[y][x + 2] == 2))))
			{// Left
				if ((this->_maze[y][x - 1] == '|') || ((this->_maze[y][x - 1] == 29) && ((this->_maze[y][x - 2] == 1) || (this->_maze[y][x - 2] == 2))))
				{
					return true;
				}
			}
		}
	}
	return false;
}
// Get the location of the random treasure and check if the room is inside the maze and if the room is empty,
// if all good - the function will return false.
bool Maze::roomCheck(const int y, const int x) const
{// The x,y of the rooms are even
	if ((x % 2 != 0) || (y % 2 != 0)
		|| (this->_maze[y][x] != ' ')
		|| (this->_maze[y][x - 1] == ' ')
		|| (this->_maze[y][x + 1] == ' ')
		|| (this->_maze[y - 1][x] == ' ')
		|| (this->_maze[y + 1][x] == ' '))
	{
		return true;
	}
	return false;
}
// Get the location of the player and check if the player went out of the frame of the maze (up or down)
// if he isn't inside the maze - the function will return frue.
bool Maze::outOfFrame1(const int y, const int x) const
{// No walls or doors
	if ((this->_maze[y][x + 1] == ' ') || (this->_maze[y][x - 1] == ' '))
	{
		return true;
	}
	return false;
}
// Get the location of the player and check if the player went out of the frame of the maze (right or left)
// if he isn't inside the maze - the function will return frue.
bool Maze::outOfFrame2(const int y, const int x) const
{// No walls or doors
	if ((this->_maze[y + 1][x] == ' ') || (this->_maze[y - 1][x] == ' '))
	{
		return true;
	}
	return false;
}
// Get the random choose of the maze from the constructor and then call the right function that will draw 
// the maze (no return).
void Maze::randMazes(const int mazeRand)
{
	if (mazeRand == 1)
	{
		maze1();
	}
	else if (mazeRand == 2)
	{
		maze2();
	}
	else if (mazeRand == 3)
	{
		maze3();
	}
	else if (mazeRand == 4)
	{
		maze4();
	}
	else if (mazeRand == 5)
	{
		maze5();
	}
}
// This is type number 1 of the maze, this function will draw all the walls of maze number 1 
// (don't get anything or return).
void Maze::maze1()
{
	for (int i = 1; i < _r + 1; i++)//Draws all the walls that are lying down
	{
		if ((i == 1) || (i == 13))
		{
				this->_maze[i][4] = '_';
		}
		else if ((i == 3) || (i == 9) || (i == 11))
		{
			for (int j = 4; j < _c + 1; j++)
			{
				this->_maze[i][j] = '_';
				j++;
			}
		}
		else if ((i == 5) || (i == 7))
		{
			for (int j = 2; j < _c + 1; j++)
			{
				this->_maze[i][j] = '_';
				j++;
			}
		}
	}
	for (int i = 1; i < _r + 1; i++)// Draws all the walls that are standing
	{
		if ((i == 2) || (i == 12))
		{
			for (int j = 3; j < 6; j++)
			{
				this->_maze[i][j] = '|';
				j++;
			}
		}
		else if ((i == 4) || (i == 6) || (i == 8) || (i == 10))
		{
			for (int j = 3; j < _c + 1; j++)
			{
				this->_maze[i][j] = '|';
				j++;
			}
			if (i == 6)
			{
				this->_maze[i][1] = '|';
			}
		}
	}
	doorsMaze1(); // The function that will add all the doors
}
// This function will draw all the doors that fit to maze number 1 
// (don't get anything or return).
void Maze::doorsMaze1()
{//18 arrows up and down 
//29  arrows right and left
	this->_maze[3][4] = 18;
	this->_maze[3][8] = 18;
	this->_maze[4][5] = 29;
	this->_maze[4][9] = 29;
	this->_maze[4][11] = 29;
	this->_maze[5][6] = 18;
	this->_maze[5][12] = 18;
	this->_maze[6][3] = 29;
	this->_maze[6][5] = 29;
	this->_maze[6][7] = 29;
	this->_maze[6][9] = 29;
	this->_maze[7][8] = 18;
	this->_maze[7][10] = 18;
	this->_maze[7][12] = 18;
	this->_maze[8][5] = 29;
	this->_maze[8][13] = 29;
	this->_maze[9][4] = 18;
	this->_maze[9][6] = 18;
	this->_maze[9][10] = 18;
	this->_maze[9][12] = 18;
	this->_maze[10][7] = 29;
	this->_maze[10][9] = 29;
	this->_maze[10][11] = 29;
	this->_maze[11][4] = 18;
}
// This is type number 2 of the maze, this function will draw all the walls of maze number 2 
// (don't get anything or return).
void Maze::maze2()
{
	for (int i = 1; i < _r + 1; i++)//Draws all the walls that are lying down
	{
		if ((i == 1) || (i == 13))
		{
			this->_maze[i][4] = '_';
		}
		else if ((i == 3) || (i == 9) || (i == 11))
		{
			for (int j = 4; j < _c + 1; j++)
			{
				this->_maze[i][j] = '_';
				j++;
			}
		}
		else if ((i == 5) || (i == 7))
		{
			for (int j = 2; j < _c + 1; j++)
			{
				this->_maze[i][j] = '_';
				j++;
			}
		}
	}
	for (int i = 1; i < _r + 1; i++)//Draws all the walls that are standing
	{
		if ((i == 2) || (i == 12))
		{
			for (int j = 3; j < 6; j++)
			{
				this->_maze[i][j] = '|';
				j++;
			}
		}
		else if ((i == 4) || (i == 6) || (i == 8) || (i == 10))
		{
			for (int j = 3; j < _c + 1; j++)
			{
				this->_maze[i][j] = '|';
				j++;
			}
			if (i == 6)
			{
				this->_maze[i][1] = '|';
			}
		}
	}
	doorsMaze2();// The function that will add all the doors
}
// This function will draw all the doors that fit to maze number 2 
// (don't get anything or return).
void Maze::doorsMaze2()
{//18 arrows up and down 
//29  arrows right and left
	this->_maze[3][4] = 18;
	this->_maze[3][12] = 18;
	this->_maze[4][5] = 29;
	this->_maze[4][7] = 29;
	this->_maze[4][9] = 29;
	this->_maze[4][11] = 29;	
	this->_maze[5][12] = 18;	
	this->_maze[6][3] = 29;
	this->_maze[6][5] = 29;
	this->_maze[6][7] = 29;
	this->_maze[6][9] = 29;
	this->_maze[6][11] = 29;	
	this->_maze[7][12] = 18;	
	this->_maze[8][5] = 29;
	this->_maze[8][7] = 29;
	this->_maze[8][9] = 29;
	this->_maze[8][11] = 29;	
	this->_maze[9][4] = 18;
	this->_maze[9][6] = 18;
	this->_maze[9][8] = 18;
	this->_maze[9][10] = 18;
	this->_maze[9][12] = 18;
	this->_maze[10][3] = 29;
	this->_maze[11][4] = 18;
	this->_maze[11][10] = 18;
}
// This is type number 3 of the maze, this function will draw all the walls of maze number 3 
// (don't get anything or return).
void Maze::maze3()
{
	for (int i = 1; i < _r + 1; i++)//Draws all the walls that are lying down
	{
		if ((i == 1) || (i == 13))
		{
			this->_maze[i][4] = '_';
		}
		else if ((i == 3) || (i == 9) || (i == 11))
		{
			for (int j = 4; j < _c + 1; j++)
			{
				this->_maze[i][j] = '_';
				j++;
			}
		}
		else if ((i == 5) || (i == 7))
		{
			for (int j = 2; j < _c + 1; j++)
			{
				this->_maze[i][j] = '_';
				j++;
			}
		}
	}
	for (int i = 1; i < _r + 1; i++)//Draws all the walls that are standing
	{
		if ((i == 2) || (i == 12))
		{
			for (int j = 3; j < 6; j++)
			{
				this->_maze[i][j] = '|';
				j++;
			}
		}
		else if ((i == 4) || (i == 6) || (i == 8) || (i == 10))
		{
			for (int j = 3; j < _c + 1; j++)
			{
				this->_maze[i][j] = '|';
				j++;
			}
			if (i == 6)
			{
				this->_maze[i][1] = '|';
			}
		}
	}
	doorsMaze3(); // The function that will add all the doors
}
// This function will draw all the doors that fit to maze number 3 
// (don't get anything or return).
void Maze::doorsMaze3()
{//18 arrows up and down 
//29  arrows right and left
	this->_maze[3][4] = 18;
	this->_maze[3][12] = 18;
	this->_maze[4][5] = 29;
	this->_maze[4][9] = 29;
	this->_maze[5][4] = 18;
	this->_maze[5][6] = 18;
	this->_maze[5][8] = 18;
	this->_maze[5][10] = 18;
	this->_maze[5][12] = 18;
	this->_maze[6][3] = 29;
	this->_maze[6][7] = 29;
	this->_maze[6][11] = 29;
	this->_maze[7][4] = 18;
	this->_maze[7][8] = 18;
	this->_maze[8][7] = 29;
	this->_maze[8][11] = 29;
	this->_maze[8][13] = 29;
	this->_maze[9][6] = 18;
	this->_maze[9][8] = 18;
	this->_maze[9][10] = 18;
	this->_maze[9][12] = 18;
	this->_maze[10][5] = 29;
	this->_maze[10][9] = 29;
	this->_maze[11][4] = 18;
}
// This is type number 4 of the maze, this function will draw all the walls of maze number 4 
// (don't get anything or return).
void Maze::maze4()
{
	for (int i = 1; i < _r + 1; i++)//Draws all the walls that are lying down
	{
		if ((i == 1) || (i == 11) || (i == 13))
		{
			this->_maze[i][4] = '_';
			if (i == 11)
				this->_maze[i][10] = '_';
		}
		if ((i == 3) || (i == 9))
		{
			for (int j = 4; j < _c - 1; j++)
			{
				this->_maze[i][j] = '_';
				j++;
			}
			if (i == 9)
				this->_maze[i][12] = '_';
		}
		if ((i == 5) || (i == 7))
		{
			for (int j = 2; j < _c - 1; j++)
			{
				this->_maze[i][j] = '_';
				j++;
			}
			if (i == 7)
				this->_maze[i][12] = '_';
		}
	}
	for (int i = 1; i < _r + 1; i++)//Draws all the walls that are standing
	{
		if ((i == 2) || (i == 12))
		{
			for (int j = 3; j < 6; j++)
			{
				this->_maze[i][j] = '|';
				j++;
			}
		}
		if ((i == 4) || (i == 6) || (i == 8))
		{
			for (int j = 3; j < _c - 1; j++)
			{
				this->_maze[i][j] = '|';
				j++;
			}
			if (i == 6)
				this->_maze[i][1] = '|';
			if (i == 8)
				this->_maze[i][13] = '|';
		}
		if (i == 10)
		{
			for (int j = 3; j < 6; j++)
			{
				this->_maze[i][j] = '|';
				j++;
			}
			for (int j = 9; j < 12; j++)
			{
				this->_maze[i][j] = '|';
				j++;
			}
		}
	}
	doorsMaze4();// The function that will add all the doors
}
// This function will draw all the doors that fit to maze number 4 
// (don't get anything or return).
void Maze::doorsMaze4()
{//18 arrows up and down 
//29  arrows right and left
	this->_maze[3][4] = 18;
	this->_maze[4][7] = 29;
	this->_maze[4][9] = 29;	
	this->_maze[5][4] = 18;
	this->_maze[5][6] = 18;
	this->_maze[5][10] = 18;
	this->_maze[6][3] = 29;
	this->_maze[6][7] = 29;
	this->_maze[7][4] = 18;
	this->_maze[7][10] = 18;
	this->_maze[8][5] = 29;
	this->_maze[8][7] = 29;
	this->_maze[8][9] = 29;
	this->_maze[8][11] = 29;
	this->_maze[8][13] = 29;
	this->_maze[9][4] = 18;
	this->_maze[9][10] = 18;
	this->_maze[11][4] = 18;
}
// This is type number 5 of the maze, this function will draw all the walls of maze number 5 
// (don't get anything or return).
void Maze::maze5()
{
	for (int i = 1; i < _r + 1; i++)//Draws all the walls that are lying down
	{
		if ((i == 1) || (i == 11) || (i == 13))
		{
			this->_maze[i][4] = '_';
			if (i == 11)
				this->_maze[i][10] = '_';
		}
		if ((i == 3) || (i == 9))
		{
			for (int j = 4; j < _c - 1; j++)
			{
				this->_maze[i][j] = '_';
				j++;
			}
			if (i == 9)
				this->_maze[i][12] = '_';
		}
		if ((i == 5) || (i == 7))
		{
			for (int j = 2; j < _c - 1; j++)
			{
				this->_maze[i][j] = '_';
				j++;
			}
			if (i == 7)
				this->_maze[i][12] = '_';
		}
	}
	for (int i = 1; i < _r + 1; i++)//Draws all the walls that are standing
	{
		if ((i == 2) || (i == 12))
		{
			for (int j = 3; j < 6; j++)
			{
				this->_maze[i][j] = '|';
				j++;
			}
		}
		if ((i == 4) || (i == 6) || (i == 8))
		{
			for (int j = 3; j < _c - 1; j++)
			{
				this->_maze[i][j] = '|';
				j++;
			}
			if (i == 6)
				this->_maze[i][1] = '|';
			if (i == 8)
				this->_maze[i][13] = '|';
		}
		if (i == 10)
		{
			for (int j = 3; j < 6; j++)
			{
				this->_maze[i][j] = '|';
				j++;
			}
			for (int j = 9; j < 12; j++)
			{
				this->_maze[i][j] = '|';
				j++;
			}
		}
	}
	doorsMaze5();// The function that will add all the doors
}
// This function will draw all the doors that fit to maze number 5 
// (don't get anything or return).
void Maze::doorsMaze5()
{//18 arrows up and down 
//29  arrows right and left
	this->_maze[3][4] = 18;
	this->_maze[4][5] = 29;
	this->_maze[4][7] = 29;
	this->_maze[4][9] = 29;
	this->_maze[5][6] = 18;
	this->_maze[5][10] = 18;
	this->_maze[6][3] = 29;
	this->_maze[6][5] = 29;
	this->_maze[6][7] = 29;
	this->_maze[6][9] = 29;
	this->_maze[7][6] = 18;
	this->_maze[7][10] = 18;
	this->_maze[8][3] = 29;
	this->_maze[8][5] = 29;
	this->_maze[8][7] = 29;
	this->_maze[8][9] = 29;
	this->_maze[8][11] = 29;
	this->_maze[9][4] = 18;
	this->_maze[9][10] = 18;
	this->_maze[11][4] = 18;
	this->_maze[11][10] = 18;
}
// The function randomly selected the locations of the treasures and put them there 
// (don't get anything or return). 
void Maze::treasures()
{
	const char firstTreasure = 57;// The value of the first treasure
	const char secondTreasure = 52;// The value of the second treasure
	int firstLocationX = rand() % 12 + 2;
	int firstLocationY = rand() % 12 + 2;
	int secondLocationX = rand() % 12 + 2;
	int secondLocationY = rand() % 12 + 2;
	// Check if the random locatoin of the treasure is inside room and there is no player there
	while (roomCheck(firstLocationY, firstLocationX))
	{
		firstLocationX = rand() % 12 + 2;
		firstLocationY = rand() % 12 + 2;
	}
	this->_maze[firstLocationY][firstLocationX] = firstTreasure;

	while (roomCheck(secondLocationY, secondLocationX))
	{
		secondLocationX = rand() % 12 + 2;
		secondLocationY = rand() % 12 + 2;
	}
	this->_maze[secondLocationY][secondLocationX] = secondTreasure;
}
// Put the player of the computer inside the maze and also his door 
// (don't get anything or return).
void Maze::computer()
{
	this->_maze[13][4] = 18;
	this->_maze[12][4] = 1;
}
// Put the player number 2 of the computer inside the maze and also his door 
// (don't get anything or return).
void Maze::computer2()
{
	this->_maze[1][4] = 18;
	this->_maze[2][4] = 2;
}
// Put the player inside the maze and also his door 
// (don't get anything or return).
void Maze::player()
{
	this->_maze[6][1] = 29;
	this->_maze[6][2] = 2;
}
// Get the location of the player and if the player will choose in his turn to get help - 
// the system will call this function and show him the sub menu, so the player will 
// be able to choose which help he want and then get that help (no return).
void Maze::playerHelp(const int y, const int x)
{
	int help;
	double a, b;
	do
	{
		cout << "***********************************************************************" << endl;
		cout << "Which help do you prefer?" << endl << "Press 1 to get the distance for the closest treasure" << endl
			<< "Press 2 to revealed the value that inside the room that above you" << endl
			<< "Press 3 to reveal the value inside the room below you" << endl
			<< "Press 4 to reveal the value inside the room on your right" << endl
			<< "Press 5 to reveal the value inside the room on your left" << endl;
		cout << "***********************************************************************" << endl;
		cin >> help;
		switch (help)
		{
		case 1: // The distance to the closest treasure
		{
			a = treasureDistance1(y, x);// The distance of the first treasure
			b = treasureDistance2(y, x);// The distance of the second treasure
			if (a < b)
			{
				cout << "The distance to the closest treasure is: " << a << "." << endl;
			}
			else
			{
				cout << "The distance to the closest treasure is: " << b << "." << endl;
			}
			return;
		}
		case 2: // Up
		{
			if (this->_maze[y - 2][x] == ' ')
				cout << "There is nothing there.." << endl;
			else if (this->_maze[y - 2][x] == 1)
				cout << "There is another player there!" << endl;
			else
				cout << this->_maze[y - 2][x] << endl;
			return;
		}
		case 3: // Down
		{
			if (this->_maze[y + 2][x] == ' ')
				cout << "There is nothing there.." << endl;
			else if (this->_maze[y + 2][x] == 1)
				cout << "There is another player there!" << endl;
			else
				cout << this->_maze[y + 2][x] << endl;
			return;
		}
		case 4: // Right
		{
			if (this->_maze[y][x + 2] == ' ')
				cout << "There is nothing there.." << endl;
			else if (this->_maze[y][x + 2] == 1)
				cout << "There is another player there!" << endl;
			else
				cout << this->_maze[y][x + 2] << endl;
			return;
		}
		case 5: // Left
		{
			if (this->_maze[y][x - 2] == ' ')
				cout << "There is nothing there.." << endl;
			else if (this->_maze[y][x - 2] == 1)
				cout << "There is another player there!" << endl;
			else
				cout << this->_maze[y][x - 2] << endl;
			return;
		}
		default:
			cout << "There is no option " << help << "." << endl;
		}
	} while (help != 1555);// (1555) Rare Code for developers who want to get out this loop 
}
// The main function for the moves of the player of the computer number 1, search his location
// and then randomly choose where this player will go, after the choosen - the function will 
// check if the random choose is good or not and if he needed to choose again, don't get
// anything but will return the choose to the main.
const int Maze::computerStep()
{
	int locationY = 0, locationX = 0;
	int step = rand() % 4 + 1;
	for (int i = 1; i < _r + 1; i++)// Gives the updated location of the player of the computer number 1
	{
		for (int j = 1; j < _c + 1; j++)
		{
			if (this->_maze[i][j] == 1) 
			{
				locationY = i;
				locationX = j;
			}
		}
	}
	if (cantMove(locationY, locationX))// check if this player stuck
	{
		cout << "Bad luck! computer 1 can't move this time.." << endl;
		return 2;
	}
	if (step == 1) // Up
	{// No door or players in the room that he want to move to
		if ((this->_maze[locationY - 1][locationX] == 18) && (this->_maze[locationY - 2][locationX] != 2))
		{
			if (this->_maze[locationY - 2][locationX] == 52)// The treasure
			{
				return 3;
			}
			if (this->_maze[locationY - 2][locationX] == 57)// The treasure
			{
				return 4;
			}
			this->_maze[locationY - 2][locationX] = 1;
			this->_maze[locationY][locationX] = ' ';
			if (outOfFrame1(locationY - 2, locationX))// Out of the maze
			{
				cout << "Oh no! Computer 1 go out of the maze!" << endl << "No more moves in this round for Computer 1." << endl;
				return 1;
			}
			return 0;
		}
		else
		{// Bad choose
			return computerStep();
		}
	}
	if (step == 2)// Down
	{
		if ((this->_maze[locationY + 1][locationX] == 18) && (this->_maze[locationY + 2][locationX] != 2))
		{
			if (this->_maze[locationY + 2][locationX] == 52 )
			{
				return 3;
			}
			if (this->_maze[locationY + 2][locationX] == 57)
			{
				return 4;
			}
			this->_maze[locationY + 2][locationX] = 1;
			this->_maze[locationY][locationX] = ' ';
			if (outOfFrame1(locationY + 2, locationX))
			{
				cout << "Oh no! Computer 1 go out of the maze!" << endl << "No more moves in this round for Computer 1." << endl;
				return 1;
			}
			return 0;
		}
		else
		{
			return computerStep();
		}
	}
	if (step == 3)// Right
	{
		if ((this->_maze[locationY][locationX + 1] == 29) && (this->_maze[locationY][locationX + 2] != 2))
		{
			if (this->_maze[locationY][locationX + 2] == 52)
			{
				return 3;
			}
			if (this->_maze[locationY][locationX + 2] == 57)
			{
				return 4;
			}
			this->_maze[locationY][locationX + 2] = 1;
			this->_maze[locationY][locationX] = ' ';
			if (outOfFrame2(locationY, locationX + 2))
			{
				cout << "Oh no! Computer 1 go out of the maze!" << endl << "No more moves in this round for Computer 1." << endl;
				return 1;
			}
			return 0;
		}
		else
		{
			return computerStep();
		}
	}
	if (step == 4)// Left
	{
		if ((this->_maze[locationY][locationX - 1] == 29) && (this->_maze[locationY][locationX - 2] != 2))
		{
			if (this->_maze[locationY][locationX - 2] == 52)
			{
				return 3;
			}
			if (this->_maze[locationY][locationX - 2] == 57)
			{
				return 4;
			}
			this->_maze[locationY][locationX - 2] = 1;
			this->_maze[locationY][locationX] = ' ';
			if (outOfFrame2(locationY, locationX - 2))
			{
				cout << "Oh no! Computer 1 go out of the maze!" << endl << "No more moves in this round for Computer 1." << endl;
				return 1;
			}
			return 0;
		}
		else
		{
			return computerStep();
		}
	}
	else
		return 9;// There is a warning so all the paths will return a value, 
	// although the random step is between 1-4.
}
// The main function for the moves of the player of the computer number 2, search his location
// and then randomly choose where this player will go, after the choosen - the function will 
// check if the random choose is good or not and if he needed to choose again, don't get
// anything but will return the choose to the main.
const int Maze::computerStep2()
{
	int locationY = 0, locationX = 0;
	int step = rand() % 4 + 1;
	for (int i = 1; i < _r + 1; i++)// Gives the updated location of the player of the computer number 2
	{
		for (int j = 1; j < _c + 1; j++)
		{
			if (this->_maze[i][j] == 2)
			{
				locationY = i;
				locationX = j;
			}
		}
	}
	if (cantMove(locationY, locationX))
	{
		cout << "Bad luck! Computer 2 can't move this time.." << endl;
		return 2;
	}
	if (step == 1) // Up
	{
		if ((this->_maze[locationY - 1][locationX] == 18) && (this->_maze[locationY - 2][locationX] != 1))
		{
			if (this->_maze[locationY - 2][locationX] == 52)
			{
				return 3;
			}
			if (this->_maze[locationY - 2][locationX] == 57)
			{
				return 4;
			}
			this->_maze[locationY - 2][locationX] = 2;
			this->_maze[locationY][locationX] = ' ';
			if (outOfFrame1(locationY - 2, locationX))
			{
				cout << "Oh no! Computer 2 go out of the maze!" << endl << "No more moves in this round for Computer 2." << endl;
				return 1;
			}
			return 0;
		}
		else
		{
			return computerStep2();
		}
	}
	if (step == 2)// Down
	{
		if ((this->_maze[locationY + 1][locationX] == 18) && (this->_maze[locationY + 2][locationX] != 1))
		{
			if (this->_maze[locationY + 2][locationX] == 52)
			{
				return 3;
			}
			if (this->_maze[locationY + 2][locationX] == 57)
			{
				return 4;
			}
			this->_maze[locationY + 2][locationX] = 2;
			this->_maze[locationY][locationX] = ' ';
			if (outOfFrame1(locationY + 2, locationX))
			{
				cout << "Oh no! Computer 2 go out of the maze!" << endl << "No more moves in this round for Computer 2." << endl;
				return 1;
			}
			return 0;
		}
		else
		{
			return computerStep2();
		}
	}
	if (step == 3)// Right
	{
		if ((this->_maze[locationY][locationX + 1] == 29) && (this->_maze[locationY][locationX + 2] != 1))
		{
			if (this->_maze[locationY][locationX + 2] == 52)
			{
				return 3;
			}
			if (this->_maze[locationY][locationX + 2] == 57)
			{
				return 4;
			}
			this->_maze[locationY][locationX + 2] = 2;
			this->_maze[locationY][locationX] = ' ';
			if (outOfFrame2(locationY, locationX + 2))
			{
				cout << "Oh no! Computer 2 go out of the maze!" << endl << "No more moves in this round for Computer 2." << endl;
				return 1;
			}
			return 0;
		}
		else
		{
			return computerStep2();
		}
	}
	if (step == 4)// Left
	{
		if ((this->_maze[locationY][locationX - 1] == 29) && (this->_maze[locationY][locationX - 2] != 1))
		{
			if (this->_maze[locationY][locationX - 2] == 52)
			{
				return 3;
			}
			if (this->_maze[locationY][locationX - 2] == 57)
			{
				return 4;
			}
			this->_maze[locationY][locationX - 2] = 2;
			this->_maze[locationY][locationX] = ' ';
			if (outOfFrame2(locationY, locationX - 2))
			{
				cout << "Oh no! Computer 2 go out of the maze!" << endl << "No more moves in this round for Computer 2." << endl;
				return 1;
			}
			return 0;
		}
		else
		{
			return computerStep2();
		}
	}
	else
		return 9;// There is a warning so all the paths will return a value,
	// although the random step is between 1-4.
}
// The main function for the moves of the player, search his location
// and then ask him to choose where to go (or help or stay), after the choosen - the function will 
// check if the choose is good or not and if he needed to choose again, don't get
// anything but will return the choose to the main.
const int Maze::playerStep()
{
	int locationY = 0, locationX = 0;
	char step;
	step = playerMenu();// Call the function that will print the menu
	for (int i = 1; i < _r + 1; i++)// Gives the updated location of the player
	{
		for (int j = 1; j < _c + 1; j++)
		{
			if (this->_maze[i][j] == 2)
			{
				locationY = i;
				locationX = j;
			}
		}
	}
	if ((step == 'U') || (step == 'u')) // If the player choose up
	{// No door or other players in the room he want to move to
		if ((this->_maze[locationY - 1][locationX] == 18) && (this->_maze[locationY - 2][locationX] != 1))
		{
			if (this->_maze[locationY - 2][locationX] == 52)// The treasure
			{
				return 3;
			}
			if (this->_maze[locationY - 2][locationX] == 57)// The treasure
			{
				return 4;
			}
			this->_maze[locationY - 2][locationX] = 2;
			this->_maze[locationY][locationX] = ' ';
			if (outOfFrame1(locationY - 2, locationX))// If he go out of the maze
			{
				cout << "Oh no! You go out of the maze!" << endl << "No more moves in this round for you." << endl;
				return 1;
			}
			else
				return 0;
		}
		else
		{
			cout << "BAGA! You can't do that right now." << endl << "Choose again" << endl;
			return playerStep();
		}
	}
	else if ((step == 'D') || (step == 'd'))// If the player choose down
	{
		if ((this->_maze[locationY + 1][locationX] == 18) && (this->_maze[locationY + 2][locationX] != 1))
		{
			if (this->_maze[locationY + 2][locationX] == 52)
			{
				return 3;
			}
			if (this->_maze[locationY + 2][locationX] == 57)
			{
				return 4;
			}
			this->_maze[locationY + 2][locationX] = 2;
			this->_maze[locationY][locationX] = ' ';
			if (outOfFrame1(locationY + 2, locationX))
			{
				cout << "Oh no! You go out of the maze!" << endl << "No more moves in this round for you." << endl;
				return 1;
			}
			else
				return 0;
		}
		else
		{
			cout << "BAGA! You can't do that right now." << endl << "Choose again" << endl;
			return playerStep();
		}
	}
	else if ((step == 'R') || (step == 'r'))// If the player choose right
	{
		if ((this->_maze[locationY][locationX + 1] == 29) && (this->_maze[locationY][locationX + 2] != 1))
		{
			if (this->_maze[locationY][locationX + 2] == 52)
			{
				return 3;
			}
			if (this->_maze[locationY][locationX + 2] == 57)
			{
				return 4;
			}
			this->_maze[locationY][locationX + 2] = 2;
			this->_maze[locationY][locationX] = ' ';
			if (outOfFrame2(locationY, locationX + 2))
			{
				cout << "Oh no! You go out of the maze!" << endl << "No more moves in this round for you." << endl;
				return 1;
			}
			else
				return 0;
		}
		else
		{
			cout << "BAGA! You can't do that right now." << endl << "Choose again" << endl;
			return playerStep();
		}
	}
	else if ((step == 'L') || (step == 'l'))// If the player choose left
	{
		if ((this->_maze[locationY][locationX - 1] == 29) && (this->_maze[locationY][locationX - 2] != 1))
		{
			if (this->_maze[locationY][locationX - 2] == 52)
			{
				return 3;
			}
			if (this->_maze[locationY][locationX - 2] == 57)
			{
				return 4;
			}
			this->_maze[locationY][locationX - 2] = 2;
			this->_maze[locationY][locationX] = ' ';
			if (outOfFrame2(locationY, locationX - 2))
			{
				cout << "Oh no! You go out of the maze!" << endl << "No more moves in this round for you." << endl;
				return 1;
			}
			else
				return 0;
		}
		else
		{
			cout << "BAGA! You can't do that right now." << endl << "Choose again" << endl;
			return playerStep();
		}
	}
	else if ((step == 'S') || (step == 's'))// If the player choose to stay in his place
	{
		return 6;
	}
	else if ((step == 'H') || (step == 'h'))// If the player choose to use help
	{
		playerHelp(locationY, locationX);
		return 5;
	}
	else if ((step == 'E') || (step == 'e'))// If the player choose to quit this round
	{
		cout << "(Loser..)" << endl;
		return 2;
	}
	else
		return 9;// There is a warning so all the paths will return a value,
	// although the random step is between 1-4.
}
// The function will print all the menu for the player to choose what he want,
// don't get anything, but ask from the player for his choose and then will 
// return this choose.
const char Maze::playerMenu() const
{
	char choice;
	do
	{
		cout << "***********************************************************************" << endl;
		cout << "Press U to move up" << endl << "Press D to move down" << endl << "Press R to move right"
			<< endl << "Press L to move left" << endl << "Press S to stay in the same place" << endl
			<< "Press H for help" << endl << "Press E to exit this round" << endl;
		cout << "***********************************************************************" << endl;
		cin >> choice;
		switch (choice)
		{
			case 'U':
			{
				return choice;
			}
			case 'u':
			{
				return choice;
			}
			case 'D':
			{
				return choice;
			}
			case 'd':
			{
				return choice;
			}
			case 'R':
			{
				return choice;
			}
			case 'r':
			{
				return choice;
			}
			case 'L':
			{
				return choice;
			}
			case 'l':
			{
				return choice;
			}
			case 'S':
			{
				return choice;
			}
			case 's':
			{
				return choice;
			}
			case 'H':
			{
				return choice;
			}
			case 'h':
			{
				return choice;
			}
			case 'E':
			{
				return choice;
			}
			case 'e':
			{
				return choice;
			}
			default:
				cout << "There is no option " << choice << "." << endl << "Try again" << endl;
		}
	} while (choice != 1555); //(1555) Rare Code for developers who want to get out this loop
	return 'E';
}
// Get the location of the player, then search the first treasure with 
// Pythagoras formula (a^2 + b^2 = c^2) and after this the function
// will return the distance.
const double Maze::treasureDistance1(const int y, const int x) const
{
	double a, b, c, treasureY = 0, treasureX = 0;
	for (int i = 1; i < _r + 1; i++)// Gives the updated location of the first treasure
	{
		for (int j = 1; j < _c + 1; j++)
		{
			if (this->_maze[i][j] == 57)
			{
				treasureY = i;
				treasureX = j;
			}
		}
	}
	a = y - treasureY;// The distance from the player
	b = x - treasureX;
	if (a == 0)
	{
		if (b < 0)
		{
			b = b * (-1);
		}
		return b;
	}
	else if (b == 0)
	{
		if (a < 0)
		{
			a = a * (-1);
		}
		return a;
	}
	else
	{
		c = sqrt(pow(a, 2) + pow(b, 2));
		return c;
	}
}
// Get the location of the player, then search the second treasure with 
// Pythagoras formula (a^2 + b^2 = c^2) and after this the function
// will return the distance.
const double Maze::treasureDistance2(const int y, const int x) const
{
	double a, b, c, treasureY = 0, treasureX = 0;
	for (int i = 1; i < _r + 1; i++)// Gives the updated location of the second treasure
	{
		for (int j = 1; j < _c + 1; j++)
		{
			if (this->_maze[i][j] == 52)
			{
				treasureY = i;
				treasureX = j;
			}
		}
	}
	a = y - treasureY;// The distance from the player
	b = x - treasureX;
	if (a == 0)
	{
		if (b < 0)
		{
			b = b * (-1);
		}
		return b;
	}
	else if (b == 0)
	{
		if (a < 0)
		{
			a = a * (-1);
		}
		return a;
	}
	else
	{
		c = sqrt(pow(a, 2) + pow(b, 2));
		return c;
	}
}
// Matrix printing operator that receives a matrix from an ostream object, and prints the matrix (the maze).
// The function will return - ostream out.
ostream& operator<<(ostream& out, const Maze& other)
{
	for (int i = 0; i < other._r + 2; i++)
	{
		for (int j = 0; j < other._c + 2; j++)
		{
			cout << other._maze[i][j] <<" ";
		}
		cout << endl;
	}
	return out;
}
// Default constructor
Maze::Maze()
{
	this->_maze = new char* [_c + 2];// Columns
	for ( int i = 0 ; i < _r +2 ; i++ )
	{
		this->_maze[i] = new char[_r + 2];// Rows
	}
	for (int i = 0; i < _r + 2; i++)
	{
		for (int j = 0; j < _c + 2; j++)// Initialize the maze.
		{
			this->_maze[i][j] = ' ';
		}
	}
	int mazeRand = rand() % 5 + 1;// Random choose of the maze
	randMazes(mazeRand);
}

// Disructor
Maze::~Maze()
{
	for (int i = 0; i < _r + 2; i++)
	{
		delete[] _maze[i];
	}
	delete _maze;
}