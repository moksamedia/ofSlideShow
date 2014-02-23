//
//  ZOIEnd.h
//  slideShow
//
//  Created by Andrew Hughes on 2/22/14.
//
//

#ifndef __slideShow__ZOIEnd__
#define __slideShow__ZOIEnd__

#include <iostream>
#include "ZOIState.h"
#include "ofMain.h"
#include "ZoneOfInterestAnimator.h"

class ZOIEnd : public ZOIState {
    ZoneOfInterestAnimator * parent;
public:
    ZOIEnd(ZoneOfInterestAnimator * parent);
    void draw();
    bool update();
};

#endif /* defined(__slideShow__ZOIEnd__) */
