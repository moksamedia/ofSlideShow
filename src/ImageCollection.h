//
//  ImageCollection.h
//  slideShow
//
//  Created by Andrew Hughes on 1/31/14.
//
//

#ifndef __slideShow__ImageCollection__
#define __slideShow__ImageCollection__

#include <iostream>
#include "ofMain.h"


class ImageCollection {
    
    string imageDirectoryPath;
    vector<ofFile> imageFiles;
    
    int currentImageIndex = 0;
    
    ofImage currentImage;
    
public:
    
    ImageCollection(string pathToImageFilesDirectory);
    
    int getNumberOfImages();
    
    ofImage getNextImage();
    
    bool extensionIsImage(string ext);
    
private:
    
    void loadImageFilesFromDirectory(string dir);
    ofImage loadImage(string imageFilePath);
    

};

#endif /* defined(__slideShow__ImageCollection__) */
