#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    iMainCamera = 0;

    // user camera
    //	camEasyCam.setTarget(nodeSwarm);
    camEasyCam.setDistance(500);
    cameras[0] = &camEasyCam;
    
    
    // front
    camFront.scale = 100;
    
    cameras[1] = &camFront;
    
    // top
    camTop.scale = 100;
    camTop.tilt(-90);
    cameras[2] = &camTop;
    
    // left
    camLeft.scale = 100;
    camLeft.pan(-90);
    cameras[3] = &camLeft;
    
    
    //test cam
    //camInObject.setDistance(0); //.scale = 10; //
    
    // camInObject.setForceAspectRatio(true);
    camInObject.setAspectRatio(1.7778);
    camInObject.setFov(40);
    //camInObject.setVFlip(false);
    cameras[4] = &camInObject;
    
    float sphereDiameter = 100;
    sphere.set(sphereDiameter, 12,OF_PRIMITIVE_TRIANGLES);
    //sphere.setRadius( sphereDiameter );
    //ofSetSphereResolution(24);
    //myPlane.init();
    mesh=sphere.getMesh();

    
     setupViewports();
}

void ofApp::setupViewports()
{
    //call here whenever we resize the window
    
    /////////////////////
    // DEFINE VIEWPORTS
    /////////////////////
    //
    //float xOffset = ofGetWidth()/3;
    //	float yOffset = ofGetHeight()/N_CAMERAS;
    
    //float xOffset = 0;
    //float yOffset = N_CAMERAS;
    
    
    viewMain.x = 0;
    viewMain.y = 0;
    viewMain.width = 1024; //ofGetWidth();
    viewMain.height = 576; //ofGetHeight();
    
    
    
    
    
    float yOffset = ofGetHeight() / N_CAMERAS;
    float xOffset = yOffset * 1.77778;
    
    //    viewOnObject.x=0;
    //    viewOnObject.y = 0;
    //    viewOnObject.width = 400;
    //    viewOnObject.height = 800;
    
    for(int i = 0; i < N_CAMERAS; i++){
        
        viewGrid[i].x = 0;
        viewGrid[i].y = yOffset * i;
        viewGrid[i].width = xOffset;
        viewGrid[i].height = yOffset;
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){


   }

//--------------------------------------------------------------
void ofApp::draw(){

//    glDisable(GL_DEPTH_TEST);
//    ofPushStyle();
//    ofSetColor(100, 100, 100);
//    ofDrawRectangle(viewMain);
//    ofPopStyle();
//    glEnable(GL_DEPTH_TEST);
//    
    
    
//    cameras[4]->begin(viewMain); //viewMain);
//    //drawScene(iMainCamera);
//    cameras[4]->end();
    
    cameras[iMainCamera]->begin(viewMain);
    drawScene(iMainCamera);
    
    cameras[iMainCamera]->end();
    
    
    // draw side viewports
    for(int i = 0; i < N_CAMERAS; i++){
        ofSetColor(255);
        cameras[i]->begin(viewGrid[i]);
        drawScene(i);
        cameras[i]->end();
    }
    
    
    ofPushStyle();
    glDepthFunc(GL_ALWAYS); // draw on top of everything
    
    //draw outlines on views
    ofSetLineWidth(1);
    ofNoFill();
    ofSetColor(255, 255, 255);
    for (int i=0; i<N_CAMERAS; i++)
    {
        ofRect(viewGrid[i]);
    }
    
    ofRect(viewMain);
    
    glDepthFunc(GL_LESS);
    ofPopStyle();
    

    
}

void ofApp::drawScene(int iCameraDraw){
    

    
    
    
    //draw the image and place it right infront in camera view
    ofPushMatrix();

    ofEnableAlphaBlending();
    ofSetColor(255,255,255,50);
    //sixt.draw(0,0,0);
//    myFBO.draw(0,0);
    ofDrawRectangle(0,0, 400, 400);
    ofDisableAlphaBlending();
    ofPopMatrix();
    

        ofSetColor(50);
        mesh.drawWireframe();

    //////////////////////////////////
    // DRAW EASYCAM FRUSTUM PREVIEW
    //////////////////////////////////
    
    //let's not draw the camera
    //if we're looking through it
    //if (iCameraDraw != 4){
    
    //  ofSetColor(255, 0, 0);
    //  ofLine(camInObject.getPosition(), camInObject.getLookAtDir());
    

    
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