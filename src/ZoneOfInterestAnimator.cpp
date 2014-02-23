//
//  ZoneOfInterestAnimator.cpp
//  slideShow
//
//  Created by Andrew Hughes on 1/31/14.
//
//

#include "ZoneOfInterestAnimator.h"
#include "ofxTimer.h"


ZoneOfInterestAnimator::ZoneOfInterestAnimator(ofImage img, float windowWidth, float windowHeight, vector<ofRectangle> zones) : Animator(img,windowWidth,windowHeight) {
    
    for(ofRectangle rect : zones) {
        ofRectangle newRect = ofRectangle(rect.x, rect.y, rect.width, rect.height);ofRectangle(rect.x, rect.y, rect.width, rect.height);
        this->zonesOfInterest.push_back(newRect);
    }
    
    if (zonesOfInterest.size() < 2) {
        throw "Not enough zones of interest!";
    }
   
    state = new ZOIStart((void*)this);
    fromZone = &zonesOfInterest[0];
    toZone = &zonesOfInterest[1];
    
    currentFromZoneIndex = 0;
    
    image = img;
}

ZoneOfInterestAnimator::~ZoneOfInterestAnimator() {

}

bool ZoneOfInterestAnimator::update() {
    ofRectangle currentZone = zonesOfInterest.back();
    currentAdjustedRect = getAdjustedZoneRectForScreenAspect(&currentZone);
    return true;
}

void ZoneOfInterestAnimator::draw() {
    image.drawSubsection(0,0,windowWidth,windowHeight,
                         currentAdjustedRect.getX(),currentAdjustedRect.getY(),
                         currentAdjustedRect.getWidth(),currentAdjustedRect.getHeight());
}


/*
 * Returns a rectangle that is the smallest rectangle that fits the zone of interest rect
 * completely and is centered to the same point.
 */
ofRectangle ZoneOfInterestAnimator::getAdjustedZoneRectForScreenAspect(ofRectangle * zoneRect) {
    
    float screenRatio = windowHeight / windowWidth;
    
    float imageRatio = image.getHeight() / image.getWidth();
    
    ofRectangle adjustedRect;
    
    adjustedRect.setFromCenter(zoneRect->getCenter(), windowWidth, windowHeight);

    /*
     * If screenRatio > imageRatio, the screen is comparatively taller than the
     * image, thus the image's width must be adjusted so that it will fit the
     * screen's width
     */
    if (screenRatio > imageRatio) {

        float scaleRatio = zoneRect->getWidth() / adjustedRect.getWidth();
        
        adjustedRect.scaleFromCenter(scaleRatio);
        
    }
    else {
        
        float scaleRatio = zoneRect->getHeight() / adjustedRect.getHeight();
        
        adjustedRect.scaleFromCenter(scaleRatio);
        
    }
    
    return adjustedRect;

}
