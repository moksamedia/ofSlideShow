//
//  ofxTimer.cpp
//  slideShow
//
//  Created by Andrew Hughes on 1/31/14.
//
//

#include "ofxTimer.h"


ofxTimer::ofxTimer() {
    
}

ofxTimer::~ofxTimer() {
    printf("*** Timer Destroyed ***\n");
}

// ---------------------------------------

void ofxTimer::setup(float millSeconds, bool loopTimer) {
    
    bLoop           = loopTimer;
    bPauseTimer = false;
    
    //timer
    bStartTimer = true;
    delay           = millSeconds;  // mill seconds
    timer           = 0;
    timerStart      = 0;
    
    //events
    ofAddListener(ofEvents().update, this, &ofxTimer::update);
    
}

// ---------------------------------------
void ofxTimer::loop(bool b) {
    bLoop = b;
}

// ---------------------------------------
void ofxTimer::update(ofEventArgs &e) {
    if(!bPauseTimer) {
        if(bStartTimer) {
            bStartTimer = false;
            timerStart  = ofGetElapsedTimef();
        }
        
        float time = ofGetElapsedTimef() - timerStart;
        time *= 1000.0;
        if(time >= delay) {
            if(!bLoop) bPauseTimer = true;
            bStartTimer = true;
            static ofEventArgs timerEventArgs;
            ofNotifyEvent(TIMER_REACHED, timerEventArgs, this);
        }
    }
}

// ---------------------------------------
void ofxTimer::setTimer(float millSeconds) {
    delay = millSeconds;
}

void ofxTimer::startTimer() {
    bPauseTimer = false;
}

void ofxTimer::stopTimer() {
    bPauseTimer = true;
}