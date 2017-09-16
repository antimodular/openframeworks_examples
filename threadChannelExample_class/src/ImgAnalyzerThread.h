//
//  ImgAnalyzer.h
//  threadChannelExample
//
//  Created by Stephan Schulz on 2017-09-14.
//
//

#ifndef ImgAnalyzerThread_h
#define ImgAnalyzerThread_h


/*
 * ImgAnalysisThread.cpp
 *
 *  Created on: Oct 8, 2014
 *      Author: arturo
 */

#include "ofConstants.h"

class testClass{
public:
    ofPixels pix;
    int myInt;
    string myStr;
    
};

class ImgAnalyzerThread: public ofThread {
    
private:
    //    void threadedFunction();
    ofThreadChannel<testClass> toAnalyze;
    ofThreadChannel<testClass> analyzed;

    ofTexture texture;

    testClass mainClass;
    
    bool newFrame;
    
public:
    ImgAnalyzerThread()
    :newFrame(true){
        // start the thread as soon as the
        // class is created, it won't use any CPU
        // until we send a new frame to be analyzed
        startThread();
    }
    
    ~ImgAnalyzerThread(){
        // when the class is destroyed
        // close both channels and wait for
        // the thread to finish
        toAnalyze.close();
        analyzed.close();
        waitForThread(true);
    }
    
    //void analyze(testClass & _aClass){
    void analyze(ofPixels & pix, int _aInt){
        
        // send the frame to the thread for analyzing
        // this makes a copy but we can't avoid it anyway if
        // we want to update the grabber while analyzing
        // previous frames
        testClass aClass;
        aClass.pix = pix;
        aClass.myInt = _aInt;
        
        toAnalyze.send(aClass);
    }
    
    void update(){
        // check if there's a new analyzed frame and upload
        // it to the texture. we use a while loop to drop any
        // extra frame in case the main thread is slower than
        // the analysis
        // tryReceive doesn't reallocate or make any copies
        newFrame = false;
        
       
        
        while(analyzed.tryReceive(mainClass)){
            newFrame = true;
        }
        if(newFrame){
            if(!texture.isAllocated()){
                texture.allocate(mainClass.pix);
            }
            texture.loadData(mainClass.pix);
        }
    }
    
    bool mainisFrameNew(){
        return newFrame;
    }
    
    //ofPixels & maingetPixels(){
    //	return pixels;
    //}
    
    ofTexture & maingetTexture(){
        return texture;
    }
    
    void draw(float x, float y, int w, int h){
        if(texture.isAllocated()){
            ofSetColor(255);
            texture.draw(x,y,w,h);
        }
    }
    
    void drawInfo(float x, float y){
     
        ofPushMatrix();
        ofTranslate(x, y);
            ofSetColor(255);
            ofSetColor(ofColor::lightGreen);
            ofDrawBitmapStringHighlight("myInt "+ofToString(mainClass.myInt), 0, 0);
            ofDrawBitmapStringHighlight("myStr "+ofToString(mainClass.myStr), 0, 30);
        ofPopMatrix();
    }
    
    
    void threadedFunction(){
        // wait until there's a new frame
        // this blocks the thread, so it doesn't use
        // the CPU at all, until a frame arrives.
        // also receive doesn't allocate or make any copies
        
        testClass bClass;
        while(toAnalyze.receive(bClass)){
            // we have a new frame, process it, the analysis
            // here is just a thresholding for the sake of
            // simplicity
            bClass.pix.setImageType(OF_IMAGE_GRAYSCALE);
            for(auto & p: bClass.pix){
                if(p > 80) p = 255;
                else p = 0;
            }
            int t = ofRandom(bClass.myInt);
            
            
            bClass.myStr = "abc "+ofToString(t);
            
            bClass.myInt = t;
            
            // once processed send the result back to the
            // main thread. in c++11 we can move it to
            // avoid a copy
            
            
#if __cplusplus>=201103
            analyzed.send(std::move(bClass));
#else
            analyzed.send(bClass);
#endif
        }
    }

    
    
};



#endif /* ImgAnalyzerThread_h */
