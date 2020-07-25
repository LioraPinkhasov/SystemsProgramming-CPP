//
// Created by LioraPinkhasov on 24/07/2020.
//
#include "Sniper.hpp"
#pragma once
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "FootSoldier.hpp"

using namespace std;

void Sniper::attack(vector<vector<Soldier*>> &board, pair<int, int> location)
{
	Soldier* target = nullptr;
	uint targetHP = 0;
	pair<int, int> locationTarget;
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
		{
			Soldier* fighter = board[i][j];
			if (fighter != nullptr)
			{
				if (fighter->get_player_id() != PlayerId)
				{

					if (targetHP <= fighter->Health)
					{
						targetHP = fighter->Health;
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

		if (!target->UpdateHealth(-((int)this->Demage))) {//the function adds the damage so damage needs to be a negative
			cout << "soldier has been killed" << target << endl;
			board[locationTarget.first][locationTarget.second] = nullptr;
		}
		else {
			cout << " soldier in [" << locationTarget.first << "],[" << locationTarget.second
				<< "], updated health is: " << target->Health << endl;

		}
	}
	else
	{
		cout << "there are no more soldiers to attack!" << endl;

	}
}
