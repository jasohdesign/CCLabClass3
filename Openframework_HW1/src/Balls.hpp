//
//  Balls.hpp
//  myFirstSketch
//
//  Created by Woo Jung Oh on 11/3/15.
//
#pragma once

#include "ofMain.h"

class Balls{
public:
    Balls();
    
    void setup();
    void update();
    void draw();

    int xPos;
    int xVel;
    
    int yPos;
    int yVel;
    
    int r,g,b;    
    float size;
    
    ofPoint pos;
    ofPoint vel;

    
};
