#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <SFML/Graphics.hpp>

class SpriteSheet : public sf::Drawable
{
private:
	sf::IntRect source;
	sf::Texture sheet;
	sf::Sprite currSprite;
	int oneWidth;
	int oneHeight;
	int numRows;
	int numCols;
public:
	SpriteSheet(std::string fileName, int, int);
	void setSprite(int);

	float getX();
	float getY();

	void move(float, float);

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif