#include "AICommander.h"

std::shared_ptr<ActorCommand> AICommander::moveUp(new ActorMoveCommand(UP));
std::shared_ptr<ActorCommand> AICommander::moveDown(new ActorMoveCommand(DOWN));
std::shared_ptr<ActorCommand> AICommander::moveLeft(new ActorMoveCommand(LEFT));
std::shared_ptr<ActorCommand> AICommander::moveRight(new ActorMoveCommand(RIGHT));

AICommander::AICommander(Actor* ai)
{
	this-> ai = ai;
	moving = false;
	timer = 0;
}