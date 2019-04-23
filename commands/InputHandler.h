#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "ActorCommands.h"
#include <memory>

class InputHandler
{
private:
	//these are static because they do the same thing for every instance of
	//InputHandler
	static std::shared_ptr<ActorCommand> moveUp;
	static std::shared_ptr<ActorCommand> moveDown;
	static std::shared_ptr<ActorCommand> moveLeft;
	static std::shared_ptr<ActorCommand> moveRight;
public:
	InputHandler();
	~InputHandler();
	void keyPressed(sf::Keyboard::Key code, Actor*);
	void keyReleased(sf::Keyboard::Key code, Actor*);
};

#endif