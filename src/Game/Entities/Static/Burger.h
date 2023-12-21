//
// Created by joshu on 11/4/2020.
//
#pragma once

#include "Entity.h"
#include "Item.h"

class Burger {
  private:
    int x, y, width, height;
    vector<Item *> ingredients;
    int Burgertotal;

  public:
    Burger(int, int, int, int);
    void addIngredient(Item *item);
    void RemoveIngredient();
    bool Equals(Burger* newburg); // Equals method
    void render();
    void clear();
    bool IsEmpty(); // Added to know if ingredients vector is empty
    void setY(int y) {
        this->y = y;
    }

    vector <Item *> getIngredients(); //get burger ingredients 
    int BurgerTotalPrice(vector<Item *> ingredients); // sets the price of the burger according to its ingredients

};
