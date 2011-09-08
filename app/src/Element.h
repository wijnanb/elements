
#ifndef ELEMENT_H
#define ELEMENT_H

#include "ofMain.h"
#include "Behavior.h"

class Behavior;

class Element
{
	public:
		Element(int color);
	
		void update(float counter);
		void draw();
	
		float x, y;
		float counter, offsetY;
		float vx, vy;
		Behavior** behaviors;
		int nBehaviors;
		int color;
}; 

#endif