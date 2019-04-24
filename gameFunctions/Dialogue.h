#ifndef DIALOGUE_H
#define DIALOGUE_H

#include "../Actors/Actor.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include <iostream>

class Dialogue : public sf::Drawable
{
private:
	float timePerCharacter = 0.05;
	float timer;

	int line;
	int character;

	Actor* actor1;
	Actor* actor2;

	int width = 540;
	int height = 100;

	sf::Font font;
	sf::Text text;
	sf::RectangleShape rect;

	std::vector<std::string> lines;

public:
	Dialogue(Actor* actor1, Actor* actor2, sf::RenderTarget&);
	~Dialogue();
	void advance();
	void nextChar();
	void update(sf::Time dt);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif