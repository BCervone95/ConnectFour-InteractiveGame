/*  Benedetta Cervone s1443887
 Hester van de Ven s2000156
 Connect 4
 */
#include "HumanPlayer.hpp"

using namespace std;

HumanPlayer::HumanPlayer() {
    
    
}


void HumanPlayer::moveLeft() {
    
    if (col > 0) {	//move within boundries of board
        col--;
    }
}

void HumanPlayer::moveRight() {
    if (col < A_W - 1) {	//move within boundries of board
        col++;
    }
}


void HumanPlayer::setColumn(int x, int y){
    
    //cout << "x" << x << "y"<< y  << endl;
    if (y>0 && y<300){
        for( int i = 0; i < 7;i++) {
            if(x > i*100 && i*100 + 100) {
                col = i;
            }
        }
        
    }
}






