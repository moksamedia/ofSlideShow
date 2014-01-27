//
//  SlideShow.h
//  slideShow
//
//  Created by Andrew Hughes on 1/27/14.
//
//

#ifndef __slideShow__SlideShow__
#define __slideShow__SlideShow__

#include <iostream>
#include "ofMain.h"


/*
    Some type of border? Or blur effect?
 */

class SlideShow {
    
    bool extensionIsImage(string ext);

public:

    vector<ofFile> imageFiles;
    
    float screenWidth;
    float screenHeight;
    string imageDirectoryPath;
    
    bool setup(float screenWidth, float screenHeight, string imageDirectoryPath);


    ofPoint getPointOfInterestForImage(ofImage image);
    ofRectangle getRectangleOfInterestForPoint(ofPoint point);

    int loadImageFilesFromDirectory(string dir);

    string chooseNextImageFromVector(vector<string> imageFileNames);

    ofImage loadImage(string imageFileName);
    

    
    
};



#endif /* defined(__slideShow__SlideShow__) */
