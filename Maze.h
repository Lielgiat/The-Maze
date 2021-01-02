#pragma once
#include <iostream>
#include <time.h>   
#include <math.h>
#include <stdlib.h>   

using namespace std;

class Maze
{
private:
	const int _r = 13;// Rows
	const int _c = 13;// Columns
	char** _maze;

public:
	// Getter
	char** getMaze() const { return _maze; }

	// Functions
	bool cantMove(const int y, const int x) const;
	bool roomCheck(const int y, const int x) const;
	bool outOfFrame1(const int y, const int x) const;
	bool outOfFrame2(const int y, const int x) const;

	void randMazes(const int mazeRand);
	void maze1();
	void doorsMaze1();
	void maze2();
	void doorsMaze2();
	void maze3();
	void doorsMaze3();
	void maze4();
	void doorsMaze4();
	void maze5();
	void doorsMaze5();
	void treasures();
	void computer();
	void computer2();
	void player();
	void playerHelp(const int y, const int x);

	const int computerStep();
	const int computerStep2();
	const int playerStep();
	const char playerMenu() const;
	const double treasureDistance1(const int y, const int x) const;
	const double treasureDistance2(const int y, const int x) const;

	// Print the maze
	friend ostream& operator<<(ostream& out, const Maze& other);

	// Constructor
	Maze();

	// Disructor
	~Maze();
};

