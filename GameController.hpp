/*  Benedetta Cervone s1443887
 Hester van de Ven s2000156
 Connect 4
 */
#pragma once

#include "ofMain.h"
#include "Board.hpp"
#include "HumanPlayer.hpp"
#include "HeuristicsPlayer.hpp"
#include <iostream>


class GameController {
public:
	GameController(Board _board, HumanPlayer * _human, HeuristicsPlayer * _heuristics);		//pointer to a board and human player
	void dropPiece();
	void drawInterfacePiece(Interface _inter);
	void update();
	void drawGame(Interface _inter);
    void resetBoard();

	
private:
	Board board;
	HumanPlayer * human;
	Piece * interfacePiece;
	HeuristicsPlayer * heuristics;
   	int end = -1;
	int currentPlayer = 1;	//player 1 starts
	int column;
	bool gameOver = false;
	void switchPlayer();
	Interface * inter;
};



