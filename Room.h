#ifndef ROOM_H
#define ROOM_H

#include <SFML/Graphics.hpp>

#include <string>

class Room;

struct Door
{
	Room* room;
	sf::Vector2i enterPos;
	sf::Vector2i exitPos;
};

class Room : public sf::Drawable
{
private:
	sf::Texture sourceTexture;
	sf::Sprite sprite;
	std::vector<Door> doors;
	sf::FloatRect boundingRect;
public:
	Room(std::string, std::vector<Door>);
	Room* getNextRoom(float, float);
	bool insideRoom(float, float);
	sf::Vector2f getRejectedMapPosition(int, int, int, int);
	sf::Vector2f getCenter();
	//inherited method
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif