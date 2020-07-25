//
// Created by LioraPinkhasov on 24/07/2020.
//

#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Board.hpp"
#include "FootSoldier.hpp"

using namespace std;

namespace WarGame
{
	void FootSoldier::attack(vector<vector<Soldier*>> &board, pair<int, int> location)
	{

		Soldier* target = nullptr;
		double currDistance = 1000.0;
		pair<int, int> locationTarget;
		//this finds closest enemy
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				Soldier* fighter = board[i][j];
				if (fighter != nullptr)
				{
					if (fighter->get_player_id() != PlayerId)
					{
						double dis = distance(location.first, location.second, i, j);
						if (dis <= currDistance)
						{
							currDistance = dis;
							target = fighter;
							locationTarget.first = i;
							locationTarget.second = j;
						}
					}
				}
			}
		}

		if (target != nullptr)
		{

			if (!target->UpdateHealth(-((int)this->Demage) )){//the function adds the damage so damage needs to be a negative
				cout << "soldier has been killed" << target << endl;
				board[locationTarget.first][locationTarget.second] = nullptr;
			}
			else {
				cout << " soldier in [" << locationTarget.first << "],[" << locationTarget.second
					<< "], updated health is: " << target->get_health() << endl;

			}
		}
		else
		{
			cout << "there are no more soldiers to attack!" << endl;

		}
	}
}
	


