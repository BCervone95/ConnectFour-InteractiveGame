/*  Benedetta Cervone s1443887
 Hester van de Ven s2000156
 Connect 4
 */
#include "GameController.hpp"
using namespace std;

GameController::GameController(Board _board, HumanPlayer * _human,  HeuristicsPlayer * _heuristics) {
	board = _board;
	human = _human;
	heuristics = _heuristics;
	column = 0;	//initialize column counter
    interfacePiece = new Piece();
}

void GameController::update() {
	if (currentPlayer == 1) {
		column = human->col;
	}
	else {
		//column = ofRandom(0,7);
		column = heuristics->getNextMove(board, currentPlayer);
		dropPiece();
	}
}

void GameController::drawInterfacePiece(Interface _inter) {
	//draw a coin for the right player, above the board
	interfacePiece->color = currentPlayer;
	interfacePiece->drawPiece(column, A_H + 1, _inter);
} 

void GameController::dropPiece() {
	if (!gameOver) {
		int row = board.doMove(column, currentPlayer);
		if (row !=-1) {	//if board says move is valid, execute
			
			end = board.isWinner(column, row);
			if (end > 0) {
				cout << "Finished, player " << end << " won." << endl;
				gameOver = true;
			}
			else if (board.isFull()) {
				cout << "It's a tie!" << endl;
				gameOver = true;
			}
			else {
				switchPlayer();
			}
		}
		else {
			cout << "Try again, loser" << endl;	//if move is not valid, pick another column
		}
	}
}

void GameController::switchPlayer() {
	currentPlayer = currentPlayer % 2 + 1;	//alternate between players
}

void GameController::drawGame(Interface _inter) {
		
		board.drawBoard(_inter);
		drawInterfacePiece(_inter);
}

void GameController::resetBoard() {
    board.resetBoard();
    gameOver=false;
}
