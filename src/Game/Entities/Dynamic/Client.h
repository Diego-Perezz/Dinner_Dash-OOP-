#pragma once
#include "Entity.h"
#include "Burger.h"

class Client: public Entity{
    private:
        Burger* burger;
        int originalPatience = 4800;
        int patience=4800;
        int total = 0;
    public:
        Client(int, int, int, int, ofImage, Burger*);
        virtual ~Client();
        void tick();
        void render();
        int serve(Burger*);
        Client* nextClient=nullptr;
        bool isLeaving=false;
        int redshade;
        float Patiencelvl;
        Client* client = this;

        void SetRedShade();
        int getPatience();
};