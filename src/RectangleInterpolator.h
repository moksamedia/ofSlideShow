//
//  RectangleInterpolator.h
//  slideShow
//
//  Created by Andrew Hughes on 1/31/14.
//
//

#ifndef __slideShow__RectangleInterpolator__
#define __slideShow__RectangleInterpolator__

#include <iostream>
#include "ofMain.h"

class RectangleInterpolator {
public:
    
    ofRectangle static linear(ofRectangle r1, ofRectangle r2, float amt);
    ofRectangle static interpolateRectHelper(ofRectangle r1, ofRectangle r2, float amt, float (*func)(float,float,float));
};

#endif /* defined(__slideShow__RectangleInterpolator__) */
