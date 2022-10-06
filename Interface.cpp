/*  Benedetta Cervone s1443887
 Hester van de Ven s2000156
 Connect 4
 */

#include "Interface.hpp"
Interface::Interface(){
}

void Interface::guiSetup(){
    
    
    parameters.add(color1.set("Player 1",ofColor(255),ofColor(0,0),ofColor(255))); //color panel for player 1
    parameters.add(color2.set("Player 2",ofColor(0),ofColor(8,0),ofColor(255))); // color panel for player 2

    resetButton.addListener(this, &Interface::resetGame);
    
    
    
    gui.setup(parameters);
    gui.add(resetButton.setup("Reset Game"));
    
    gui.setPosition(680, 10); //set position of panel
}
void Interface::guiDraw(){
    gui.draw();
}

void Interface::resetGame(){
    reset = true;
}



