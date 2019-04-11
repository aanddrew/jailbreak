#include "Room.h"

Room::Room(std::string spriteFile, std::vector<Door> doorsIn)
{
	sourceTexture.loadFromFile(spriteFile);
	sprite.setTexture(sourceTexture);

	doors = doorsIn;
}

void Room::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(sprite);
}