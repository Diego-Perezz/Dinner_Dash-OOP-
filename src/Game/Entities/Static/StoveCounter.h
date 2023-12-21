#include "BaseCounter.h"

class StoveCounter : public BaseCounter{

    private:
    // Item* cookedPatty;
    int cookingcounter = 0;
    bool startCooking = false;
    bool isCooked = false;

    public:
    StoveCounter(int x, int y, int width, int height, Item* item, ofImage sprite);
    
    bool cook();
    bool isCooking();
    bool isReady();
    void render();
    void tick();

};