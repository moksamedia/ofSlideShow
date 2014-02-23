//
//  ZOITransition.h
//  slideShow
//
//  Created by Andrew Hughes on 2/22/14.
//
//

#ifndef __slideShow__ZOITransition__
#define __slideShow__ZOITransition__

#include <iostream>
#include "ZOIState.h"
#include "ofMain.h"

class ZOITransition : public ZOIState {
public:
    ZOITransition(void * parent);
    void draw();
    bool update();
};


#endif /* defined(__slideShow__ZOITransition__) */
