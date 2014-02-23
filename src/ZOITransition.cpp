//
//  ZOITransition.cpp
//  slideShow
//
//  Created by Andrew Hughes on 2/22/14.
//
//

#include "ZOITransition.h"



/*
 * Transition
 * - interpolate between fromZone to toZone
 * - when toZone is reached, set state to end
 */

ZOITransition::ZOITransition(ZoneOfInterestAnimator * parent) {
    this->parent = parent;
}

bool ZOITransition::update() {
}

void ZOITransition::draw() {
}
