//
// Created by LioraPinkhasov on 24/07/2020.
//
#pragma once
#include "FootSoldier.hpp"

#include <iostream>

using namespace std;

namespace WarGame
{
	class FootCommander : public FootSoldier
	{

	private:
	public:
		explicit FootCommander(int player) : FootSoldier(player, 20, 150, 1) { this->Demage = 20; this->Health = 150;  this->MaxHealth = 150;}

		void specialAttack(vector<vector<Soldier*>> &board, pair<int, int> location);
	
		 void Action(vector<vector<Soldier*>> &board, pair<int, int> location) { specialAttack(board, location); };

	};
}