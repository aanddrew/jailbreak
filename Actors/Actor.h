#ifndef ACTOR_H
#define ACTOR_H

#include <SFML/Graphics.hpp>
#include "../SpriteSheet.h"

#include "../gameFunctions/DialogueSheet.h"

enum Move
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

//sprite sheet with 16 different sprites on it.
enum SheetNum
{
	WALK_UP_1,
	WALK_UP_2,
	WALK_DOWN_1,
	WALK_DOWN_2,
	WALK_LEFT_1,
	WALK_LEFT_2,
	WALK_RIGHT_1,
	WALK_RIGHT_2,
	STILL_UP,
	STILL_DOWN_1,
	STILL_DOWN_2,
	STILL_DOWN_3,
	STILL_LEFT,
	STILL_RIGHT,
	MISC_1,
	MISC_2
};

class Actor : public sf::Drawable
{
private:
	DialogueSheet dialogueSheet;
	SpriteSheet sheet;
	//stores the moving states for each direction, using the enum
	bool moving[4];
	Move facing;
	bool currentlyMoving;
	bool altMove;
	int altFaceNum;

	float speed = 200;
	float xVel;
	float yVel;
	float spriteMoveTimer;
	float spriteFaceTimer;
public:
	Actor(std::string,int, int, std::string);
	// Actor(int, int);

	void setPosition(float, float);

	void setMoving(Move m, bool state);
	void update(sf::Time dt);

	float getX();
	float getY();

	float getXVel();
	float getYVel();

	DialogueSheet* getDialogueSheet();

	//inherited method
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif