
#include "Element.h"

Element::Element(int _color) {
	x = ofRandom(10+1, ofGetWidth()-10-1 );
	y = ofRandom(10+1, ofGetHeight()-10-1 );
	
	color = _color;
	
	vx = 0;
	vy = 0;
	
	offsetY = y;
	
	int features[] = { BEHAVIOR_WANDER, BEHAVIOR_BOUNCE_BORDERS };
	nBehaviors = 3;
	
	behaviors = new Behavior*[nBehaviors];
	
	for (int i=0; i<nBehaviors; i++) {
		behaviors[i] = new Behavior( this, features[i] );
		behaviors[i]->setup();
	}
}

void Element::update(float c) {
	counter = c;
	
	for (int i=0; i<nBehaviors; i++) {
		behaviors[i]->execute();
	}
}

void Element::draw()
{
	if ( true ) {
		ofFill();
		ofSetHexColor( color );
		ofCircle( x, y, 10 );
	}
	else {
		ofNoFill();
		ofSetColor(255, 255, 255);
	}

}
