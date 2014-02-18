//
//  Animator.h
//  slideShow
//
//  Created by Andrew Hughes on 1/31/14.
//
//

#ifndef __slideShow__Animator__
#define __slideShow__Animator__

#include <iostream>
#include "ofMain.h"

class Animator {

protected:
    
    ofImage image;
    float windowWidth;
    float windowHeight;
    
public:
    
    Animator(ofImage img, float screenWidth, float screenHeight);
    
    /*
     *  Called to perform the draw.
     */
    virtual void draw() = 0;

    /*
     *  Update is called until the animation is finished and
     *  the method returns false.
     */
    virtual bool update() = 0;
    
    virtual ~Animator();
    
};

#endif /* defined(__slideShow__Animator__) */
