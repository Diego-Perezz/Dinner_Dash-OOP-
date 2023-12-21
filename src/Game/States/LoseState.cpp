#include "LoseState.h"

LoseState::LoseState(){

	Youloseimg.load("images/youlose.png");
}
void LoseState::tick() {

	setFinished(true);
	setNextState("");
}
void LoseState::render() {

	ofSetBackgroundColor(256);
	Youloseimg.draw(0,0, ofGetWidth(), ofGetHeight());

}

void LoseState::keyPressed(int key){

}

void LoseState::mousePressed(int x, int y, int button){

}


void LoseState::reset(){
	setFinished(false);
	setNextState("");

}