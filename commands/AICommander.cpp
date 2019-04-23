#include "AICommander.h"

std::shared_ptr<ActorCommand> InputHandler::moveUp(new ActorMoveCommand(UP));
std::shared_ptr<ActorCommand> InputHandler::moveDown(new ActorMoveCommand(DOWN));
std::shared_ptr<ActorCommand> InputHandler::moveLeft(new ActorMoveCommand(LEFT));
std::shared_ptr<ActorCommand> InputHandler::moveRight(new ActorMoveCommand(RIGHT));