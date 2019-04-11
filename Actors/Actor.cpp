#include "Actor.h"

Actor::Actor(std::string fileName, int width, int height)
:
sheet(fileName, width, height)
{
	altMove  = false;
	facing = DOWN;
	spriteTimer = 0;
}

void Actor::setPosition(float xIn, float yIn)
{
	sheet.setPosition(xIn, yIn);
}

float Actor::getX()
{
	return sheet.getX();
}

float Actor::getY()
{
	return sheet.getY();;
}

void Actor::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(sheet);
}

void Actor::setMoving(Move m, bool state)
{
	moving[m] = state;
}

void Actor::update(sf::Time dt)
{
	// printf("move: %d\n", moveSprite);
	spriteTimer += dt.asSeconds();
	if (spriteTimer >= 0.3)
	{
		altMove = !altMove;
		spriteTimer = 0;
	}
	float finalSpeed = dt.asSeconds()* speed;

	currentlyMoving = (moving[UP] || moving[DOWN] 
									|| moving[LEFT] || moving[RIGHT]);

	//handle different move states
	if (moving[UP])
	{
		sheet.move(0, -1*finalSpeed);
		sheet.setSprite(WALK_UP_1 + altMove);
		facing = UP;
	}
	if (moving[DOWN])
	{
		sheet.move(0, finalSpeed);
		sheet.setSprite(WALK_DOWN_1 + altMove);
		facing = DOWN;
	}
	if (moving[LEFT])
	{
		sheet.move(-1*finalSpeed, 0);
		sheet.setSprite(WALK_LEFT_1 + altMove);
		facing = LEFT;
	}
	if (moving[RIGHT])
	{
		sheet.move(finalSpeed, 0);
		sheet.setSprite(WALK_RIGHT_1 + altMove);
		facing = RIGHT;
	}

	if (!currentlyMoving)
	{
		switch(facing)
		{
			case UP: sheet.setSprite(STILL_UP); break;
			case RIGHT: sheet.setSprite(STILL_RIGHT); break;
			case LEFT: sheet.setSprite(STILL_LEFT); break;
			case DOWN: sheet.setSprite(STILL_DOWN_1); break;
		}
	}
}