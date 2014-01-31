//
//  ImageCollection.cpp
//  slideShow
//
//  Created by Andrew Hughes on 1/31/14.
//
//

#include "ImageCollection.h"

ImageCollection::ImageCollection(string pathToImageFilesDirectory) {
    
    imageDirectoryPath = pathToImageFilesDirectory;
    
    this->loadImageFilesFromDirectory(imageDirectoryPath);
    
}

ofImage ImageCollection::getNextImage() {
    
    if (currentImageIndex >= getNumberOfImages()) {
        currentImageIndex = 0;
    }
    
    currentImage.loadImage(imageFiles[currentImageIndex].getAbsolutePath());
    
    currentImageIndex++;
    
    return currentImage;
}

int ImageCollection::getNumberOfImages() {
    return imageFiles.size();
}


void ImageCollection::loadImageFilesFromDirectory(string directoryPath) {
    
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

bool ImageCollection::extensionIsImage(string ext) {
    return ext == "png" || ext == "jpg" || ext == "jpeg";
}

ofImage ImageCollection::loadImage(string imageFilePath) {
    ofImage toLoad;
    toLoad.loadImage(imageFilePath);
    return toLoad;
}