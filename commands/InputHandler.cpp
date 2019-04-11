#include "InputHandler.h"

InputHandler::InputHandler()
{
	moveUp = new ActorMoveCommand(UP);
	moveDown = new ActorMoveCommand(DOWN);
	moveLeft = new ActorMoveCommand(LEFT);
	moveRight = new ActorMoveCommand(RIGHT);
}

InputHandler::~InputHandler()
{
	delete(moveUp);
	delete(moveDown);
	delete(moveLeft);
	delete(moveRight);
}

void InputHandler::keyPressed(sf::Keyboard::Key code, Actor* actor)
{
	switch(code)
	{
		case sf::Keyboard::Up: moveUp->execute(actor); break;
		case sf::Keyboard::Down: moveDown->execute(actor); break;
		case sf::Keyboard::Left: moveLeft->execute(actor); break;
		case sf::Keyboard::Right: moveRight->execute(actor); break;
	}
}

void InputHandler::keyReleased(sf::Keyboard::Key code, Actor* actor)
{
	switch(code)
	{
		case sf::Keyboard::Up: moveUp->undo(actor); break;
		case sf::Keyboard::Down: moveDown->undo(actor); break;
		case sf::Keyboard::Left: moveLeft->undo(actor); break;
		case sf::Keyboard::Right: moveRight->undo(actor); break;
	}
}