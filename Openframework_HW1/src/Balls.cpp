//
//  Balls.cpp
//  myFirstSketch
//
//  Created by Woo Jung Oh on 11/3/15.
//
//

#include "Balls.hpp"

Balls::Balls(){
   
}

void Balls::setup(){
    xPos = ofRandomWidth();
    xVel = 5;
    
    yPos = ofRandomHeight();
    yVel = 5;
}
void Balls::update(){
    xPos += xVel;
    yPos += yVel;
    
    if (xPos >= ofGetWidth()-35 || xPos < 35){
        xVel *= (-1);
    }
    
    if (yPos >= ofGetHeight()-35 || yPos < 0){
        yVel *= (-1);
    }
}
void Balls::draw(){
    ofSetColor(255, 0, 127);
    ofEllipse(xPos, yPos, 70, 70);
}