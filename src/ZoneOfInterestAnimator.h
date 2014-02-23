//
//  ZoneOfInterestAnimator.h
//  slideShow
//
//  Created by Andrew Hughes on 1/31/14.
//
//

#ifndef __slideShow__ZoneOfInterestAnimator__
#define __slideShow__ZoneOfInterestAnimator__

#include <iostream>
#include "ofMain.h"
#include "Animator.h"
#include "ZOIState.h"
#include "ZOIStart.h"
#include "ZOIEnd.h"
#include "ZOITransition.h"


class ZoneOfInterestAnimator : public Animator {
    
    friend class ZOIStart;
    friend class ZOIEnd;
    friend class ZOITransition;
    
protected:
   
    ZOIState * state;
    
    ofRectangle * fromZone;
    ofRectangle * toZone;
    
    unsigned currentFromZoneIndex;
    
    vector<ofRectangle> zonesOfInterest;
    ofImage image;
    ofRectangle currentAdjustedRect;
    
public:
    
    ZoneOfInterestAnimator(ofImage img, float windowWidth, float windowHeight, vector<ofRectangle> zones);
    
    ~ZoneOfInterestAnimator();

    void draw();
    bool update();
    
    ofRectangle getAdjustedZoneRectForScreenAspect(ofRectangle * zoneRect);
    
};

#endif /* defined(__slideShow__ZoneOfInterestAnimator__) */
