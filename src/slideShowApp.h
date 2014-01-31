#pragma once

#include "ofMain.h"
#include "SlideShow.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 1000

#define BACKGROUND_COLOR 0x000000

class slideShowApp: public ofBaseApp{
    
    SlideShow slideShow;
        
	public:
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
