//
// Created by LioraPinkhasov on 24/07/2020.
//

#include "FootCommander.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Board.hpp"

namespace WarGame
{

	void FootCommander::specialAttack(vector<vector<Soldier*>> &board, pair<int, int> location)
	{
		Soldier* current;
		//i only need to go over the board and have each for soldier attack
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				current = board[i][j];
				if (current != nullptr)
				{//we want to have commander shoot first to match demands of tests
					if (current->get_player_id() == PlayerId && (current->SoldierType == 1 ))
					{
						current->attack(board, pair<int, int>(i, j));//each footsoldier on team is supposed to attack
					}
				}
			}
		}
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				current = board[i][j];
				if (current != nullptr)
				{
					if (current->get_player_id() == PlayerId && ( current->SoldierType == 0))
					{
						current->attack(board, pair<int, int>(i, j));//each footsoldier on team is supposed to attack
					}
				}
			}
		}
	};
}