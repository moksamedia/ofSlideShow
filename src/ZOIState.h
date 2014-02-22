//
//  ZOIState.h
//  slideShow
//
//  Created by Andrew Hughes on 2/22/14.
//
//

#ifndef slideShow_ZOIState_h
#define slideShow_ZOIState_h

#include "ZoneOfInterestAnimator.h"

class ZOIState {
    friend class ZoneOfInterestAnimator;
    
protected:
    void * parent;
    
public:
    ZOIState(void * parent);
    void draw();
    bool update();
};

class ZOIStart : public ZOIState {
public:
    ZOIStart(void * parent);
    void draw();
    bool update();
};

class ZOITransition : public ZOIState {
public:
    ZOITransition(void * parent);
    void draw();
    bool update();
};

class ZOIEnd : public ZOIState {
public:
    ZOIEnd(void * parent);
    void draw();
    bool update();
};


#endif
