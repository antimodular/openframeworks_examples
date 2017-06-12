#pragma once

#include "ofMain.h"
#include "ofxCv.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	
	ofVideoGrabber cam;
    
    cv::Mat croppedCamMat;
	ofImage croppedImage;
    ofImage croppedImage2;
    ofImage croppedImage3;
    ofPixels croppedPixels3;
    
    ofRectangle roiRect;
    ofRectangle camRect;
};
