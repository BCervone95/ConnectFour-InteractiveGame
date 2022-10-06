/*  Benedetta Cervone s1443887
 Hester van de Ven s2000156
 Connect 4
 */

#include "HeuristicsPlayer.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <vector>
using namespace std;

const int HeuristicsPlayer::MAXDEPTH = 2;		//give maximum amount of steps ahead

HeuristicsPlayer::HeuristicsPlayer(){ 
}

int HeuristicsPlayer::getNextMove(Board const& board, int currentPlayer) {
	int move = 0;
	int highestScore = -1000;
	for (int i = 0; i < A_W; i++) {
		if (!board.isColumnFull(i)) {
			Board newBoard = Board(board);
			int layer = newBoard.doMove(i, currentPlayer);
			//cout << newBoard.slotsArray << endl;
			//cout << board.slotsArray << endl;

    
			int otherPlayer = currentPlayer % 2 + 1;
			int heurScore = -getScore(newBoard, otherPlayer, 0);

			if (heurScore > highestScore) {
				highestScore = heurScore;
				move = i;
			}

		}
	}
	return move;
}

bool HeuristicsPlayer::checkPositions(int players[], int checkPlayer, int requiredCount) {
	int count = 0;
	for (int i = 0; i < 4; i++) {			//for 4 arbitrary slots, check the amount of coins for one player
		if (players[i] == checkPlayer) {
			count++;
		}
	}

	int requiredEmptyCount = 4 - count;		//the should only be empty slots other than the player ones
	if (count == requiredCount) {		
		int emptyCount = 0;
		for (int i = 0; i < 4; i++) {
			players[i] = -1; {				//for the same 4 arbitrary slots, check if they are empty
				emptyCount++;
			}
		}
		return emptyCount == requiredCount;		//check if emptyCount is as required
	}
	else {
		return false;
	}

}

int HeuristicsPlayer::heuristicValue(Board const &board, int currentPlayer) {
	//initialize counters
	int counter2P1=0;			//counter for player 1 with 2 slots filled
	int counter3P1=0;			//counter for player 1 with 3 slots filled
	int counter2P2=0;			//counter for player 2 with 2 slots filled
	int counter3P2=0;			//counter for player 2 with 3 slots filled

	int player1 = currentPlayer;
	int player2 = currentPlayer % 2 + 1;

	//check vertical
	for (int i = 0; i < A_W; i++) {
		for (int j = 0; j < A_H-3 ; j++) {		//only go to height-3 to stay withing the array when counting up
			int testingPlayer[4] = { board.slotsArray[i][j].color, board.slotsArray[i][j+1].color, board.slotsArray[i][j+2].color, board.slotsArray[i][j+3].color };
			if (checkPositions(testingPlayer, player1, 2)) {		//if there are 2 player 2 coins and 2 open, add to counter
				counter2P1++;
			}
			if (checkPositions(testingPlayer, player1, 3)) {
				counter3P1++;
			}
			if (checkPositions(testingPlayer, player2, 2)) {
				counter2P2++;
			}
			if (checkPositions(testingPlayer, player2, 3)) {
				counter3P2++;
			}
		}

	}

	//check horizontally
	for (int j = 0; j < A_W; j++) {
		for (int i = 0; i < A_H-3; i++) {
			int testingPlayer[4] = { board.slotsArray[i][j].color, board.slotsArray[i+1][j].color, board.slotsArray[i+2][j].color, board.slotsArray[i+3][j].color };
			if (checkPositions(testingPlayer, player1, 2)) {
				counter2P1++;
			}
			if (checkPositions(testingPlayer, player1, 3)) {
				counter3P1++;
			}
			if (checkPositions(testingPlayer, player2, 2)) {
				counter2P2++;
			}
			if (checkPositions(testingPlayer, player2, 3)) {
				counter3P2++;
			}
		}

	}

	int value = 3 * counter3P1 + counter2P1 - 3 * counter3P2 - counter2P2;		//3 coins per player are worth the most, opposite for other player
	return value;
}

int HeuristicsPlayer::getScore(Board const &board, int currentPlayer, int depth) {
	int winner = board.getWinner();

	if (winner == currentPlayer % 2 + 1) {
		return -20;
	}
	else if (board.isFull()) {
		return 0;	//it's a tie
	}
	else if (winner == currentPlayer) {
		return 20;
	}

	else {
		int score;
		int evaluation = -100;

		for (int i = 0; i < A_W; i++) {
			if (!board.isColumnFull(i)) {
				Board newBoard = Board(board);
				int layer = newBoard.doMove(i, currentPlayer);
				

				int otherPlayer = currentPlayer % 2 + 1;

				if (depth >= MAXDEPTH) {
					score = heuristicValue(newBoard, currentPlayer);
				}
				else {
					score = getScore(newBoard, currentPlayer, depth + 1);
				}
				if (depth % 2 == 0) {
					evaluation = fmax(evaluation, score);
				}
				else {
					evaluation = fmin(evaluation, score);
				}
			}
		}
		return evaluation;
	}
}
