//
//  zoneManagerApp.cpp
//  zoneOfInterestManager
//
//  Created by Andrew Hughes on 2/1/14.
//
//

#include "zoneManagerApp.h"

void zoneManagerApp::exit()
{
    delete guiImageFiles;
    delete guiZones;
    delete guiControls;
}

void zoneManagerApp::guiEventZones(ofxUIEventArgs &e) {
    
    if (!mousePressedFlag) return;

    string name = e.getName();
    for (ZoneOfInterest *zone : zones ) {
        if (zone->name == name) {
            //zone->setState(!zone->getState());
        }
    }
}



void zoneManagerApp::guiEventControls(ofxUIEventArgs &e) {
    
    // filter out button up events
    if (!((ofxUIButton*)e.widget)->getValue()) {
        return;
    }
    
    string name = e.getName();
    if (name == "WRITE TO FILE" && currentImageFileName != "") {
        
        string path = IMAGE_DIR_PATH;
        string filepath = path + "/" + currentImageFileName.substr(0,currentImageFileName.find_last_of('.')) + ".zns";
        
        ofFile file(filepath, ofFile::WriteOnly);
        
        for(ZoneOfInterest* zone : zones) {
            file << zone->rect << "\n";
        }
        file.close();
        
    }
    else if (name == "DELETE ALL ZONES") {
        guiZones->removeWidgets();
        zones.clear();
    }
    else if (name == "SWAP SELECTION") {
        for(ZoneOfInterest* zone : zones) {
            zone->toggleState();
        }
    }
    else if (name == "CLEAR SELECTION") {
        for(ZoneOfInterest* zone : zones) {
            zone->setState(false);
        }
    }
    else if (name == "SELECT ALL") {
        for(ZoneOfInterest* zone : zones) {
            zone->setState(true);
        }
    }
 }

void zoneManagerApp::guiEventFiles(ofxUIEventArgs &e)
{
    
    if (!mousePressedFlag) return;

    // clear all buttons
    vector<ofxUIWidget*> imageButtons = guiImageFiles->getWidgetsOfType(OFX_UI_WIDGET_BUTTON);
    for (ofxUIWidget* button : imageButtons) {
        ((ofxUIButton*)button)->setValue(false);
    }

    // clear zones
    clearZones();
    
    // load image
    image = imageCollection->loadImageForName(e.getName());
    currentImageFileName = e.getName();
    
    // adjust image to fit window area
    adjustedRect = getAdjustedRectToFitRect(ofRectangle(0,0,image.width, image.height), ofRectangle(OFFSET_FOR_CONTROLS,0,ofGetViewportWidth()-OFFSET_FOR_CONTROLS,ofGetViewportHeight()));
    
    // set button to on state
    e.getButton()->setValue(true);
    
}

//--------------------------------------------------------------
void zoneManagerApp::setup(){
    
    imageCollection = new ImageCollection(IMAGE_DIR_PATH);

    guiControls = new ofxUICanvas(0,0,OFFSET_FOR_CONTROLS,WINDOW_HEIGHT);
    guiControls->addButton("WRITE TO FILE", false);
    guiControls->addButton("DELETE ALL ZONES", false);
    guiControls->addButton("SWAP SELECTION", false);
    guiControls->addButton("CLEAR SELECTION", false);
    guiControls->addButton("SELECT ALL", false);

    guiControls->autoSizeToFitWidgets();
    guiControls->setWidth(OFFSET_FOR_CONTROLS);
    
    float guiControlsHeight = guiControls->getRect()->getHeight();
    
    ofAddListener(guiControls->newGUIEvent, this, &zoneManagerApp::guiEventControls);

    guiZones = new ofxUICanvas(0,guiControlsHeight,OFFSET_FOR_CONTROLS,WINDOW_HEIGHT/2-guiControlsHeight);

    guiImageFiles = new ofxUICanvas(0,WINDOW_HEIGHT/2,OFFSET_FOR_CONTROLS,WINDOW_HEIGHT);
    
    
    guiImageFiles->addLabel("IMAGE FILES", OFX_UI_FONT_MEDIUM);
    guiZones->addLabel("ZONES", OFX_UI_FONT_MEDIUM);
    
    guiImageFiles->setWidgetFontSize(OFX_UI_FONT_MEDIUM);
    guiZones->setWidgetFontSize(OFX_UI_FONT_MEDIUM);

    vector<string> imageFileNames = imageCollection->getImageFileNames();
    
    for (string name : imageFileNames) {
        guiImageFiles->addButton(name, false);
    }
    
    ofAddListener(guiImageFiles->newGUIEvent, this, &zoneManagerApp::guiEventFiles);
    ofAddListener(guiZones->newGUIEvent, this, &zoneManagerApp::guiEventZones);

}

