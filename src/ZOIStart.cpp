//
//  ZOIStart.cpp
//  slideShow
//
//  Created by Andrew Hughes on 2/22/14.
//
//

#include "ZOIStart.h"
#include "ZoneOfInterestAnimator.h"

/*
 * Start
 * - pause on zone fromZone
 * - when time is up, set state to transition
 */

ZOIStart::ZOIStart(void * parent): ZOIState(parent) {
    ZoneOfInterestAnimator * p = (ZoneOfInterestAnimator*)parent;
    
    timer.setup(30000, false);
    timer.startTimer();
    adjustedRect = p->getAdjustedZoneRectForScreenAspect(p->fromZone);
    
}

bool ZOIStart::update() {
    ZoneOfInterestAnimator * p = (ZoneOfInterestAnimator*)parent;

}

void ZOIStart::draw() {
    ZoneOfInterestAnimator * p = (ZoneOfInterestAnimator*)parent;

}
