/*  Benedetta Cervone s1443887
 Hester van de Ven s2000156
 Connect 4
 */
#include "Piece.hpp"
using namespace std;

Piece::Piece() {
	color = -1;//initialise color of empty slot	
}


void Piece::drawPiece(int x, int y, Interface _inter) {
	if (color == -1) {	//empty slot
		ofSetColor(50, 50, 49);
	}
	else if (color == 1) {	//player 1
        ofSetColor(_inter.color1);
	}
	else if (color == 2) {	//player 2
		ofSetColor(_inter.color2);
	}

	ofDrawCircle(100 + x *  80, 600- y * 80, PIECE_SIZE);
}


