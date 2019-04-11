#ifndef ACTORCOMMANDS_H
#define ACTORCOMMANDS_H

#include "../Actors/Actor.h"

#include <stdio.h>

class ActorCommand
{
public:
	virtual ~ActorCommand() {}
	virtual void execute(Actor* actor) = 0;
	virtual void undo(Actor* actor) = 0;
};

class ActorMoveCommand : public ActorCommand
{
private:
	Move move;
public:
	ActorMoveCommand(Move moveIn);
	virtual void execute(Actor* actor);
	virtual void undo(Actor* actor);
};

#endif