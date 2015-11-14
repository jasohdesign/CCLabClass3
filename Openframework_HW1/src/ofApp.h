#pragma once

#include "ofMain.h"
#include "Balls.hpp"
#define NUMBEROFBALLS 20

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

        int xPos;
        int xVel;
    
        int yPos;
        int yVel;
    
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
        void Bounce();
    
    Balls myBalls;
    Balls arrayOfBalls[NUMBEROFBALLS];
    
    int r;
    int g;
    int b;
    
};
