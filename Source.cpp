#include <iostream>
#include <time.h>   
#include <math.h>
#include "Maze.h"


using namespace std;

int main()
{
	int choice, choice2, a = 0, b = 0;
	int playerScore = 0, computerScore = 0, computerScore2 = 0;
	int playerMoves = 0, computerMoves = 0, computerMoves2 = 0;
	char instructions, player = 2, computer = 1, computer2 = 2;
	srand(time(NULL));
	Maze A, B;
	do
	{
		cout << "***********************************************************************" << endl;
		cout << "Press 1 for instructions" << endl << "Press 2 to play" << endl << "Press 3 to check the game" << endl
			<< "Press 0 to exit" << endl;
		cout << "***********************************************************************" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "This is the player or the computer number 2: ";
			instructions = 2;
			cout << instructions << endl;
			cout << "This is the computer number 1: ";
			instructions = 1;
			cout << instructions << endl;
			cout << "This is a DOOR that you can go through it up or down: ";
			instructions = 18;
			cout << instructions << endl;
			cout << "This is a DOOR that you can go through it right or left: ";
			instructions = 29;
			cout << instructions << endl;
			cout << "This is a WALL that you can NOT go through it up or down: ";
			instructions = '_';
			cout << instructions << endl;
			cout << "This is a WALL that you can NOT go through it right or left: ";
			instructions = '|';
			cout << instructions << endl;
			break;
		}
		case 2:
		{
			do
			{
				cout << "***********************************************************************" << endl;
				cout << "Press 1 for Player (" << player <<") VS. Computer (" << computer << ")" << endl
					<< "Press 2 for Computer (" << computer << ") VS. Computer (" << computer2 << ")" << endl
					<< "Press 0 to exit" << endl;
				cout << "***********************************************************************" << endl;
				cin >> choice2;
				switch (choice2)
				{
				case 1:
				{
					cout << "Round 1 - GO!" << endl;
					A.player();
					A.computer();
					A.treasures();
					cout << A << endl;
					a = A.playerStep();
					b = A.computerStep();
					playerMoves++;
					computerMoves++;
					if ((a == 2) || (a == 6))
						playerMoves--;
					cout << A << endl;
					while (((a == 0) && (b == 0)) || ((a == 0) && (b == 1)) || ((a == 1) && (b == 0)) || ((a == 0) && (b == 2))
						|| ((a == 2) && (b == 0)) || ((a == 5) && (b == 0)) || ((a == 6) && (b == 0)) || ((a == 5) && (b == 1))
						|| ((a == 6) && (b == 1)) || ((a == 5) && (b == 2)) || ((a == 6) && (b == 2)))
					{
						playerMoves++;
						computerMoves++;
						if ((a == 1) || (a == 2))// player can't move anymore
						{
							b = A.computerStep();
							playerMoves--;
							if (b == 2)
								computerMoves--;
						}
						else if ((b == 1) || (b == 2))// Computer maybe can't move anymore
						{
							a = A.playerStep();
							computerMoves--;
							if ((a == 2) || (a == 6))
								playerMoves--;
						}
						else if (b == 0)
						{
							a = A.playerStep();
							b = A.computerStep();
							if ((a == 2) || (a == 6))
								playerMoves--;
							if (b == 2)
								computerMoves--;
						}
						cout << A << endl;
					}
					cout << endl << "Round 1 over - ";
					if ((a == 3) || (a == 4))
					{
						cout << "You won this round!" << endl;
						if (a == 3)
						{
							playerScore = 4 - playerMoves;
							computerScore = computerMoves * (-1);

						}
						else
						{
							playerScore = 9 - playerMoves;
							computerScore = computerMoves * (-1);

						}
					}
					else if ((b == 3) || (b == 4))
					{
						cout << "The computer won this round!" << endl;
						if (b == 3)
						{
							playerScore = playerMoves * (-1);
							computerScore = 4 - computerMoves;
						}
						else
						{
							playerScore = playerMoves * (-1);
							computerScore = 9 - computerMoves;
						}
					}
					else if (((a == 1) && (b == 1)) || ((a == 1) && (b == 2)) || ((a == 2) && (b == 1)) || ((a == 2) && (b == 2)))
					{
						cout << "Draw!" << endl;
						playerScore = playerMoves * (-1);
						computerScore = computerMoves * (-1);
					}

					cout << "Round 2 - GO!" << endl;
					playerMoves = 0;
					computerMoves = 0;
					B.player();
					B.computer();
					B.treasures();
					cout << B << endl;
					a = B.playerStep();
					b = B.computerStep();
					playerMoves++;
					computerMoves++;
					if ((a == 2) || (a == 6))
						playerMoves--;
					cout << B << endl;
					while (((a == 0) && (b == 0)) || ((a == 0) && (b == 1)) || ((a == 1) && (b == 0)) || ((a == 0) && (b == 2))
						|| ((a == 2) && (b == 0)) || ((a == 5) && (b == 0)) || ((a == 6) && (b == 0)) || ((a == 5) && (b == 1))
						|| ((a == 6) && (b == 1)) || ((a == 5) && (b == 2)) || ((a == 6) && (b == 2)))
					{
						playerMoves++;
						computerMoves++;
						if ((a == 1) || (a == 2))// player can't move anymore
						{
							b = B.computerStep();
							playerMoves--;
							if (b == 2)
								computerMoves--;
						}
						else if ((b == 1) || (b == 2))// Computer maybe can't move anymore
						{
							a = B.playerStep();
							computerMoves--;
							if ((a == 2) || (a == 6))
								playerMoves--;
						}
						else if (b == 0)
						{
							a = B.playerStep();
							b = B.computerStep();
							if ((a == 2) || (a == 6))
								playerMoves--;
							if (b == 2)
								computerMoves--;
						}
						cout << B << endl;
					}
					cout << endl << "Round 2 over - ";
					if ((a == 3) || (a == 4))
					{
						cout << "You won this round!" << endl;
						if (a == 3)
						{
							playerScore = (4 - playerMoves) + playerScore;
							computerScore = (computerMoves * (-1)) + computerScore;

						}
						else
						{
							playerScore = (9 - playerMoves) + playerScore;
							computerScore = (computerMoves * (-1)) + computerScore;

						}
					}
					else if ((b == 3) || (b == 4))
					{
						cout << "The computer won this round!" << endl;
						if (b == 3)
						{
							playerScore = (playerMoves * (-1)) + playerScore;
							computerScore = (4 - computerMoves) + computerScore;
						}
						else
						{
							playerScore = (playerMoves * (-1)) + playerScore;
							computerScore = (9 - computerMoves) + computerScore;
						}
					}
					else if (((a == 1) && (b == 1)) || ((a == 1) && (b == 2)) || ((a == 2) && (b == 1)) || ((a == 2) && (b == 2)))
					{
						cout << "Draw!" << endl;
						playerScore = (playerMoves * (-1)) + playerScore;
						computerScore = (computerMoves * (-1)) + computerScore;
					}
					if (playerScore > computerScore)
						cout << "You won the game!" << endl;
					else if (playerScore < computerScore)
						cout << "The computer won the game!" << endl;
					else
						cout << "Draw!" << endl;
					cout << endl << "The scores: " << endl << "You: " << playerScore << endl << "The computer: " << computerScore << endl;
					cout << "***********************************************************************" << endl;
					return 0;
				}
				case 2:
				{
					cout << "Round 1 - GO!" << endl;
					A.computer();
					A.computer2();
					A.treasures();
					a = A.computerStep();
					b = A.computerStep2();
					computerMoves++;
					computerMoves2++;
					cout << A << endl;
					while (((a == 0) && (b == 0)) || ((a == 0) && (b == 1)) || ((a == 1) && (b == 0)) || ((a == 0) && (b == 2)) || ((a == 2) && (b == 0)))
					{
						computerMoves++;
						computerMoves2++;
						if ((a == 1) || (a == 2))// Computer can't move anymore
						{
							b = A.computerStep2();
							computerMoves--;
						}
						else if ((b == 1) || (b == 2))// Computer 2 can't move anymore
						{
							a = A.computerStep();
							computerMoves2--;
						}
						else if ((a == 0) && (b == 0))
						{
							a = A.computerStep();
							b = A.computerStep2();
						}
						cout << A << endl;
					}
					cout << endl << "Round 1 over - ";
					if ((a == 3) || (a == 4))
					{
						cout << "Computer 1 won this round!" << endl;
						if (a == 3)
						{
							computerScore = 4 - computerMoves;
							computerScore2 = computerMoves2 * (-1);

						}
						else
						{
							computerScore = 9 - computerMoves;
							computerScore2 = computerMoves2 * (-1);

						}
					}
					if ((b == 3) || (b == 4))
					{
						cout << "Computer 2 won this round!" << endl;
						if (b == 3)
						{
							computerScore = computerMoves * (-1);
							computerScore2 = 4 - computerMoves2;
						}
						else
						{
							computerScore = computerMoves * (-1);
							computerScore2 = 9 - computerMoves2;
						}
					}
					if (((a == 1) && (b == 1)) || ((a == 1) && (b == 2)) || ((a == 2) && (b == 1)) || ((a == 2) && (b == 2)))
					{
						cout << "Draw!" << endl;
						computerScore = computerMoves * (-1);
						computerScore2 = computerMoves2 * (-1);
					}

					cout << "Round 2 - GO!" << endl;
					computerMoves = 0;
					computerMoves2 = 0;
					B.computer();
					B.computer2();
					B.treasures();
					a = B.computerStep();
					b = B.computerStep2();
					computerMoves++;
					computerMoves2++;
					cout << B << endl;
					while (((a == 0) && (b == 0)) || ((a == 0) && (b == 1)) ||
						((a == 1) && (b == 0)) || ((a == 0) && (b == 2)) || ((a == 2) && (b == 0)))
					{
						computerMoves++;
						computerMoves2++;
						if ((a == 1) || (a == 2))// Computer can't move anymore
						{
							b = B.computerStep2();
							computerMoves--;
						}
						else if ((b == 1) || (b == 2))// Computer 2 can't move anymore
						{
							a = B.computerStep();
							computerMoves2--;
						}
						else if ((a == 0) && (b == 0))
						{
							a = B.computerStep();
							b = B.computerStep2();
						}
						cout << B << endl;
					}
					cout << endl << "Round 2 over - ";
					if ((a == 3) || (a == 4))
					{
						cout << "Computer 1 won this round!" << endl;
						if (a == 3)
						{
							computerScore = (4 - computerMoves) + computerScore;
							computerScore2 = (computerMoves2 * (-1)) + computerScore2;

						}
						else
						{
							computerScore = (9 - computerMoves) + computerScore;
							computerScore2 = (computerMoves2 * (-1)) + computerScore2;

						}
					}
					else if ((b == 3) || (b == 4))
					{
						cout << "Computer 2 won this round!" << endl;
						if (b == 3)
						{
							computerScore = (computerMoves * (-1)) + computerScore;
							computerScore2 = (4 - computerMoves2) + computerScore2;
						}
						else
						{
							computerScore = (computerMoves * (-1)) + computerScore;
							computerScore2 = (9 - computerMoves2) + computerScore2;
						}
					}
					else if (((a == 1) && (b == 1)) || ((a == 1) && (b == 2)) || ((a == 2) && (b == 1)) || ((a == 2) && (b == 2)))
					{
						cout << "This is draw!" << endl;
						computerScore = (computerMoves * (-1)) + computerScore;
						computerScore2 = (computerMoves2 * (-1)) + computerScore2;
					}
					if (computerScore > computerScore2)
						cout << "Computer 1 won the game!" << endl;
					else if (computerScore < computerScore2)
						cout << "Computer 2 won the game!" << endl;
					else
						cout << "Draw!" << endl;
					cout << endl << "The scores - " << endl << "Computer 1: " << computerScore << endl << "Computer 2: " << computerScore2 << endl;
					cout << "***********************************************************************" << endl;
					return 0;
				}
				case 0:
				{
					break;
				}
				default:
					cout << "There is no option " << choice2 << "." << endl;
				}
			} while (choice2 != 0);
			return 0;
		}
		case 3:
		{

			do
			{
				cout << "***********************************************************************" << endl;
				cout << "Press 1 for Player VS. Computer" << endl << "Press 2 for Computer VS. Computer" << endl
					<< "Press 0 to exit" << endl;
				cout << "***********************************************************************" << endl;
				cin >> choice2;
				switch (choice2)
				{
				case 1:
				{
					cout << "Round 1 - GO!" << endl;
					A.player();
					A.computer();
					A.treasures();
					a = A.playerStep();
					b = A.computerStep();
					playerMoves++;
					computerMoves++;
					if ((a == 2) || (a == 6))
						playerMoves--;
					while (((a == 0) && (b == 0)) || ((a == 0) && (b == 1)) || ((a == 1) && (b == 0)) || ((a == 0) && (b == 2))
						|| ((a == 2) && (b == 0)) || ((a == 5) && (b == 0)) || ((a == 6) && (b == 0)) || ((a == 5) && (b == 1))
						|| ((a == 6) && (b == 1)) || ((a == 5) && (b == 2)) || ((a == 6) && (b == 2)))
					{
						playerMoves++;
						computerMoves++;
						if ((a == 1) || (a == 2))// player can't move anymore
						{
							b = A.computerStep();
							playerMoves--;
							if (b == 2)
								computerMoves--;
						}
						else if ((b == 1) || (b == 2))// Computer maybe can't move anymore
						{
							a = A.playerStep();
							computerMoves--;
							if ((a == 2) || (a == 6))
								playerMoves--;
						}
						else if (b == 0)
						{
							a = A.playerStep();
							b = A.computerStep();
							if ((a == 2) || (a == 6))
								playerMoves--;
							if (b == 2)
								computerMoves--;
						}
					}
					cout << endl << "Round 1 over - ";
					if ((a == 3) || (a == 4))
					{
						cout << "Player won this round!" << endl;
						if (a == 3)
						{
							playerScore = 4 - playerMoves;
							computerScore = computerMoves * (-1);

						}
						else
						{
							playerScore = 9 - playerMoves;
							computerScore = computerMoves * (-1);

						}
					}
					else if ((b == 3) || (b == 4))
					{
						cout << "The computer won this round!" << endl;
						if (b == 3)
						{
							playerScore = playerMoves * (-1);
							computerScore = 4 - computerMoves;
						}
						else
						{
							playerScore = playerMoves * (-1);
							computerScore = 9 - computerMoves;
						}
					}
					else if (((a == 1) && (b == 1)) || ((a == 1) && (b == 2)) || ((a == 2) && (b == 1)) || ((a == 2) && (b == 2)))
					{
						cout << "Draw!" << endl;
						playerScore = playerMoves * (-1);
						computerScore = computerMoves * (-1);
					}
					cout << A << endl;

					cout << "Round 2 - GO!" << endl;
					playerMoves = 0;
					computerMoves = 0;
					B.player();
					B.computer();
					B.treasures();
					a = B.playerStep();
					b = B.computerStep();
					playerMoves++;
					computerMoves++;
					if ((a == 2) || (a == 6))
						playerMoves--;
					while (((a == 0) && (b == 0)) || ((a == 0) && (b == 1)) || ((a == 1) && (b == 0)) || ((a == 0) && (b == 2))
						|| ((a == 2) && (b == 0)) || ((a == 5) && (b == 0)) || ((a == 6) && (b == 0)) || ((a == 5) && (b == 1))
						|| ((a == 6) && (b == 1)) || ((a == 5) && (b == 2)) || ((a == 6) && (b == 2)))
					{
						playerMoves++;
						computerMoves++;
						if ((a == 1) || (a == 2))// player can't move anymore
						{
							b = B.computerStep();
							playerMoves--;
							if (b == 2)
								computerMoves--;
						}
						else if ((b == 1) || (b == 2))// Computer maybe can't move anymore
						{
							a = B.playerStep();
							computerMoves--;
							if ((a == 2) || (a == 6))
								playerMoves--;
						}
						else if (b == 0)
						{
							a = B.playerStep();
							b = B.computerStep();
							if ((a == 2) || (a == 6))
								playerMoves--;
							if (b == 2)
								computerMoves--;
						}
					}
					cout << endl << "Round 2 over - ";
					if ((a == 3) || (a == 4))
					{
						cout << "Player won this round!" << endl;
						if (a == 3)
						{
							playerScore = (4 - playerMoves) + playerScore;
							computerScore = (computerMoves * (-1)) + computerScore;

						}
						else
						{
							playerScore = (9 - playerMoves) + playerScore;
							computerScore = (computerMoves * (-1)) + computerScore;

						}
					}
					else if ((b == 3) || (b == 4))
					{
						cout << "The computer won this round!" << endl;
						if (b == 3)
						{
							playerScore = (playerMoves * (-1)) + playerScore;
							computerScore = (4 - computerMoves) + computerScore;
						}
						else
						{
							playerScore = (playerMoves * (-1)) + playerScore;
							computerScore = (9 - computerMoves) + computerScore;
						}
					}
					else if (((a == 1) && (b == 1)) || ((a == 1) && (b == 2)) || ((a == 2) && (b == 1)) || ((a == 2) && (b == 2)))
					{
						cout << "Draw!" << endl;
						playerScore = (playerMoves * (-1)) + playerScore;
						computerScore = (computerMoves * (-1)) + computerScore;
					}
					cout << B;
					if (playerScore > computerScore)
						cout << "You won the game!" << endl;
					else if (playerScore < computerScore)
						cout << "The computer won the game!" << endl;
					else
						cout << "Draw!" << endl;
					cout << endl << "The scores - " << endl << "You : " << playerScore << endl << "The computer : " << computerScore << endl;
					cout << "***********************************************************************" << endl;
					return 0;
				}
				case 2:
				{
					cout << "Round 1 - GO!" << endl;
					A.computer();
					A.computer2();
					A.treasures();
					a = A.computerStep();
					b = A.computerStep2();
					computerMoves++;
					computerMoves2++;
					while (((a == 0) && (b == 0)) || ((a == 0) && (b == 1)) || ((a == 1) && (b == 0)) || ((a == 0) && (b == 2)) || ((a == 2) && (b == 0)))
					{
						computerMoves++;
						computerMoves2++;
						if ((a == 1) || (a == 2))// Computer can't move anymore
						{
							b = A.computerStep2();
							computerMoves--;
						}
						else if ((b == 1) || (b == 2))// Computer 2 can't move anymore
						{
							a = A.computerStep();
							computerMoves2--;
						}
						else if ((a == 0) && (b == 0))
						{
							a = A.computerStep();
							b = A.computerStep2();
						}
					}
					cout << endl << "Round 1 over - ";
					if ((a == 3) || (a == 4))
					{
						cout << "Computer 1 won this round!" << endl;
						if (a == 3)
						{
							computerScore = 4 - computerMoves;
							computerScore2 = computerMoves2 * (-1);

						}
						else
						{
							computerScore = 9 - computerMoves;
							computerScore2 = computerMoves2 * (-1);

						}
					}
					if ((b == 3) || (b == 4))
					{
						cout << "Computer 2 won this round!" << endl;
						if (b == 3)
						{
							computerScore = computerMoves * (-1);
							computerScore2 = 4 - computerMoves2;
						}
						else
						{
							computerScore = computerMoves * (-1);
							computerScore2 = 9 - computerMoves2;
						}
					}
					if (((a == 1) && (b == 1)) || ((a == 1) && (b == 2)) || ((a == 2) && (b == 1)) || ((a == 2) && (b == 2)))
					{
						cout << "Draw!" << endl;
						computerScore = computerMoves * (-1);
						computerScore2 = computerMoves2 * (-1);
					}
					cout << A << endl;

					cout << "Round 2 - GO!" << endl;
					computerMoves = 0;
					computerMoves2 = 0;
					B.computer();
					B.computer2();
					B.treasures();
					a = B.computerStep();
					b = B.computerStep2();
					computerMoves++;
					computerMoves2++;
					while (((a == 0) && (b == 0)) || ((a == 0) && (b == 1)) ||
						((a == 1) && (b == 0)) || ((a == 0) && (b == 2)) || ((a == 2) && (b == 0)))
					{
						computerMoves++;
						computerMoves2++;
						if ((a == 1) || (a == 2))// Computer can't move anymore
						{
							b = B.computerStep2();
							computerMoves--;
						}
						else if ((b == 1) || (b == 2))// Computer 2 can't move anymore
						{
							a = B.computerStep();
							computerMoves2--;
						}
						else if ((a == 0) && (b == 0))
						{
							a = B.computerStep();
							b = B.computerStep2();
						}
					}
					cout << endl << "Round 2 over - ";
					if ((a == 3) || (a == 4))
					{
						cout << "Computer 1 won this round!" << endl;
						if (a == 3)
						{
							computerScore = (4 - computerMoves) + computerScore;
							computerScore2 = (computerMoves2 * (-1)) + computerScore2;

						}
						else
						{
							computerScore = (9 - computerMoves) + computerScore;
							computerScore2 = (computerMoves2 * (-1)) + computerScore2;

						}
					}
					else if ((b == 3) || (b == 4))
					{
						cout << "Computer 2 won this round!" << endl;
						if (b == 3)
						{
							computerScore = (computerMoves * (-1)) + computerScore;
							computerScore2 = (4 - computerMoves2) + computerScore2;
						}
						else
						{
							computerScore = (computerMoves * (-1)) + computerScore;
							computerScore2 = (9 - computerMoves2) + computerScore2;
						}
					}
					else if (((a == 1) && (b == 1)) || ((a == 1) && (b == 2)) || ((a == 2) && (b == 1)) || ((a == 2) && (b == 2)))
					{
						cout << "This is draw!" << endl;
						computerScore = (computerMoves * (-1)) + computerScore;
						computerScore2 = (computerMoves2 * (-1)) + computerScore2;
					}
					cout << B;
					if (computerScore > computerScore2)
						cout << "Computer 1 won the game!" << endl;
					else if (computerScore < computerScore2)
						cout << "Computer 2 won the game!" << endl;
					else
						cout << "Draw!" << endl;
					cout << endl << "The scores: " << endl << "Computer 1: " << computerScore << endl << "Computer 2: " << computerScore2 << endl;
					cout << "***********************************************************************" << endl;
					return 0;
				}
				case 0:
				{
					break;
				}
				default:
					cout << "There is no option " << choice2 << "." << endl;
				}
			} while (choice2 != 0);
			return 0;
		}
		case 0:
		{
			break;
		}
		default:
			cout << "There is no option " << choice << "." << endl;
		}
	} while (choice != 0);
	return 0;
}