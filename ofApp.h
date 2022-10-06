/*  Benedetta Cervone s1443887
 Hester van de Ven s2000156
 Connect 4
 */
#pragma once

#include "ofMain.h"
#include "Interface.hpp"
#include "Board.hpp"
#include "Piece.hpp"
#include "GameController.hpp"
#include "HumanPlayer.hpp"
#include "HeuristicsPlayer.hpp"
#include "CoinTracker.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        Interface interface;
        Board board;
		GameController * controller;
		HumanPlayer human;
		HeuristicsPlayer * heuristics;
        CoinTracker tracker;


	
};
