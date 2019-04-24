#include "Actor.h"

Actor::Actor(std::string spriteFileName, int width, int height, 
						 std::string dialogueFileName)
:
sheet(spriteFileName, width, height),
dialogueSheet(dialogueFileName)
{
	for(int i = 0; i < 4; i++)
	{
		moving[i] = false;
	}
	altMove  = false;
	facing = DOWN;
	spriteMoveTimer = 0;
	spriteFaceTimer = 0;
	altFaceNum = 0;
	xVel = 0;
	yVel = 0;

	stopped = false;
}

void Actor::setPosition(float xIn, float yIn)
{
	sheet.setPosition(xIn, yIn);
}

float Actor::getX() {return sheet.getX();}

float Actor::getY() {return sheet.getY();}

void Actor::stop() {stopped = true;}
void Actor::unstop() {stopped = false;}

float Actor::getXVel() {return this->xVel;}
float Actor::getYVel() {return this->yVel;}

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
	xVel = 0;
	yVel = 0;
	// printf("move: %d\n", moveSprite);
	spriteMoveTimer += dt.asSeconds();
	spriteFaceTimer += dt.asSeconds();
	if (spriteMoveTimer  >= 0.3)
	{
		// altResting = rand()%2;
		altMove = !altMove;
		spriteMoveTimer = 0;
	}

	if (spriteFaceTimer >= 1)
	{
		altFaceNum = rand()%3;
		spriteFaceTimer = 0;
	}

	float finalSpeed = dt.asSeconds()* speed;

	currentlyMoving = (moving[UP] || moving[DOWN] 
									|| moving[LEFT] || moving[RIGHT]);

	//handle different move states
	if (moving[UP])
	{
		yVel += -1*finalSpeed;
		// sheet.move(0, -1*finalSpeed);
		sheet.setSprite(WALK_UP_1 + altMove);
		facing = UP;
	}
	if (moving[DOWN])
	{
		yVel += finalSpeed;
		sheet.setSprite(WALK_DOWN_1 + altMove);
		facing = DOWN;
	}
	if (moving[LEFT])
	{
		xVel += -1*finalSpeed;
		sheet.setSprite(WALK_LEFT_1 + altMove);
		facing = LEFT;
	}
	if (moving[RIGHT])
	{
		xVel += finalSpeed;
		sheet.setSprite(WALK_RIGHT_1 + altMove);
		facing = RIGHT;
	}

	if (stopped)
	{
		currentlyMoving = false;
	}
	else
	{
		sheet.move(xVel, yVel);
	}

	if (!currentlyMoving)
	{
		switch(facing)
		{
			case UP: sheet.setSprite(STILL_UP); break;
			case RIGHT: sheet.setSprite(STILL_RIGHT); break;
			case LEFT: sheet.setSprite(STILL_LEFT); break;
			case DOWN: sheet.setSprite(STILL_DOWN_1+altFaceNum); break;
		}
	}
}

DialogueSheet* Actor::getDialogueSheet()
{
	return &dialogueSheet;
}