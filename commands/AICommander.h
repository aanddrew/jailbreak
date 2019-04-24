#include "ActorCommands.h"
#include <memory>

class AIController
{
private:
	static std::shared_ptr<ActorCommand> moveUp;
	static std::shared_ptr<ActorCommand> moveDown;
	static std::shared_ptr<ActorCommand> moveLeft;
	static std::shared_ptr<ActorCommand> moveRight;

	float timer;
	bool moving;

	Actor* ai;

public:
	AIController(Actor* ai);
	void update(sf::Time dt);
};