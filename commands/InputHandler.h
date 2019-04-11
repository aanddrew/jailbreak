#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "ActorCommands.h"

class InputHandler
{
private:
	ActorCommand* moveUp;
	ActorCommand* moveDown;
	ActorCommand* moveLeft;
	ActorCommand* moveRight;
public:
	InputHandler();
	~InputHandler();
	void keyPressed(sf::Keyboard::Key code, Actor*);
	void keyReleased(sf::Keyboard::Key code, Actor*);
};

#endif