//
//  ZOIStart.h
//  slideShow
//
//  Created by Andrew Hughes on 2/22/14.
//
//

#ifndef __slideShow__ZOIStart__
#define __slideShow__ZOIStart__

#include <iostream>
#include "ZOIState.h"
#include "ofxTimer.h"
#include "ofMain.h"
#include "ZoneOfInterestAnimator.h"

class ZOIStart : public ZOIState {
    ZoneOfInterestAnimator * parent;
    ofxTimer timer;
    ofRectangle adjustedRect;
public:
    ZOIStart(ZoneOfInterestAnimator* parent);
    void draw();
    bool update();
};


#endif /* defined(__slideShow__ZOIStart__) */
