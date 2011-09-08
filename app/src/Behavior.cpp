
#include "Behavior.h"

Behavior::Behavior(Element* _el, int &_type) {
	el = _el;
	type = _type;
}

void Behavior::setup() {
	float speed;
	double theta;
	
	switch (type) {
		case BEHAVIOR_WANDER:
			theta = ofRandom(0, TWO_PI);
			speed = ofRandom(1, 2.5);;
			el->vx = speed * cos(theta);
			//el->vy = speed/5 * sin(theta);
			break;
		default:
			break;
	}
	
}

void Behavior::execute() {
	
	switch (type) {
		case BEHAVIOR_SINE_Y:
			el->vy += (el->vy > 0 ? 1 : -1) * 0.03*cos(2*el->counter);
			break;
		case BEHAVIOR_STOP_BORDERS:
			el->x = ofClamp( el->x, 10+1, ofGetWidth()-10-1 );
			el->y = ofClamp( el->y, 10+1, ofGetHeight()-10-1 );
			break;
		case BEHAVIOR_BOUNCE_BORDERS:
			if ( el->x <= 10+1 || el->x >= ofGetWidth()-10-1 )	{
				el->x = ofClamp( el->x, 10+1, ofGetWidth()-10-1 );
				el->vx = - el->vx;
			}
			if ( el->y <= 10+1 || el->y >= ofGetHeight()-10-1 )	{
				el->y = ofClamp( el->y, 10+1, ofGetHeight()-10-1 );
				el->vy = - el->vy;
			}
			break;
		default:
			break;
	}
	
	el->x += el->vx;
	el->y += el->vy;
}
