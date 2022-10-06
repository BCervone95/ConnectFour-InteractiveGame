/*  Benedetta Cervone s1443887
 Hester van de Ven s2000156
 Connect 4
 */

#ifndef Interface_hpp
#define Interface_hpp


#include "ofxGui.h"

class Interface{
public:
    Interface();
    
    void guiSetup();
    void guiDraw();
    void resetGame();
    bool reset = false;

    ofxPanel gui;

    ofParameterGroup parameters;
    ofParameter<ofColor> color1; 
    ofParameter<ofColor> color2;
    ofxButton resetButton;
    
  
};


#endif /* Interface_hpp */
