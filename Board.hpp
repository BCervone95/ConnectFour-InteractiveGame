/*  Benedetta Cervone s1443887
 Hester van de Ven s2000156
 Connect 4
 */
#pragma once
#include "ofMain.h"
#include "Piece.hpp"
#include "Constants.hpp"
#include <iostream>


class Board{
public:
    
	Board();
	Board(const Board& board) = default;
	void resetBoard();
	void drawBoard(Interface _inter);


	int isWinner(int col, int row)const;
    
    int getWinner()const;
	
    bool isFull()const;
    
    bool isColumnFull(int column) const;
    int doMove(int column, int color);
	
	Piece slotsArray[A_W][A_H];	//Make an array of coins
    
};

