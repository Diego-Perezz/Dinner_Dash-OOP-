#include "WinState.h"

WinState::WinState(){
    winImage.load("images/youwin.png");
}

void WinState::tick(){
    setFinished(true);
    setNextState("");
}

void WinState::render(){
    winImage.draw(0,0,ofGetWidth(),ofGetHeight());
}

void WinState::keyPressed(int key){
    restaurant->keyPressed(key);
}

void WinState::mousePressed(int x, int y, int button){

}

void WinState::keyReleased(int key){

}

void WinState::reset(){
    setFinished(false);
    setNextState("");
}