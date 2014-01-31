//
//  Animator.cpp
//  slideShow
//
//  Created by Andrew Hughes on 1/31/14.
//
//

#include "Animator.h"

Animator::Animator(ofImage img, float screenWidth, float screenHeight) {
    image = img;
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
}

Animator::~Animator() {
    
}