vector<string> zoneManagerApp::getListOfZones() {
    
    vector<string> listOfZones;
    
    for (ZoneOfInterest * zone : zones) {
        listOfZones.push_back(zone->name);
    }
    
    return listOfZones;
    
}

void zoneManagerApp::clearZones() {
    for (ZoneOfInterest * zone : zones) {
        delete zone;
    }
    zones.clear();
    //guiZones->removeWidgets();
}

string zoneManagerApp::getNameForZone(ofRectangle zone) {
    ostringstream nameStream;
    nameStream << " ( " << zone.x << " , " << zone.y << " ) ";
    return nameStream.str();
}

/*
 * Returns a rectangle that is the smallest rectangle that fits the zone of interest rect
 * completely and is centered to the same point.
 */
ofRectangle zoneManagerApp::getAdjustedRectToFitRect(ofRectangle toFit, ofRectangle fitTo) {
    
    float fitToRatio = fitTo.getHeight() / fitTo.getWidth();
    
    float toFitRatio = toFit.getHeight() / toFit.getWidth();
    
    ofRectangle adjustedRect;
    
    adjustedRect.setFromCenter(fitTo.getCenter(), toFit.getWidth(), toFit.getHeight());
    
    /*
     * If fitTo is taller and skinnier than toFit, we need to adjust the width
     * of toFit
     */
    if (fitToRatio > toFitRatio) {
        
        float scaleRatio = fitTo.getWidth() / adjustedRect.getWidth();
        
        adjustedRect.scaleFromCenter(scaleRatio);
        
    }
    else {
        
        float scaleRatio = fitTo.getHeight() / adjustedRect.getHeight();
        
        adjustedRect.scaleFromCenter(scaleRatio);
        
    }
    
    return adjustedRect;
    
}


//--------------------------------------------------------------
void zoneManagerApp::update(){
    
}

//--------------------------------------------------------------
void zoneManagerApp::draw(){
    
    if (image.isAllocated()) {
        ofSetColor(255,255,255);
        image.draw(adjustedRect.x, adjustedRect.y, adjustedRect.width, adjustedRect.height);
        if (isDragging) {
            ofSetColor(0,255,255);
            ofNoFill();
            ofRect(draggingStartPoint.x,draggingStartPoint.y,mouseX-draggingStartPoint.x,mouseY-draggingStartPoint.y);
        }
    }
    
    ofNoFill();
    
    for (ZoneOfInterest * zone : zones) {
        if (zone->getState()) {
            ofRectangle rect = zone->rect;
            ofSetColor(255,255,255);
            ofRect(rect);
            ofSetColor(255,0,0);
            ofRect(rect.x-2, rect.y-2, rect.width+4, rect.height+4);
        }
    }
}

//--------------------------------------------------------------
void zoneManagerApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void zoneManagerApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void zoneManagerApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void zoneManagerApp::mouseDragged(int x, int y, int button){
    if (!isDragging && adjustedRect.inside(x, y)) {
        isDragging = true;
        draggingStartPoint.x = x;
        draggingStartPoint.y = y;
    }
    mouseX = x;
    mouseY = y;
}

//--------------------------------------------------------------
void zoneManagerApp::mousePressed(int x, int y, int button) {
    mousePressedFlag = true;
}

//--------------------------------------------------------------
void zoneManagerApp::mouseReleased(int x, int y, int button) {
    mousePressedFlag = false;
    if (isDragging) {
        isDragging = false;
        ofRectangle newZone;
        newZone.x = draggingStartPoint.x;
        newZone.y = draggingStartPoint.y;
        newZone.width = x - draggingStartPoint.x;
        newZone.height = y - draggingStartPoint.y;
        ZoneOfInterest* pZoi = new ZoneOfInterest(newZone);
        zones.push_back(pZoi);
        pZoi->toggle = guiZones->addLabelToggle(pZoi->name, true);
    }
}

//--------------------------------------------------------------
void zoneManagerApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void zoneManagerApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void zoneManagerApp::dragEvent(ofDragInfo dragInfo){
    
}
