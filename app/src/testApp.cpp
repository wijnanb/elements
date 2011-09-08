#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	counter = 0;
	ofSetCircleResolution(80);
	ofBackground(0);
	ofSetWindowTitle("Elements");
	ofEnableSmoothing();
	ofEnableAlphaBlending();
	ofSetFrameRate(60); // if vertical sync is off, we can go a bit fast... this caps the framerate at 60fps.
	
	int colorPool[] = {0xFFAA00, 0xC2B93E, 0x808F5D, 0x576157};
	
	nList = 360;
	list = new Element*[nList];
	
	for (int i=0; i<nList; i++) {
		int color = colorPool[ (int) ofRandom(0,4) ];
		list[i] = new Element(color);
	}
	
	centerX = ofGetWidth() / 2;
	centerY = ofGetHeight() / 2;
	
	if (COLORIZE) ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void testApp::update(){
	counter = counter + 0.01f;
	
	for (int i=0; i<nList; i++) {
		list[i]->update(counter);
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	if ( COLORIZE ) {
		ofSetColor(0,0,0,30);
		ofRect(0,0,ofGetWidth(),ofGetHeight());
	}
	
	for (int i=0; i<nList; i++) {
		list[i]->draw();
	}	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}