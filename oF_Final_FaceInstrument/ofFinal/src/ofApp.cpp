#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
    ofSetVerticalSync(true);
    cam.initGrabber(640, 480);
    
    tracker.setup();
    tracker.setRescale(.5);
    
    mouthDrum.load("sound/drum.mp3");
    rightEyeCymbal.load("sound/cymbal.mp3");
    leftEyeBrowShaker.load("sound/shaker.mp3");
    smileHarp.load("sound/smileHarp.mp3");
    nostrilGong.load("sound/nostrilGong.mp3");
}

void ofApp::update() {
    cam.update();
    if(cam.isFrameNew()) {
        if(tracker.update(toCv(cam))) {
            classifier.classify(tracker);
        }
    }
}

void ofApp::draw() {
    ofSetColor(255);
    cam.draw(0, 0);
    tracker.draw();
//    ofSetLineWidth(2);
    
    int w = 100, h = 12;
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(5, 10);
    int n = classifier.size();
    int primary = classifier.getPrimaryExpression();
    for(int i = 0; i < n; i++){
        ofSetColor(i == primary ? ofColor::red : ofColor::black);
        ofRectangle(0, 0, w * classifier.getProbability(i) + .5, h);
        ofSetColor(255);
        ofDrawBitmapString(classifier.getDescription(i), 5, 9);
        ofTranslate(0, h + 5);
    }
    ofPopMatrix();
    ofPopStyle();
    
    ofDrawBitmapString(ofToString((int) ofGetFrameRate()), ofGetWidth() - 20, ofGetHeight() - 10);
    drawHighlightString(
                        string() +
                        "Create music with your face!\n" +
                        "Mouth opened - drum\n" +
                        "Smile - harp\n" +
                        "Eye opened wide - cymbal\n"
                        "Nostril flared-gong",
                        14, ofGetHeight() - 7 * 12);
    
    //MOUTH - When opened wide vertically, makes drum sound
    if (tracker.getGesture(ofxFaceTracker::MOUTH_HEIGHT) > 3.4){
        if (!mouthDrum.isPlaying()) {
            mouthDrum.play();
            
        }

    }else{
        mouthDrum.stop(); //Stop sound if mouth is closed.
    }
    
    //MOUTH - When smiled (opened wide horizontally), makes harp sound
    if (tracker.getGesture(ofxFaceTracker::MOUTH_WIDTH) > 14.0){
        if (!smileHarp.isPlaying()) {
            smileHarp.play();
        }
        
    }else{
        smileHarp.stop(); //Stop sound if mouth is closed.
    }
    
    //RIGHT_EYE - When opened wide, makes cymbal sound
    if (tracker.getGesture(ofxFaceTracker::RIGHT_EYE_OPENNESS) > 3.5){
        cout<< "Right eye openness is"<< tracker.getGesture(ofxFaceTracker::RIGHT_EYE_OPENNESS)<< endl;
        if (!rightEyeCymbal.isPlaying()) {
            rightEyeCymbal.play();
        }
    }else{
        rightEyeCymbal.stop();
    }
    
    //LEFT_EYEBROW - When raised, makes shaker sound
    if (tracker.getGesture(ofxFaceTracker::LEFT_EYEBROW_HEIGHT) > 9.2){
        cout<< "Left eye brow height is"<< tracker.getGesture(ofxFaceTracker::LEFT_EYEBROW_HEIGHT)<< endl;
        if (!leftEyeBrowShaker.isPlaying()) {
            leftEyeBrowShaker.play();
        }
    }else{
        leftEyeBrowShaker.stop();
    }
    
    //NOSTRIL - When nostrils are bigger, makes fire sound
    if (tracker.getGesture(ofxFaceTracker::NOSTRIL_FLARE) > 6.5){
        cout<< "Nostril size is"<< tracker.getGesture(ofxFaceTracker::NOSTRIL_FLARE)<< endl;
        if (!nostrilGong.isPlaying()) {
            nostrilGong.play();
        }
    }else{
       nostrilGong.stop();
    }

}//end of void draw()


//used to console log the measurement of eye openness, mouth width, nostril flare, etc
void ofApp::keyPressed(int key) {
    if(key == 'r') {
        tracker.reset();
        classifier.reset();
    }
    if(key == 'e') {
        classifier.addExpression();
    }
    if(key == 'a') {
        classifier.addSample(tracker);
    }
    if(key == 's') {
        classifier.save("expressions");
    }
    if(key == 'l') {
        classifier.load("expressions");
    }
    if(key == 'm'){
        cout<< tracker.getGesture(ofxFaceTracker::MOUTH_HEIGHT)<< endl;
    }
    if(key == 'b'){
        cout<< tracker.getGesture(ofxFaceTracker::LEFT_EYE_OPENNESS)<< endl;
    }
    if(key == 'u'){
        cout<< tracker.getGesture(ofxFaceTracker::MOUTH_WIDTH)<< endl;
    }
    if(key == 'n'){
        cout<< tracker.getGesture(ofxFaceTracker::NOSTRIL_FLARE)<< endl;
    }

    
}
