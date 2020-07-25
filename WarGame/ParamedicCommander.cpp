//
// Created by LioraPinkhasov on 24/07/2020.
//
#include "ParamedicCommander.hpp"
namespace WarGame
{


    void ParamedicCommander::specialAttack(vector<vector<Soldier*>> &board, pair<int, int> location)
    {
        Soldier* current;
        //i only need to go over the board and have each for soldier attack
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                current = board[i][j];
                if (current != nullptr)//we want commander to act first to match test
                {
                    if (current->get_player_id() == PlayerId && (current->SoldierType == 1 ))
                    {
                        current->attack(board, pair<int, int>(i, j));//each parmadic on team is supposed to attack
                    }
                }
            }
        }
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                current = board[i][j];
                if (current != nullptr)
                {
                    if (current->get_player_id() == PlayerId && ( current->SoldierType == 0))
                    {
                        current->attack(board, pair<int, int>(i, j));//each footsoldier on team is supposed to attack
                    }
                }
            }
        }
    }
}