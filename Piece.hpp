/*  Benedetta Cervone s1443887
 Hester van de Ven s2000156
 Connect 4
 */
#pragma once

#include "ofMain.h"
#include "Constants.hpp"
#include "Interface.hpp"
#include <iostream>

class Piece {
public:
	Piece();			
	void drawPiece(int x, int y, Interface _inter);
    Interface * inter;
	int color;
    
};


