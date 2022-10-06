/*  Benedetta Cervone s1443887
    Hester van de Ven s2000156
    Connect 4
 */
#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
    interface.guiSetup();//starts the gui interface
	controller = new GameController(board, &human, heuristics);	//initializing playing board
    tracker.tSetup();

}

//--------------------------------------------------------------
void ofApp::update(){
    
    if(interface.reset){
        controller->resetBoard();
        interface.reset=false;
    }
    
    tracker.tUpdate();
	controller->update();

}

//--------------------------------------------------------------
void ofApp::draw(){
	controller->drawGame(interface);
    interface.guiDraw();
    human.setColumn(tracker.getCoinX(), tracker.getCoinY());
   // tracker.cameraDisplay(); //uncomment this if you want to see the camera output
    //ofDrawCircle(tracker.getCoinX(), tracker.getCoinY(), 30); //uncomment this to see the coin on the screen
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
	//if (key == OF_KEY_LEFT) {
	//	human.moveLeft();
	//}
	//else if (key == OF_KEY_RIGHT) {
	//	human.moveRight();
	//}
	//else
        if (key == OF_KEY_DOWN || key ==' ') {
		controller->dropPiece();
	}
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
