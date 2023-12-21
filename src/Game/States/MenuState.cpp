#include "MenuState.h"

MenuState::MenuState() {
	string text = "Start";
	startButton = new Button(ofGetWidth()/2 - text.length()*8, ofGetHeight()/2 - text.length()*11, 64, 50, "Start");
}
void MenuState::tick() {
	startButton->tick();
	if(startButton->wasPressed()){
		setNextState("Game");
		setFinished(true);
	}
}
void MenuState::render() {
	ofSetBackgroundColor(115,215,255);
	startButton->render();

	string instruction1 = "Press 'E' to pickup ingredient";
	string instruction2 = "Press 'U' to remove ingredient";
	string instruction3 = "Press 'S' to serve";
	string instruction4 = "Press 'left arrow' to move left";
	string instruction5 = "Press 'right arrow' to move right";

	ofDrawBitmapString(instruction1,(ofGetWidth()/2) - 95,ofGetHeight() - 125);
	ofDrawBitmapString(instruction2,(ofGetWidth()/2) - 95,ofGetHeight() - 110);
	ofDrawBitmapString(instruction3,(ofGetWidth()/2) - 95,ofGetHeight() - 95);
	ofDrawBitmapString(instruction4,(ofGetWidth()/2) - 95,ofGetHeight() - 80);
	ofDrawBitmapString(instruction5,(ofGetWidth()/2) - 95,ofGetHeight() - 65);
}

void MenuState::keyPressed(int key){
	
}

void MenuState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}