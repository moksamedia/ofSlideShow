//
//  ZOIState.h
//  slideShow
//
//  Created by Andrew Hughes on 2/22/14.
//
//

#ifndef slideShow_ZOIState_h
#define slideShow_ZOIState_h

class ZOIState {
protected:
    void * parent;
public:
    ZOIState(void * parent) {
        this->parent = parent;
    }
    virtual void draw() = 0;
    virtual bool update() = 0;
};


#endif
