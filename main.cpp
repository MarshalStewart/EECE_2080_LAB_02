// TowerHannoiGame.cpp : Defines the entry point for the console application.
//
// Marsh
// Steven LeVassuer
// In Loving Memory: Ilan (September 2020 -> September 2020)

#include "StackQueue.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TowersOfHannoiGame
{
public:
	TowersOfHannoiGame() : m_GameEnded(false)
	{
		tower_1.push(4);
		tower_1.push(3);
		tower_1.push(2);
		tower_1.push(1);
	}

	bool IsGameEnded() { return m_GameEnded; }
	
	void setGameEnded(bool endToken)
	{
		m_GameEnded = endToken;
	}

	ArrayBasedQueue getMoves()
	{

	}

	void PrintTowers()
	{
		// Tower 1: 3
		// Tower 2: 4 2
		// Tower 3: 1  
		for (int i=1; i<4; i++)
		{
			ArrayBasedStack *curTower = getTower(i);
			string str = curTower->toString();
			
			printf("Tower %d: %s\n", i, str.c_str());

		
		}
	}

	ArrayBasedStack* getTower(int id)
	{
		ArrayBasedStack *curTower = nullptr;
		switch (id)
		{
			case 1:
				curTower = &tower_1;
				break;
			case 2:
				curTower = &tower_2;
				break;
			case 3: 
				curTower = &tower_3;
				break;
			default:
				break; // error
		}
		return curTower;
	}

	bool checkValidMove(int diskId, int fromId, int toId)
	{
		bool validMove = true;

		// peak fromId tower (check if on top)
		ArrayBasedStack *fromTower = getTower(fromId);
		if(fromTower == nullptr)
			return false;

		if (!fromTower->isEmpty()) if (fromTower->peek() != diskId)
			validMove = false;

		// peak toId tower (disk can fit on new tower)
		ArrayBasedStack *toTower = getTower(toId);
		if (toTower == nullptr)
			return false;

		if (!toTower->isEmpty()) if (toTower->peek() <= diskId)
			validMove = false;

		return validMove;

	}

	void makeMove(int diskId, int fromId, int toId)
	{
		if (!checkValidMove(diskId, fromId, toId))
		{
			cout << "Invalid move" << endl;
			return;
		}

		// Get towers
		ArrayBasedStack *fromTower = getTower(fromId);
		ArrayBasedStack *toTower   = getTower(toId);

		// blindly move shit
		fromTower->pop();
		toTower->push(diskId);

		// queue move cmds
		string cmd = to_string(diskId) 
			+ to_string(fromId) + to_string(toId);
		moves.enQueue(cmd);

		// check if they won
		if (tower_1.isEmpty() && tower_2.isEmpty())
		{
			cout << "Congrats, you won!!!" << endl;
			setGameEnded(true);
			int count = 1;
			while (!moves.isEmpty())
			{
				printf("%d: %s\n", count, moves.peekFront().c_str());
				moves.deQueue();
				count++;
			}
			exit(0);
		}

	}


private:
	bool m_GameEnded;
	ArrayBasedStack tower_1;
	ArrayBasedStack tower_2;
	ArrayBasedStack tower_3;
	ArrayBasedQueue moves;

};

int main()
{

	cout << "Enter in moves to make for Towers  of  Hannoi" << endl;
	cout << "Progam will exit once towers have  been successfully moved of" << endl;
	cout << "or string of -1 is entered. Moves must be entired in format of" << endl;
	cout << "<disk>,<column from>,<column to>   NOTE no spaces!!!!" << endl;

	TowersOfHannoiGame game;

	bool receivedEndToken = false;

	while (!receivedEndToken || game.IsGameEnded())
	{
		std::string inputLine;
		game.PrintTowers();
		cout << "Enter Move " << endl;
		getline(cin, inputLine);
		if (inputLine == "-1")
		{
			receivedEndToken = true;
		}
		else
		{
			std::vector<std::string> output;
			std::string::size_type prev_pos = 0, pos = 0;
			// Snippet from https://stackoverflow.com/questions/5167625/splitting-a-c-stdstring-using-tokens-e-g
			// tokenizing a string
			while ((pos = inputLine.find(",", pos)) != std::string::npos)
			{
				std::string substring(inputLine.substr(prev_pos, pos - prev_pos));
				output.push_back(substring);
				prev_pos = ++pos;
			}
			//Need to get last token
			output.push_back(inputLine.substr(prev_pos, pos - prev_pos)); // Last word

			if (output.size() != 3)
			{
				receivedEndToken = true;
				cout << "Invalid input recieved = " + inputLine << endl;
			}
			else
			{
				std::string disk = output[0];
				std::string from = output[1];
				std::string to = output[2];

				if (disk.size() == 0 || from.size() == 0 || to.size() == 0)
				{
					receivedEndToken = true;
					cout << "Invalid input recieved = " + inputLine << endl;
				}

				int diskId = atoi(disk.c_str()); 
				int fromId = atoi(from.c_str());
				int toId = atoi(to.c_str());
				//if any number is zero we didn't have a integer
				if (diskId == 0 || fromId == 0 || toId == 0)
				{
					receivedEndToken = true;
					cout << "Invalid input recieved = " + inputLine << endl;
				}

				cout << "Disk " << diskId << " From " << fromId << " To " << toId << endl;
				if (!receivedEndToken || game.IsGameEnded())
					game.makeMove(diskId, fromId, toId);	
				

			}
		}

		game.setGameEnded(receivedEndToken);

	}

    return 0;
}

