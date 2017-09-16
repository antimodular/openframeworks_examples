#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    	grabber.setup(1920,1080);
}

//--------------------------------------------------------------
void ofApp::update(){
	grabber.update();
	if(grabber.isFrameNew()){
        
        pixs = grabber.getPixels();
        
        myInt = 234;
        analyzer.analyze(pixs, myInt);

    }
	analyzer.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(255);
	grabber.draw(0,0,grabber.getWidth()/3,grabber.getHeight()/3);
	analyzer.draw(grabber.getWidth()/3,0,grabber.getWidth()/3,grabber.getHeight()/3);
    analyzer.drawInfo(grabber.getWidth()/3,10);
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
