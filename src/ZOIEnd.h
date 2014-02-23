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


class ZOIEnd : public ZOIState {
public:
    ZOIEnd(void * parent);
    void draw();
    bool update();
};

#endif /* defined(__slideShow__ZOIEnd__) */
