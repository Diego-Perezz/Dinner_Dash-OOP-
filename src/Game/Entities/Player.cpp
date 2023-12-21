#include "Player.h"

Player::Player(int x, int y, int width, int height, ofImage sprite, EntityManager* em) : Entity(x, y, width, height, sprite){

    vector<ofImage> chefAnimframes;
    ofImage temp;
    this->burger = new Burger(ofGetWidth()-110, 100, 100, 50);
    temp.cropFrom(sprite, 30,3,66,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 159,3,66,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 287, 3,67,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 31,129,66,120);
    chefAnimframes.push_back(temp);
    this->chefAnim = new Animation(50, chefAnimframes);
    this->entityManager = em;
    
}
void Player::tick(){
    chefAnim->tick();
}

void Player::render(){
    BaseCounter *ac = getActiveCounter();
    if (ac != nullptr) {
        ac->showItem();
    }
    ofSetColor(256, 256, 256);
    ofImage currentFrame = chefAnim->getCurrentFrame();
    if (facing == "left") {
        currentFrame.mirror(false, true);
    }
    currentFrame.draw(x, y, width, height);
    burger->render();
}

void Player::keyPressed(int key)
{
    if (key == 'e')
    {
        BaseCounter *ac = getActiveCounter();
        if (ac != nullptr)
        {
            StoveCounter *sc = dynamic_cast<StoveCounter *>(ac);
            if (sc != nullptr)
            {
                // Se termino de cocinar?
                if (sc->isReady())
                {
                    money--;
                    burger->addIngredient(sc->getItem());
                }
                // Cocinar
                else {
                    sc->cook();
                }
            }
            else
            {
                Item *item = ac->getItem();
                if (item != nullptr)
                {
                    money--; // Takes money every ingredient you use
                    burger->addIngredient(item);
                }
            }
        }
    }
    if (key == 'u')
    {
        if (!burger->IsEmpty())
        {
            money++; // Returns the money if inredient is removed
        }
        burger->RemoveIngredient();
    }
    if (key == OF_KEY_LEFT)
    {
        facing = "left"; // Flips chef's image
        x -= speed;      // Chef moves left
    }
    else if (key == OF_KEY_RIGHT)
    {
        facing = "right"; // Flips chef's image
        x += speed;       // Chef moves right
    }
    if (x <= 0)
    {
        x += speed; // Chef never goes the left side of the window
    }
    else if (x + width >= ofGetWidth())
    {
        x -= speed; // Chef never goes the right side of the window
    }
}

BaseCounter* Player::getActiveCounter(){
    for(Entity* e:entityManager->entities){
        BaseCounter* c = dynamic_cast<BaseCounter*>(e);
        if(x + e->getWidth()/2 >= e->getX() && x +e->getWidth()/2 <e->getX() + e->getWidth()){
            return c;
        }
    }
    return nullptr;
}

void Player::keyReleased(int key) {
}
void Player::mousePressed(int x, int y, int button) {
}

void Player::setFacing(string facing){ this->facing = facing; }