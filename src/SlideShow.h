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
#include "Animator.h"
#include "ImageCollection.h"

/*
    Some type of border? Or blur effect?
 */

class SlideShow {
        
    ofImage img;
    
    Animator * animator;
    
    ImageCollection * imageCollection;

public:
    
    ~SlideShow();

    vector<ofFile> imageFiles;
    
    float screenWidth;
    float screenHeight;
    string imageDirectoryPath;
    
    bool setup(float screenWidth, float screenHeight, string imageDirectoryPath);

    bool update();
    void draw();
    
};



#endif /* defined(__slideShow__SlideShow__) */
