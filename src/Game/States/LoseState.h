
#include "State.h"
#include "Button.h"
#include "ofMain.h"

class LoseState: public State{
	private:
	ofImage Youloseimg;

    public: 
        LoseState();
		void reset();
		void tick();
		void render();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);

};