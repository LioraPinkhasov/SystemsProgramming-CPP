//
// Created by LioraPinkhasov on 24/07/2020.
//
#pragma once
#include <stdexcept>
#include <math.h>
#include <vector>
#include <iostream>
#include <iomanip>
//#include <sys/param.h>

using namespace std;
typedef unsigned int uint;


	class Soldier {

	public:
		uint Health;//soldier health
		uint Demage;// occure by soldier
		uint PlayerId;//player id
		uint MaxHealth;//the maxim healgth per soldier
		int SoldierType; /*there are 5 types of soldiers
							0 footsoldier
							1 footcomaner
							2 sniper
							3 snipercomander
							4 parmadeic
							5 parmediccomander
						  */

						  //soldier constuctor
		Soldier(uint h, uint d, int p, int t) { this->Health = h; this->Demage = d; this->PlayerId = p; this->SoldierType = t; };

		//destructor
		virtual ~Soldier() = default;

		//distance by pitagoras
		double distance(uint x_s, uint y_s, uint x_t, uint y_t) { return sqrt((x_s - x_t)*(x_s - x_t) + (y_s - y_t)*(y_s - y_t)); };

		//attack sega
		virtual void attack(vector<vector<Soldier*>> &board, pair<int, int> location) {};
		uint get_damage();
		virtual void Action(vector<vector<Soldier*>> &board, pair<int, int> location) {};
		//health sega
		uint get_health()
		{
			return Health;
		}

		uint get_max_health()
		{
			return MaxHealth;
		}
		bool UpdateHealth(int hp)
		{
			int UpdatedHealth = (int)Health + hp;
			if (UpdatedHealth <= 0)
			{
				return false;//if life reaches 0 you dead
			}
			else if ((uint)UpdatedHealth > MaxHealth) {
				Health = (uint)MaxHealth;
				return true;//cant have more hp then max
			}

			else
			{
				Health = (uint)UpdatedHealth;
				return true;//life goes on
			}
		};

		//player sega
		uint get_player_id()
		{
			return PlayerId;
		}

	};
