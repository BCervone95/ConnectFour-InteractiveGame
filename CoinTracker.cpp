//
//  CoinTracker.cpp
//  Tracker
//
//  Created by Benedetta Cervone on 30/01/2019.
//

#include "CoinTracker.hpp"

CoinTracker::CoinTracker(){
    
}

void CoinTracker::tSetup(){
    vidGrabber.setup(cameraWidth,cameraHeight);
    colorImg.allocate(cameraWidth,cameraHeight);
    hueImg.allocate(cameraWidth,cameraHeight); //Hue map
    satImg.allocate(cameraWidth,cameraHeight); //saturation map
    briImg.allocate(cameraWidth,cameraHeight); //brightness map, not gonna be used but necessary
    contourImg.allocate(cameraWidth,cameraHeight);
    trackedColor = new unsigned char [numPixels];
    
    
}

void CoinTracker::tUpdate(){
    bool bNewFrame=false;
    vidGrabber.update();
    bNewFrame =  vidGrabber.isFrameNew();
    
    if (bNewFrame){
        
        colorImg.setFromPixels(vidGrabber.getPixels());
        colorImg.blurGaussian(7);
        colorImg.mirror(false, true);
        colorImg.convertRgbToHsv();
        cout<< "this is the hue:" << int(hueImg.getPixels()[cameraWidth/2*cameraWidth+ cameraHeight/2])<<endl;
       cout<< "this is the sat" <<int(satImg.getPixels()[cameraWidth/2*cameraWidth+ cameraHeight/2])<<endl;
colorImg.convertToGrayscalePlanarImages(hueImg, satImg, briImg); //distribute the hue, saturation and brightness to hueImg, satImg, and briImg
        
        hueImg.flagImageChanged();
        satImg.flagImageChanged();
        briImg.flagImageChanged();

        
     
     
        for (int i = 0; i < numPixels; i++){ //let’s go through every pixel in hue pixels
            if ((hueImg.getPixels()[i] >= minHue && hueImg.getPixels()[i] <= maxHue) && //if the hue is of a certain range
                (satImg.getPixels()[i] >= minSat && satImg.getPixels()[i] <= maxSat)){ //if the saturation is of a certain range
                trackedColor[i] = 255; //mark this corresponding pixel white
            } else {
                trackedColor[i] = 0; //if it doesn’t fit then color the corresponding pixel black
            }
        }
        
        contourImg.setFromPixels(trackedColor, cameraWidth,cameraHeight);
        finderBlue.findContours(contourImg, 10 ,numPixels/3, 1, false, true);
        if (finderBlue.blobs.size()>0){
         coinX = finderBlue.blobs[0].centroid.x;
        coinY = finderBlue.blobs[0].centroid.y;
        
        }
    }
}

void CoinTracker::cameraDisplay(){
    
    colorImg.draw(0,0);
    contourImg.draw(360,0);
    
    glPushMatrix(); //start a new openGL stack
   glTranslatef(360,0,0); //translate lower a bit
   finderBlue.draw(); //draw the contour tracker over the trackedTextureRed
  glPopMatrix(); //end the stack
    
    
}

float CoinTracker::getCoinX(){
    return coinX*900/cameraWidth;
}

float CoinTracker::getCoinY(){
    return coinY*700/cameraHeight;
}
