//
// Created by joshu on 11/3/2020.
//
#pragma once

#include "BaseCounter.h"
#include "EntityManager.h"
#include "Player.h"
#include "ofMain.h"

class Restaurant {
    private:
        Player* player;
        EntityManager* entityManager;
        int ticks=0;
        std::vector<ofImage> people;
        int money =0;

    public:
        Restaurant();
        Player* getPlayer();
        void setPlayer(Player *player);
        Item* cheese;
        Item* lettuce;
        Item* tomato;
        Item* burger;
        Item* botBread;
        Item* topBread;
        ofImage floor;

        //Images of added items
        ofImage tables;
        ofImage chairs;
        ofImage chairlsleft;
        ofImage beer_barrils;
        ofImage arcade_machines;
        ofImage sunflowers;

        void initItems();
        void initCounters();
        void initClients();
        void generateClient();
        void serveClient();
        void tick();
        void render();
        void keyPressed(int key);

        EntityManager* getEntityManager();
        int getMoney();
};
