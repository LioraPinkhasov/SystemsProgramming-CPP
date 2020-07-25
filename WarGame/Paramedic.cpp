//
// Created by LioraPinkhasov on 24/07/2020.
//
#include "Paramedic.hpp"
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Board.hpp"

namespace WarGame
{
	void Paramedic::attack(vector<vector<Soldier*>> &board, pair<int, int> location)
	{
		int x = location.first;
		int y = location.second;
		//now there are 4 locations to be healed
		//locations are up down left right
		Soldier* target;
		if (x != 0)
		{
			target = board[x - 1][y];
			if (target != nullptr)
			{
				if (target->get_player_id() == PlayerId)
				{
					target->Health = target->MaxHealth;
				}
			}
		}


		if ((x != board.size() - 1))
		{
			target = board[x + 1][y];
			if (target != nullptr)
			{
				if (target->get_player_id() == PlayerId)
				{
					target->Health = target->MaxHealth;
				}
			}
		}


		if (y != 0)
		{
			target = board[x][y - 1];
			if (target != nullptr)
			{
				if (target->get_player_id() == PlayerId)
				{
					target->Health = target->MaxHealth;
				}
			}
		}


		if (y != board[0].size())
		{
			target = board[x][y + 1];
			if (target != nullptr)
			{
				if (target->get_player_id() == PlayerId)
				{
					target->Health = target->MaxHealth;
				}
			}
		}

	}
}
