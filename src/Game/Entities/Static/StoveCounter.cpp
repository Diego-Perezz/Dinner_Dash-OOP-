#include "StoveCounter.h"

StoveCounter::StoveCounter(int x, int y, int width, int height, Item* item, ofImage sprite)
: BaseCounter(x,y,width,height,item,sprite){
};


bool StoveCounter::cook(){
    startCooking = true;
    isCooked = false;
}

bool StoveCounter::isCooking(){
    if (startCooking){
        return true;
    }
    else {
        return false;
    }

}

bool StoveCounter::isReady(){
    if (isCooked){
        cookingcounter = 0;
        startCooking = false;
        isCooked = false;
        return true;
    } else {
        return false;
    }
}


void StoveCounter::render(){
    Entity::render();
    if (!startCooking && !isCooked){
        ofSetColor(0, 100, 0);
        ofDrawBitmapString("ready to cook",175,450);
    }

    if (startCooking){
        int percent = (cookingcounter * 100) / 500;
        ofSetColor(0, 100, 0);
        ofDrawBitmapString("Patty cooking progress: " + ofToString(percent) + "%",175,450);
    } 
    if (isCooked){
        ofSetColor(0, 100, 0);
        ofDrawBitmapString("ready to serve",175,450);
    }
}

void StoveCounter::tick(){
    ticks++;
    if (startCooking){
        cookingcounter++;
    }

    if (cookingcounter == 500){
        startCooking = false;
        isCooked = true;
    }
}
