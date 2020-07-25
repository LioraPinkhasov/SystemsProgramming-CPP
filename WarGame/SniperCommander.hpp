//
// Created by LioraPinkhasov on 24/07/2020.
//
#pragma once
#include "Sniper.hpp"
#include <iostream>

using namespace std;
namespace WarGame
{
    class SniperCommander : public Sniper {
    private:

        int SoldierHealth = 120;
        int SoldierDemage = 100;
    public:
        explicit SniperCommander(int player) : Sniper(120, 100, player, 3) {}


        void specialAttack(vector<vector<Soldier *>> &board, pair<int, int> location);

        virtual void Action(vector<vector<Soldier *>> &board, pair<int, int> location) {
            specialAttack(board, location);
        };

    };
}