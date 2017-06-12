#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
    ofSetVerticalSync(true);
    ofSetFrameRate(120);
    
    
    cam.setup(640, 480);
    croppedImage.allocate(100,100, OF_IMAGE_COLOR);
    croppedImage3.allocate(100,100, OF_IMAGE_COLOR);
    croppedPixels3.allocate(100,100, OF_IMAGE_COLOR);
    
    camRect = ofRectangle(0,0,cam.getWidth(),cam.getHeight());
    
   
}

void ofApp::update() {
    cam.update();
    if(cam.isFrameNew()) {
        
        roiRect = ofRectangle(ofGetMouseX(),ofGetMouseY(),100,100);
        
        if(camRect.inside(roiRect)){
            
            cv::Rect roi(toCv(roiRect));
            
            //option 1
            Mat camMat = toCv(cam);
            Mat temp_croppedCamMat = camMat(roi);
            
            resize(temp_croppedCamMat, croppedImage);
            croppedImage.update();
            
            //option 2
            camMat(roi).copyTo(croppedCamMat);
            
            //option 3
            croppedImage2.setFromPixels(cam.getPixels());
            croppedImage2.crop(roiRect.x, roiRect.y, 100, 100);
            
            //option 4
            for(int x = 0; x < roiRect.getWidth(); x++){
                for(int y = 0; y < roiRect.getHeight(); y++){
                    
                    int n = y * roiRect.getWidth() + x;
                    int nn = (y+roiRect.y) * cam.getWidth() + (x +roiRect.x);
                    
                    ofColor myColor = cam.getPixels().getColor(x+roiRect.x, y+roiRect.y);
                    croppedPixels3.setColor(x, y, myColor);
                }
            }

            croppedImage3.setFromPixels(croppedPixels3);
            croppedImage3.update();
        }
    }
    
}

void ofApp::draw() {
    ofSetColor(255);
    cam.draw(0, 0);
    
    ofSetColor(255, 0, 0);
    ofNoFill();
    ofDrawRectangle(roiRect);
    
    
    ofPushMatrix();
    ofTranslate(0, cam.getHeight());
    ofSetColor(255);
    
    //option 1
    croppedImage.draw(0, 0);
    
    //option2
    drawMat(croppedCamMat, 0, 100);
    
    //option 3
    croppedImage2.draw(0, 200);
    
    //option4
    croppedImage3.draw(0, 300);
    
    ofPopMatrix();
}
