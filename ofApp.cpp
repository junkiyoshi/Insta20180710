#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("Insta");

	ofNoFill();
	ofBackground(39);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	for (int i = 0; i < 256; i++) {

		ofPoint point(ofMap(ofNoise(ofRandom(100) + ofGetFrameNum() * 0.005), 0, 1, ofGetWidth() * -0.3, ofGetWidth() * 1.3), ofMap(ofNoise(ofRandom(100) + ofGetFrameNum() * 0.001), 0, 1, ofGetHeight() * -0.3, ofGetHeight() * 1.3));
		float radius = ofRandom(5, 20);
		ofColor circle_color;
		circle_color.setHsb(ofRandom(255), 255, 255 * ofNoise(point.x * 0.05, point.y * 0.05, ofGetFrameNum() * 0.001));
		ofSetColor(circle_color);

		ofDrawCircle(point, radius);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}