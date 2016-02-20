#include "ofApp.h"

ofImage texture;

vector<ofPoint> curvePoints;

ofPolyline pLine;


ofImage image;
//--------------------------------------------------------------
void ofApp::setup(){

    
    image.loadImage("1.jpeg");
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    int radius=100;
    ofMesh mesh;
    ofPath path;
    
    path.setCircleResolution(100);
    path.circle(mouseX,mouseY,radius);
    path.close();
    
    mesh=path.getTessellation();
    
    for (int i=0;i<mesh.getNumVertices();i++)
        mesh.addTexCoord(mesh.getVertex(i));
    
    image.bind();
    mesh.draw();
    image.unbind();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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