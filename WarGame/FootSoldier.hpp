//
// Created by LioraPinkhasov on 24/07/2020.
//
#pragma once
#include "Soldier.hpp"
#include "Board.hpp"
#include <iostream>
using namespace std;

namespace WarGame
{
	class FootSoldier : public Soldier
	{
	private:
		
	public:
		 FootSoldier(int player) : Soldier(100, 10, player, 0) {}
		 FootSoldier(int player, int Damage, int health, int type) : Soldier(health, Damage, player, type) { this->Health = health; this->Demage = 10; this->MaxHealth = 100;}

		 virtual ~FootSoldier() = default;

		  void attack(vector<vector<Soldier*>> &board, pair<int, int> location)  ;
		 virtual void Action(vector<vector<Soldier*>> &board, pair<int, int> location)  { attack(board, location); } ;
	};
}