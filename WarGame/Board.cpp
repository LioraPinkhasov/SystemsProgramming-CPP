//
// Created by LioraPinkhasov on 24/07/2020.
//

#include "Board.hpp"
#include <iostream>

using namespace std;

namespace WarGame {

	Soldier*& Board::operator[](pair<int, int> location)
	{
		return board[location.first][location.second];
	}

	Soldier* Board::operator[](pair<int, int> location) const
	{
		return board[location.first][location.second];
	}

	void Board::move(int player_number, pair<int, int> source, MoveDIR direction) {
		if (source.first >= board.size() || source.first < 0 || source.second >= board.size() || source.second < 0) {
			throw invalid_argument("Outside of the board");
		}
		Soldier* s = (*this)[source];
		if (s == NULL)
		{
			
				throw invalid_argument("Illegal argument");
		}
		if (s->get_player_id() != player_number)
		{
			throw invalid_argument("Illegal argument");
		}
		pair<int, int> target;
		switch (direction)
		{
		case Up:
			target = make_pair(source.first + 1, source.second);
			break;
		case Down:
			target = make_pair(source.first - 1, source.second);
			break;
		case Left:
			target = make_pair(source.first, source.second - 1);
			break;
		case Right:
			target = make_pair(source.first, source.second + 1);
			break;
		}
		if (target.first >= board.size() || target.first < 0 || target.second >= board.size() || target.second < 0) {
			throw invalid_argument("Outside of the board");
		}
		if ((*this)[target] != nullptr) {
			throw runtime_error("stepping on other soldier!\n");
		}

		(*this)[target] = s;
		(*this)[source] = nullptr;
		s->Action(board, target);

	}

	bool Board::has_soldiers(int player_number) const {
		for (uint i = 0; i < board.size(); ++i) {
			for (uint j = 0; j < board[i].size(); ++j) {
				Soldier* s = (*this)[{i, j}];
				if (s != nullptr )
					if(s->get_player_id() == player_number) {
					return true;
				}
			}
		}
		return false;
	}

	void Board::print_board() const {
		printf("\n");
		printf("size: %d, size(0): %d\n", this->board.size(), this->board[0].size());
		for (int i = 0; i < this->board.size(); ++i) {
			for (int j = 0; j < this->board.size(); ++j) {
				if ((*this)[{i, j}] != nullptr) {
					printf("  %d:%d  ", (*this)[{i, j}]->get_player_id(), (*this)[{i, j}]->get_health());
				}
				else {
					printf("  ----  ");
				}
			}
			printf("\n");
		}
		printf("\n");
	}

}