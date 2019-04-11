#include "SpriteSheet.h"

SpriteSheet::SpriteSheet(std::string fileName, int widthIn, int heightIn)
:
source(widthIn*2,0,widthIn, heightIn)
{
	sheet.loadFromFile(fileName);
	oneWidth = widthIn;
	oneHeight = heightIn;

	// printf("%d x %d\n", textureIn.getSize().x, textureIn.getSize().y);
	numCols = sheet.getSize().x/oneWidth;
	numRows = sheet.getSize().y/oneHeight;

	// printf("cols, rows: %d, %d\n", numCols, numRows);

	currSprite = sf::Sprite(this->sheet, this->source);
	currSprite.setOrigin(widthIn/2, heightIn/2);
}

void SpriteSheet::setSprite(int numIn)
{
	//calculate the new position for the sprite to start at
	int newLeft = (numIn % numCols) * oneWidth;
	int newTop = (numIn / numRows) * oneHeight;

	if (numIn >= numRows*numCols)
		printf("ERROR, selected sprite out of bounds!\n");

	source.left = newLeft;
	source.top = newTop;
	currSprite.setTextureRect(source);
}

float SpriteSheet::getX()
{
	return currSprite.getPosition().x;
}

float SpriteSheet::getY()
{
	return currSprite.getPosition().y;
}

void SpriteSheet::setPosition(float xIn, float yIn)
{
	currSprite.setPosition(xIn, yIn);
}

void SpriteSheet::move(float dx, float dy)
{
	currSprite.move(dx, dy);
}

void SpriteSheet::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(currSprite);
}