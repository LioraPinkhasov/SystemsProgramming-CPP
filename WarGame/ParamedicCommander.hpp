//
// Created by LioraPinkhasov on 24/07/2020.
//
#pragma once
#include "Paramedic.hpp"

namespace WarGame
{
	class ParamedicCommander :public Paramedic
	{
	private:

		int SoldierHealth = 200;
		int SoldierDemage = 0;
	public:
        explicit ParamedicCommander(int player) : Paramedic(player, 0, 200, 5) { this->Health = 200;  this->MaxHealth = 200;
        };


        void specialAttack(vector<vector<Soldier*>> &board, pair<int, int> location);

        void Action(vector<vector<Soldier*>> &board, pair<int, int> location) { specialAttack(board, location); };

	};
}
