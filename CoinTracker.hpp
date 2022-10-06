//
//  CoinTracker.hpp
//  Tracker
//
//  Created by Benedetta Cervone on 30/01/2019.
//

#ifndef CoinTracker_hpp
#define CoinTracker_hpp

#include <stdio.h>
#include "ofxOpenCv.h"


class CoinTracker{
public:
    CoinTracker();
    void tSetup();
    void tUpdate();
    void cameraDisplay();
    float getCoinX();
    float getCoinY();
    int cameraHeight = 240;
    int cameraWidth = 320;
    int numPixels = 320*240;
    int coinX;
    int coinY;
    ofVideoGrabber vidGrabber;
    ofxCvColorImage colorImg;
 
    ofxCvGrayscaleImage hueImg;
    ofxCvGrayscaleImage satImg; //Saturation map
    ofxCvGrayscaleImage briImg; //Brightness map
    
    ofxCvGrayscaleImage contourImg; //Grayscale image we are gonna run the contour finder over to find our color
    ofxCvContourFinder finderBlue;
    
    unsigned char * trackedColor;
    
   // color one; //color that we’re gonna track
private:
    int minHue=110;
    int maxHue=140;
    int minSat=190;
    int maxSat=250;
};

#endif /* CoinTracker_hpp */
