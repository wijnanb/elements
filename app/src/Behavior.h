
#ifndef BEHAVIOR_H
#define BEHAVIOR_H

#include "ofMain.h"
#include "Element.h"

class Element;


#define BEHAVIOR_WANDER 0
#define	BEHAVIOR_BOUNCE_BORDERS 1
#define	BEHAVIOR_STOP_BORDERS 2
#define BEHAVIOR_SINE_Y 3

class Behavior {
	private:
		Behavior();
	public:
		Behavior(Element *el, int &type);
	
		void setup();
		void execute();
		
		int type;
		Element *el;
};

#endif