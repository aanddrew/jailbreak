#include "InputHandler.h"

std::shared_ptr<ActorCommand> InputHandler::moveUp(new ActorMoveCommand(UP));
std::shared_ptr<ActorCommand> InputHandler::moveDown(new ActorMoveCommand(DOWN));
std::shared_ptr<ActorCommand> InputHandler::moveLeft(new ActorMoveCommand(LEFT));
std::shared_ptr<ActorCommand> InputHandler::moveRight(new ActorMoveCommand(RIGHT));

// :
// moveUp(UP),
// moveDown(DOWN),
// moveLeft(LEFT),
// moveRight(RIGHT)
InputHandler::InputHandler()
{
	// moveUp = new ActorMoveCommand(UP);
	// moveDown = new ActorMoveCommand(DOWN);
	// moveLeft = new ActorMoveCommand(LEFT);
	// moveRight = new ActorMoveCommand(RIGHT);
}

InputHandler::~InputHandler()
{
	// delete(moveUp);
	// delete(moveDown);
	// delete(moveLeft);
	// delete(moveRight);
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