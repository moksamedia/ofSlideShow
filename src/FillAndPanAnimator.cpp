//
//  FillAndPanAnimator.cpp
//  slideShow
//
//  Created by Andrew Hughes on 1/31/14.
//
//

#include "FillAndPanAnimator.h"
#include "RectangleInterpolator.h"

/*
 
 ratio = Y / X or Height / Width
 
 if ratioOfScreen > ratioOfImage
 - adjust X to fit image (but leave some blank space)
 - adjust Y to fill screen (but crop image)
 
 if ratioOfScreen < ratioOfImage
 - adjust Y to fit image (but leave some blank space)
 - adjust X to fill screen (but crop image)
 
 
 */


bool FillAndPanAnimator::update() {
    
    if (count > max) {
        return false;
    }
    
    float val = (float)count / (float)max;
    
    currentRect = RectangleInterpolator::linear(fromRect, toRect, val);
    
    count++;
    
    return true;

}

void FillAndPanAnimator::draw() {
    image.drawSubsection(0.0, 0.0, screenWidth, screenHeight, currentRect.getX(), currentRect.getY());
}

FillAndPanAnimator::FillAndPanAnimator(ofImage img, float screenWidth, float screenHeight) : Animator(img,screenWidth,screenHeight) {
    
    float screenRatio = screenHeight / screenWidth;
    
    float imageRatio = image.getHeight() / image.getWidth();
    
    /*
     * If screenRatio > imageRatio, the screen is comparatively taller than the
     * image, thus the image's height must be adjusted to fit the height of the
     * screen and the image will be panned along the X axis.
     */
    if (screenRatio > imageRatio) {
        
        fromRect.setHeight(screenHeight);
        fromRect.setWidth(screenWidth);
        fromRect.setX(0);
        fromRect.setY(0);
        
        float newImageHeight = screenHeight;
        float newImageWidth = image.getWidth() * (screenHeight / image.getHeight());

        image.resize(newImageWidth, newImageHeight);
        
        toRect.setHeight(screenHeight);
        toRect.setWidth(screenWidth);
        /*
         * Image should be wider than the screen, so we want to pan 
         * the length of the difference.
         */
        distanceInPixelsToPan = newImageWidth - screenWidth;
        toRect.setX(distanceInPixelsToPan);
        toRect.setY(0);
        
    }
    
    /*
     * If screenRatio < imageRatio, the screen is WIDER than the image,
     * thus the image must be adjusted to fill the screen horizontally,
     * and will be panned vertically.
     */
    else {
        
        // Resize image, stretching horizontally
        float newImageWidth = screenWidth;
        float newImageHeight = image.getHeight() * (screenWidth / image.getWidth());
        image.resize(newImageWidth, newImageHeight);

        fromRect.setHeight(screenHeight);
        fromRect.setWidth(screenWidth);
        fromRect.setX(0);
        fromRect.setY(0);

        toRect.setHeight(screenHeight);
        toRect.setWidth(screenWidth);
        toRect.setX(0);
        distanceInPixelsToPan = newImageHeight - screenHeight;
        toRect.setY(distanceInPixelsToPan);

    }
    
    max = 30 * (distanceInPixelsToPan / pixelsPerSecond);
    
    
}
