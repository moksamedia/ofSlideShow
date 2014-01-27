//
//  SlideShow.cpp
//  slideShow
//
//  Created by Andrew Hughes on 1/27/14.
//
//

/*
 
    ratio = Y / X or Height / Width
 
    if ratioOfScreen > ratioOfImage
    - adjust X to fit image (but leave some blank space)
    - adjust Y to fill screen (but crop image)
 
    if ratioOfScreen < ratioOfImage
    - adjust Y to fit image (but leave some blank space)
    - adjust X to fill screen (but crop image)
 
 
 */

#include "SlideShow.h"

bool SlideShow::setup(float screenWidth, float screenHeight, string imageDirectoryPath) {
 
    ofLogNotice("Staring setup");
    
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    this->imageDirectoryPath = imageDirectoryPath;
    
    this->loadImageFilesFromDirectory(imageDirectoryPath);
    
}


int SlideShow::loadImageFilesFromDirectory(string directoryPath) {
    
    ofDirectory dir(directoryPath);
    
    if (!dir.exists()) {
        ofLogError("Image directory path does not exist: " + imageDirectoryPath);
        throw ("Image directory path does not exist: " + imageDirectoryPath);
    }

    dir.listDir();

    vector<ofFile> files = dir.getFiles();
        
    // get number of image files
    for (ofFile file : files) {
        if (this->extensionIsImage(file.getExtension())) {
            imageFiles.push_back(file);
        }
    }
    
    if (imageFiles.size() <= 0) {
        ofLogError("No image files found!");
        throw("No image files found!!!");
    }
    else {
        ofLogNotice() << imageFiles.size() << " image file found.";
    }
    
}

bool SlideShow::extensionIsImage(string ext) {
    return ext == "png" || ext == "jpg" || ext == "jpeg";
}

ofPoint SlideShow::getPointOfInterestForImage(ofImage image) {
    
}

ofRectangle SlideShow::getRectangleOfInterestForPoint(ofPoint point) {
    
}


string SlideShow::chooseNextImageFromVector(vector<string> imageFileNames) {
    
}

ofImage SlideShow::loadImage(string imageFileName) {
    
}

// draw image to fill screen (or get image rect)
// draw image to show entire image (or get image rect)