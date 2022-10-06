/*  Benedetta Cervone s1443887
 Hester van de Ven s2000156
 Connect 4
 */
#pragma once
#include "ofMain.h"
#include "Board.hpp"
#include <iostream>

class HeuristicsPlayer {
public:
	HeuristicsPlayer();
	int getNextMove(Board const&, int);

private:
	int getScore(Board const&, int, int);
	static const int MAXDEPTH;
	int heuristicValue(Board const&, int);
	bool checkPositions(int[], int, int);

};