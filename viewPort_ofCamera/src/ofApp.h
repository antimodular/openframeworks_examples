#pragma once

#include "ofMain.h"
#include "OrthoCamera.h"

#define N_CAMERAS 5

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void setupViewports();
    void drawScene(int iCameraDraw);
    
     ofEasyCam				camEasyCam;
    orthoCamera				camFront;
    orthoCamera				camTop;
    orthoCamera				camLeft;
       ofCamera camInObject;
    
    //camera pointers
    ofCamera*cameras[N_CAMERAS];
    int						iMainCamera;

    //viewports
    ofRectangle				viewMain;
    // ofRectangle viewOnObject;
    ofRectangle viewGrid[N_CAMERAS];
    
        ofSpherePrimitive sphere;
        ofMesh mesh;
};
