//
//  ofxTimer.h
//  slideShow
//
//  Created by Andrew Hughes on 1/31/14.
//
//

#ifndef __slideShow__ofxTimer__
#define __slideShow__ofxTimer__

#include <iostream>
#include "ofMain.h"

class ofxTimer {
    
private:
    
    // timer
    bool            bLoop;
    bool            bPauseTimer;
    bool            bStartTimer;
    float           delay;
    float           timer;
    float           timerStart;
    
    void update(ofEventArgs &e);
    
public:
    
    ofEvent <ofEventArgs> TIMER_REACHED;
    
    ofxTimer();
    ~ofxTimer();
    
    // ---------------------------------------
    void setup(float millSeconds, bool loopTimer);
    //void draw();
    
    // ---------------------------------------
    void setTimer(float millSeconds);
    void startTimer();
    void stopTimer();
    void loop(bool b);
};

#endif /* defined(__slideShow__ofxTimer__) */
