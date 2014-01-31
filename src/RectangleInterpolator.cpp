//
//  RectangleInterpolator.cpp
//  slideShow
//
//  Created by Andrew Hughes on 1/31/14.
//
//

#include "RectangleInterpolator.h"


ofRectangle RectangleInterpolator::linear(ofRectangle r1, ofRectangle r2, float amt) {
    return interpolateRectHelper(r1,r2,amt,&ofLerp);
}

ofRectangle RectangleInterpolator::interpolateRectHelper(ofRectangle r1, ofRectangle r2, float amt, float (*func)(float,float,float)) {
    
    ofRectangle result;
    
    result.setX(func(r1.getX(), r2.getX(), amt));
    result.setY(func(r1.getY(), r2.getY(), amt));
    result.setHeight(func(r1.getHeight(), r2.getHeight(), amt));
    result.setWidth(func(r1.getWidth(), r2.getWidth(), amt));
    
    return result;

}
