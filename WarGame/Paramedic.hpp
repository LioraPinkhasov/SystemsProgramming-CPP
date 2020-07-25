//
// Created by LioraPinkhasov on 24/07/2020.
//
#pragma once
#include "Soldier.hpp"

namespace WarGame
{
	class Paramedic :public  Soldier
	{
	private:

		int SoldierHealth = 100;
		int SoldierDemage = 0;

	public:
		explicit Paramedic(int player) : Soldier(100, 0, player, 4) { this->Health = 100; this->MaxHealth = 100;}
		explicit Paramedic(int player, int Damage, int health, int type) : Soldier(health, Damage, player, type) {}
		 void attack(vector<vector<Soldier*>> &board, pair<int, int> location);
		virtual void Action(vector<vector<Soldier*>> &board, pair<int, int> location) { attack(board, location); };


	};
}

