#pragma once
#include "ofMain.h"

class ofxMouseRuler {

public:
	ofxMouseRuler();
	~ofxMouseRuler();

	void setup();
	void draw(ofEventArgs&);

	void hide();
	void show();
	void toggleVisibility();

	bool mousePressed(ofMouseEventArgs& args);
	bool mouseReleased(ofMouseEventArgs& args);
	void mouseMoved(ofMouseEventArgs&){}
	void mouseDragged(ofMouseEventArgs&){}
	void mouseScrolled(ofMouseEventArgs&){}
	void mouseEntered(ofMouseEventArgs&){}
	void mouseExited(ofMouseEventArgs&){}

private:

	bool setupDone;
	bool visible;
	ofPoint dragStart;
	bool dragging;
	ofBitmapFont font;

};

