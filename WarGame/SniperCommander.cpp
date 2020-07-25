//
// Created by LioraPinkhasov on 24/07/2020.
//
#include "SniperCommander.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Board.hpp"
namespace WarGame
{
void SniperCommander::specialAttack(vector<vector<Soldier*>> &board, pair<int, int> location)
{
	Soldier* current;
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
		{
			current = board[i][j];
			if (current != nullptr)
			{
				if (current->get_player_id() == PlayerId && (current->SoldierType == 2 || current->SoldierType == 3))
				{
					current->attack(board, pair<int, int>(i, j));//each sniper on team is supposed to attack
				}
			}
		}
	}
};
}