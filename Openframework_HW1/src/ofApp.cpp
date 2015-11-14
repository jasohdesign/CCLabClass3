#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
//    xPos = ofRandomWidth();
//    xVel = 5;
//    xDir = 1;
//    
//    yPos = ofRandomHeight();
//    yVel = 5;
//    yDir = 1;
//
    
    for (int i=0; i< NUMBEROFBALLS; i++) {
        arrayOfBalls[i].setup();
    }
}

//--------------------------------------------------------------
void ofApp::update(){
//    xPos += xVel;
//    yPos += yVel;
//    
//    if (xPos >= ofGetWidth()-35 || xPos < 35){
//        xVel *= (-1);
//    }
//    
//    
//    if (yPos >= ofGetHeight()-35 || yPos < 0){
//        yVel *= (-1);
//    }
//
    myBalls.update();
    
    for (int i=0; i< NUMBEROFBALLS; i++) {
        arrayOfBalls[i].update();
    }
}

//--------------------------------------------------------------
    void ofApp::draw(){
    //Draw Ball
//    ofSetCircleResolution(8);
//    ofSetColor(255, 0, 127);
//    ofEllipse(xPos, yPos, 70, 70);
//    
    myBalls.draw();
    
    for (int i=0; i< NUMBEROFBALLS; i++) {
        arrayOfBalls[i].draw();
    }
}

//function to bounce ball---------------------------------------
void ofApp::Bounce(){
    
    }

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
