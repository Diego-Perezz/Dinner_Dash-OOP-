//
// Created by joshu on 11/3/2020.
//

#include "Restaurant.h"

Player *Restaurant::getPlayer() { return player; }
void Restaurant::setPlayer(Player *player) { this->player = player; }

Restaurant::Restaurant() {
    floor.load("images/floor.jpg");
    entityManager = new EntityManager();
    ofImage chefPlayerImage;
    chefPlayerImage.load("images/chef.png");
    this->player = new Player(0, 600, 64, 64, chefPlayerImage, entityManager);    
    initItems();
    initCounters();
    initClients();
    generateClient();

    tables.load("images/Table.png");
    chairs.load("images/chair.png");
    chairlsleft.load("images/chairflip.png");

    beer_barrils.load("images/beer_barril.png");

    arcade_machines.load("images/arcade.png");

    sunflowers.load("images/sunflower.png");

}
void Restaurant::initItems(){
    ofImage burgerSpriteSheet, cheeseImg, lettuceImg, tomatoImg, burgerImg, botBreadImg, topBreadImg, plateImg;
    burgerSpriteSheet.load("images/burger.png");
    topBreadImg.cropFrom(burgerSpriteSheet, 25, 16, 112, 43); // top bun
    burgerImg.cropFrom(burgerSpriteSheet, 30, 134, 103, 48); // patty
    cheeseImg.cropFrom(burgerSpriteSheet, 169, 213, 102, 39); // cheese
    tomatoImg.cropFrom(burgerSpriteSheet, 169, 158, 110, 41); // tomato
    lettuceImg.cropFrom(burgerSpriteSheet, 161, 62, 117, 34); // lettuce
    botBreadImg.cropFrom(burgerSpriteSheet, 444, 270, 115, 39); // bottom bun
    plateImg.cropFrom(burgerSpriteSheet, 575, 263, 131, 51); // plate

    cheese = new Item(cheeseImg, "cheese");
    lettuce = new Item(lettuceImg, "lettuce");
    tomato = new Item(tomatoImg, "tomato");
    burger = new Item(burgerImg, "patty");
    botBread = new Item(botBreadImg, "bottomBun");
    topBread = new Item(topBreadImg, "topBun");
}
void Restaurant::initCounters(){
    int counterWidth = 96;
    int yOffset = 500;
    ofImage counterSheet, plateCounterImg, cheeseCounterImg, stoveCounterImg, lettuceCounterImg, emptyCounterImg, tomatoCounterImg, breadCounterImg;
    counterSheet.load("images/kitchen_cabinets_by_ayene_chan.png");
    stoveCounterImg.cropFrom(counterSheet, 224,12,32,43);//stoveTop
    lettuceCounterImg.cropFrom(counterSheet,96,76,32,43);//Vegetables
    emptyCounterImg.cropFrom(counterSheet,0,245,30,43);//Empty
    tomatoCounterImg.cropFrom(counterSheet,96,200,32,48);//fruit basket
    cheeseCounterImg.cropFrom(counterSheet,64,73,32,46);//cheese
    plateCounterImg.cropFrom(counterSheet,0,133,32,50);//plates
    breadCounterImg.cropFrom(counterSheet,0,63,34,56);//buns
    entityManager->addEntity(new BaseCounter(0,yOffset-16, counterWidth, 117, nullptr, plateCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth,yOffset-7, counterWidth,108, cheese, cheeseCounterImg));
    entityManager->addEntity(new StoveCounter(counterWidth*2,yOffset, counterWidth, 102, burger, stoveCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*3, yOffset, counterWidth, 102, lettuce, lettuceCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*4,yOffset, counterWidth, 102, nullptr, emptyCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*5, yOffset -10, counterWidth, 113, tomato, tomatoCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*6, yOffset-32, counterWidth, 133, botBread, breadCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*7, yOffset-32, counterWidth, 133, topBread, breadCounterImg));

}
void Restaurant::initClients(){
    ofImage temp;
    temp.load("images/People/Car_Designer3Female.png");
    people.push_back(temp);
    temp.load("images/People/Freedom_Fighter2Male.png");
    people.push_back(temp);
    temp.load("images/People/Hipster.png");
    people.push_back(temp);
    temp.load("images/People/Lawyer2Male.png");
    people.push_back(temp);
    temp.load("images/People/Mad_Scientist3Female.png");
    people.push_back(temp);
    temp.load("images/People/Programmer2Male.png");
    people.push_back(temp);
    temp.load("images/People/Songwriter3Male.png");
    people.push_back(temp);
    temp.load("images/People/Weather_Reporter2Female.png");
    people.push_back(temp);
}
void Restaurant::tick() {
    ticks++;
    if(ticks % 800 == 0){
        generateClient();
    }
    player->tick();
    entityManager->tick();
    player->money = money; // Sets player's money variable to be equal to restaurant's money variable
}


int Restaurant::getMoney(){
    return money;
}

void Restaurant::generateClient(){
    Burger* b = new Burger(72, 100, 50, 25);
    vector <Item* > IngredientsInBurger {burger,lettuce,tomato,cheese};
    b->addIngredient(botBread);
    for (int i = 0; i < IngredientsInBurger.size(); i++){
        b->addIngredient(IngredientsInBurger[ofRandom(0,IngredientsInBurger.size())]);
    }
    b->addIngredient(topBread);
    entityManager->addClient(new Client(0, 50, 64, 72,people[ofRandom(8)], b));
}
void Restaurant::render() {
    floor.draw(0,0, ofGetWidth(), ofGetHeight());

    //resizing images

    tables.resize(70,70);
    chairs.resize(50,70);
    chairlsleft.resize(50,70);
    beer_barrils.resize(50,70);
    arcade_machines.resize(60,70);
    sunflowers.resize(40,60);

    //drawing tables and chairs

    tables.draw(ofGetWidth() - 230,100);
    chairs.draw(ofGetWidth() - 280,90);
    chairlsleft.draw(ofGetWidth() - 160,90);

    tables.draw(230,ofGetHeight() - 500);
    chairs.draw(180,ofGetHeight() - 510);
    chairlsleft.draw(300,ofGetHeight() - 510);

    tables.draw(ofGetWidth() - 230,ofGetHeight() - 500);
    chairs.draw(ofGetWidth() - 280,ofGetHeight() - 510);
    chairlsleft.draw(ofGetWidth() - 160,ofGetHeight() - 510);

    tables.draw(230,100);
    chairs.draw(180,90);
    chairlsleft.draw(300,90);

    //drawing decorations

    beer_barrils.draw(ofGetWidth() - 50, ofGetHeight() - 70);

    arcade_machines.draw(ofGetWidth() - 60,0);

    sunflowers.draw(ofGetWidth()-100,0);



    player->render();
    entityManager->render();
    ofSetColor(0, 100, 0);
    ofDrawBitmapString("Money: " + to_string(money), ofGetWidth()/2, 10);
    ofSetColor(256, 256, 256);
}
void Restaurant::serveClient(){
    if(entityManager->firstClient!= nullptr){
        money += entityManager->firstClient->serve(player->getBurger());
    }
}
void Restaurant::keyPressed(int key) {
    player->keyPressed(key);
    if(key == 's'){
        serveClient();
    }
    if (key == 'e' || key == 'u'){
        money = player->money; // Uptates restaurant money
    }
}


EntityManager* Restaurant::getEntityManager(){
    return entityManager;
}