//
//  ZOIStart.cpp
//  slideShow
//
//  Created by Andrew Hughes on 2/22/14.
//
//

#include "ZOIStart.h"

/*
 * Start
 * - pause on zone fromZone
 * - when time is up, set state to transition
 */

ZOIStart::ZOIStart(ZoneOfInterestAnimator * parent) {
    this->parent = parent;
    
    timer.setup(30000, false);
    timer.startTimer();
    adjustedRect = parent->getAdjustedZoneRectForScreenAspect(parent->fromZone);
    
}

bool ZOIStart::update() {

}

void ZOIStart::draw() {

}
