#include "Room.h"

Room::Room(std::string spriteFile, std::vector<Door> doorsIn)
{
	sourceTexture.loadFromFile(spriteFile);
	sprite.setTexture(sourceTexture);

	doors = doorsIn;
	boundingRect = sprite.getGlobalBounds();
}

sf::Vector2f Room::getCenter()
{
	return sf::Vector2f(boundingRect.width/2, boundingRect.height/2);
}

void Room::setBounds(sf::FloatRect boundsIn)
{
	boundingRect = boundsIn;
}

sf::FloatRect Room::getBounds()
{
	return boundingRect;
}

void Room::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(sprite);
}