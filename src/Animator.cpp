//
//  Animator.cpp
//  slideShow
//
//  Created by Andrew Hughes on 1/31/14.
//
//

#include "Animator.h"

Animator::Animator(ofImage img, float windowWidth, float windowHeight) {
    image = img;
    this->windowWidth = windowWidth;
    this->windowHeight = windowHeight;
}

Animator::~Animator() {
    
}