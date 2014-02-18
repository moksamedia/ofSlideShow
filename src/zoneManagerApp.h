//
//  zoneManagerApp.h
//  zoneOfInterestManager
//
//  Created by Andrew Hughes on 2/1/14.
//
//

#pragma once

#include <iostream>
#include "ofMain.h"
#include "ofxUI.h"
#include "ImageCollection.h"

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 1000
#define OFFSET_FOR_CONTROLS 200

#define IMAGE_DIR_PATH "/Users/cantgetnosleep/test_image_folder"

class ZoneOfInterest {
    
public:
    ofRectangle rect;
    string name;
    ofxUILabelToggle * toggle;
    
    ZoneOfInterest(ofRectangle rect) {
        this->rect = rect;
        name = getNameForZone(rect);
    }
    
    bool getState() {
        return toggle->getValue();
    }
    
    bool setState(bool state) {
        toggle->setValue(state);
    }
    
    void toggleState() {
        toggle->toggleValue();
    }
        
    static string getNameForZone(ofRectangle zone) {
        ostringstream nameStream;
        nameStream << "( " << zone.x << " , " << zone.y << " )";
        return nameStream.str();
    }
    
};

class zoneManagerApp : public ofBaseApp {
    
    
public:
    
    ofxUICanvas *guiControls;

    ofxUICanvas *guiZones;
    
    ofxUICanvas *guiImageFiles;
    
    ofxUIDropDownList *zonesDDL;

    ofImage image;
    
    ImageCollection * imageCollection;
    
    string currentImageFileName;
    
    ofRectangle adjustedRect;
    
    bool mousePressedFlag = true;
    
    vector<ZoneOfInterest*> zones;
    vector<string> getListOfZones();
    void clearZones();
    
    bool isDragging = false;
    ofPoint draggingStartPoint;
    int mouseX;
    int mouseY;
    
    void exit();
    void guiEventFiles(ofxUIEventArgs &e);
    void guiEventZones(ofxUIEventArgs &e);
    void guiEventControls(ofxUIEventArgs &e);
   
    ofRectangle getAdjustedRectToFitRect(ofRectangle toFit, ofRectangle fitTo);
    
    string getNameForZone(ofRectangle zone);

    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
};
