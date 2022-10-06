/*  Benedetta Cervone s1443887
 Hester van de Ven s2000156
 Connect 4
 */
#pragma once

#include "ofMain.h"
#include "Constants.hpp"
#include <iostream>


class HumanPlayer {
public:
	HumanPlayer();		
	void moveLeft();
	void moveRight();
    void setColumn(int x, int y);
	int col = 0;



};
