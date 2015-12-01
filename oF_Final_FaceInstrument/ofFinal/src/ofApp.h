#pragma once

#include "ofMain.h"
#include "ofxFaceTracker.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    
    ofVideoGrabber cam;
    ofxFaceTracker tracker;
    ExpressionClassifier classifier;
    
    ofSoundPlayer mouthDrum;
    ofSoundPlayer rightEyeCymbal;
    ofSoundPlayer leftEyeBrowShaker;
    ofSoundPlayer smileHarp;
    ofSoundPlayer nostrilGong;
};
