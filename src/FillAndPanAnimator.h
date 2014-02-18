//
//  FillAndPanAnimator.h
//  slideShow
//
//  Created by Andrew Hughes on 1/31/14.
//
//

#ifndef __slideShow__FillAndPanAnimator__
#define __slideShow__FillAndPanAnimator__

#include <iostream>
#include "ofMain.h"
#include "Animator.h"

class FillAndPanAnimator : public Animator {
    
    ofRectangle fromRect;
    ofRectangle toRect;
    ofRectangle currentRect;
    
    float distanceInPixelsToPan;

    int count = 0;
    float pixelsPerSecond = 10.0;
    int max;
    
    
public:
    FillAndPanAnimator(ofImage img, float windowWidth, float windowHeight);
    
    void draw();
    bool update();
    
};

#endif /* defined(__slideShow__FillAndPanAnimator__) */
