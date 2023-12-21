//
// Created by joshu on 11/4/2020.
//

#include "Burger.h"

Burger::Burger(int x, int y, int width, int height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Burger::addIngredient(Item *item) {
    ingredients.push_back(item);
}

void Burger::RemoveIngredient(){
    if (!ingredients.empty()){
        ingredients.pop_back();
    }
}

bool Burger::Equals(Burger* newburg){
    if (newburg->ingredients.size() != this->ingredients.size()) // Checks if client's and player's burger has the same amount of ingredients
    {
        return false;
    }
    int cct = 0, pct = 0;
    int cch = 0, pch = 0;
    int cbur = 0, pbur = 0;
    int clet = 0, plet = 0;

    for (int i = 0; i < this->ingredients.size(); i++) // Counts player's Ingredients
    {
        if (this->ingredients[i]->name == "tomato")
        {
            pct++;
        }
        if (this->ingredients[i]->name == "cheese")
        {
            pch++;
        }
        if (this->ingredients[i]->name == "patty")
        {
            pbur++;
        }
        if (this->ingredients[i]->name == "lettuce")
        {
            plet++;
        }
    }

    for (int i = 0; i < newburg->ingredients.size(); i++) // Counts client's ingredients
    {
        if (newburg->ingredients[i]->name == "tomato")
        {
            cct++;
        }
        if (newburg->ingredients[i]->name == "cheese")
        {
            cch++;
        }
        if (newburg->ingredients[i]->name == "patty")
        {
            cbur++;
        }
        if (newburg->ingredients[i]->name == "lettuce")
        {
            clet++;
        }
    }

    if (newburg->ingredients[0] != this->ingredients[0])
    { // Checks if client's and player's burger have a top bun
        return false;
    }

    if (newburg->ingredients[newburg->ingredients.size() - 1] != this->ingredients[this->ingredients.size() - 1])
    { // Checks if client's and player's burger have a bottom bun
        return false;
    }

    if (cct == pct && cch == pch && cbur == pbur && clet == plet)
    { // Checks if player's burger has the same ingredients as the client's burger
        return true;
    }
    else
    {
        return false;
    }
}

void Burger::render(){
    int counter = 1;
    for (Item* ingredient:ingredients){
        ingredient->sprite.draw(x-5,y-(counter * 10)+55,width*0.70,height*0.70);
        counter++;
    }
}

void Burger::clear(){
    ingredients.clear();
}

bool Burger::IsEmpty() // Added to know if ingredients vector is empty
{
    if(ingredients.empty()){
        return true;
    }
    return false;
}

int Burger::BurgerTotalPrice(vector<Item *> ingredients){
    Burgertotal = 0;

    int cheesecounter = 0;
    int lettucecounter = 0;
    int tomatocounter = 0;
    int pattycounter = 0;

    for (Item *ingredient : ingredients)
    {
        if (ingredient->name == "cheese")
        {
            cheesecounter++;
        }
        if (ingredient->name == "lettuce")
        {
            lettucecounter++;
        }
        if (ingredient->name == "tomato")
        {
            tomatocounter++;
        }
        if (ingredient->name == "patty")
        {
            pattycounter++;
        }
    }
    Burgertotal = (3 * cheesecounter) + (2 * lettucecounter) + (2 * tomatocounter) + (4 * pattycounter) + 2;
    return Burgertotal;
}

vector <Item *> Burger::getIngredients(){
    return this->ingredients;
}



