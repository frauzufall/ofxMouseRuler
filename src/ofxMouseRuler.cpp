#include "ofxMouseRuler.h"

ofxMouseRuler::ofxMouseRuler() {

	setupDone = false;
	visible = false;

}

void ofxMouseRuler::setup(){
	visible = true;
	ofRegisterMouseEvents(this);
	ofAddListener(ofEvents().draw, this, &ofxMouseRuler::draw, std::numeric_limits<int>::max());
	setupDone = true;
}

void ofxMouseRuler::draw(ofEventArgs &){

	if(visible){

		ofPoint mPos(ofGetMouseX(), ofGetMouseY());

		std::string info;
		if(!dragging){
			info = "x: " + ofToString(mPos.x) + " y: " + ofToString(mPos.y);
		}else{
			ofSetColor(255,0,0);
			ofSetLineWidth(1);
			ofDrawLine(mPos, dragStart);
			info = ofToString((mPos-dragStart).length());
		}

		ofSetColor(255);
		ofFill();
		ofDrawRectangle(font.getBoundingBox(info, mPos.x +12, mPos.y + 30));

		ofSetColor(0);
		ofDrawBitmapString(info, mPos.x +12, mPos.y + 30);

	}

}

void ofxMouseRuler::show(){
	visible = true;
}

void ofxMouseRuler::hide(){
	visible = false;
}

void ofxMouseRuler::toggleVisibility(){
	visible = !visible;
}

ofxMouseRuler::~ofxMouseRuler(){
	if(setupDone){
		ofUnregisterMouseEvents(this);
		ofRemoveListener(ofEvents().draw, this, &ofxMouseRuler::draw, OF_EVENT_ORDER_AFTER_APP+1);
	}
}


bool ofxMouseRuler::mousePressed(ofMouseEventArgs &args) {
	dragStart = ofPoint(args.x,args.y);
	dragging = true;
	return false;
}

bool ofxMouseRuler::mouseReleased(ofMouseEventArgs &args){
	dragging = false;
	return false;
}
