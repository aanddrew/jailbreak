#include "ActorCommands.h"

//-----ACTOR MOVE COMMAND------
ActorMoveCommand::ActorMoveCommand(Move moveIn)
{
	this->move = moveIn;
}

void ActorMoveCommand::execute(Actor* actor)
{
	//executing
	actor->setMoving(move, true);
}

void ActorMoveCommand::undo(Actor* actor)
{
	actor->setMoving(move, false);
}