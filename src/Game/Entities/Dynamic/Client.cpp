#include "Client.h"

Client::Client(int x, int y, int width, int height, ofImage sprite, Burger* burger): Entity(x, y, width, height, sprite){
    this->burger = burger;
}
Client::~Client(){
    delete burger;
}
void Client::render(){
    ofSetColor (255,255,255);
    burger->render();
    SetRedShade(); // Changes the shade of red when the client is losing patience
    if(nextClient != nullptr){
        nextClient->render();
    }
}

void Client::tick(){
    patience--;
    burger->setY(y);
    if(patience == 0){
        isLeaving = true;
    }
    if(nextClient != nullptr){
        nextClient->tick();
    }
}

int Client::serve(Burger *burger)
{
    while (client != nullptr)
    {
        if (burger->Equals(client->burger))
        {
            total = burger->BurgerTotalPrice(burger->getIngredients());
            client->isLeaving = true;
            client->burger->clear();
            burger->clear();
            client = client->nextClient;
            return total;
        }
        else
        {
            client = client->nextClient;
        }
        
    }
    burger->clear();
    return 0;
}

void Client::SetRedShade()
{ // Sets the shade of red depending on the patience variable
    Patiencelvl = (float)patience / originalPatience;
    redshade = 255 * Patiencelvl;
    ofSetColor(255, redshade, redshade);
    sprite.draw(x, y, width, height);
}

int Client::getPatience(){
    return patience;
}