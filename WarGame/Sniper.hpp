//
// Created by LioraPinkhasov on 24/07/2020.
//
#pragma once
#include "Soldier.hpp"

	class Sniper :public Soldier
	{
	private:


	public:

		explicit Sniper(int player) : Soldier(100, 50, player, 2) { this->Health = 100; this->Demage = 50; this->MaxHealth = 100; }
		explicit Sniper(int player, int Damage, int health, int type) : Soldier(health, Damage, player, type) {}
		virtual void attack(vector<vector<Soldier*>> &board, pair<int, int> location);
		virtual void Action(vector<vector<Soldier*>> &board, pair<int, int> location) { attack(board, location); };

	};

