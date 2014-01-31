//
//  SlideShow.cpp
//  slideShow
//
//  Created by Andrew Hughes on 1/27/14.
//
//

/*
 
    ratio = Y / X or Height / Width
 
    if ratioOfScreen > ratioOfImage
    - adjust X to fit image (but leave some blank space)
    - adjust Y to fill screen (but crop image)
 
    if ratioOfScreen < ratioOfImage
    - adjust Y to fit image (but leave some blank space)
    - adjust X to fill screen (but crop image)
 
 
 */

#include "SlideShow.h"
#include "FillAndPanAnimator.h"

bool SlideShow::setup(float screenWidth, float screenHeight, string imageDirectoryPath) {
 
    ofLogNotice("Staring setup");
    
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    this->imageDirectoryPath = imageDirectoryPath;
    
    imageCollection = new ImageCollection(imageDirectoryPath);
    
    img = imageCollection->getNextImage();
    
    animator = new FillAndPanAnimator(img,screenWidth,screenHeight);
    
}

SlideShow::~SlideShow() {
    delete(imageCollection);
    delete(animator);
}

bool SlideShow::update() {
    if (!animator->update()) {
        img = imageCollection->getNextImage();
        delete(animator);
        animator = new FillAndPanAnimator(img,screenWidth,screenHeight);
    }
}

void SlideShow::draw() {
    ofSetColor(255);
    animator->draw();
}




// draw image to fill screen (or get image rect)
// draw image to show entire image (or get image rect)