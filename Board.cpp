/*  Benedetta Cervone s1443887
 Hester van de Ven s2000156
 Connect 4
 */
#include "Board.hpp"
using namespace std;

Board::Board() {
	resetBoard();
}

void Board::resetBoard() {
	for (int i = 0; i < A_W; i++) {
		for (int j = 0; j < A_H; j++) {
			slotsArray[i][j].color = -1;	//Turn all slots to empty
		}
	}
    
}

void Board::drawBoard(Interface _inter) {
	ofBackgroundGradient(ofColor::white, ofColor::blue);
	//outline of playing board
	ofSetColor(0, 0, 159);
	ofDrawRectangle(0, 100, 700, 600);
	//inner part of the board
	ofSetColor(0, 0, 204);
	ofDrawRectangle(10, 110, 680, 580);


	for (int i = 0; i < A_W; i++) {
		for (int j = 0; j < A_H; j++) {
			slotsArray[i][j].drawPiece(i, j, _inter);	//Create slots

		}
	}
}

int Board::doMove(int column, int color) {
	for (int i = 0; i < A_H; i++) {
		if (slotsArray[column][i].color == -1) {	//check if slot is still empty, thus valid move
			slotsArray[column][i].color = color;	//if valid, make move

			return i;
		}

	}
	return -1;
}

int Board::getWinner()const {
	for (int i = 0; i < A_W; i++)
	{
		for (int j = 0; j < A_H; j++)
		{
			int winner = isWinner(i, j);

			if (winner != -1)
			{
				return winner;
			}
		}
	}
	return -1;
}



int Board::isWinner(int col, int row)const {

	int coin = slotsArray[col][row].color;
	int count = 0;

	//check horizontally
	for (int i = 0; i < A_W; i++) {
		if (slotsArray[i][row].color == coin) {
			count++;
		}
		else {
			count = 0;
		}
		if (count >= 4) {
			return coin;
		}

	}
	count = 0;
	//check vertically
	//checkvertical
	for (int i = 0; i < A_H; i++) {
		if (slotsArray[col][i].color == coin) {
			count++;

		}
		else {
			count = 0;
		}
		if (count >= 4) {
			return coin;
		}

	}


	return -1;
}

bool Board::isFull()const {
	for (int i = 0; i < A_W; i++) {
		for (int j = 0; j < A_H; j++) {
			if (slotsArray[j][i].color == -1) {
				return false;
			}
		}

	}
	return true;
}


bool Board::isColumnFull(int column) const {
	for (int j = 0; j < A_H; j++) {
		if (slotsArray[column][j].color == -1) {
			return false;
		}
	}
	return true;
}
