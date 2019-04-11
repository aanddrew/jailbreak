#include "Actors/Actor.h"
#include "SpriteSheet.h"
#include "commands/ActorCommands.h"
#include "commands/InputHandler.h"
#include "Room.h"

#include <SFML/Graphics.hpp>

#include <stdio.h>

static unsigned int SCREEN_HEIGHT = 640;
static unsigned int SCREEN_WIDTH =480;

int main()
{
	printf("Hello World!\n");

	sf::RenderWindow window(
						sf::VideoMode(SCREEN_HEIGHT,SCREEN_WIDTH), "Command Pattern");
	window.display();

	Actor player("resources/char_sheet_new.png");

	sf::Event e;

	InputHandler ih;

	sf::Time dt;
	sf::Clock clock;

	//DEBUG: remove later
	std::vector<Door> doorsTest;
	Room r("resources/cells.png", doorsTest);

	sf::View currView = window.getView();
	currView.setCenter(player.getX(), player.getY());
	window.setView(currView);

	while(window.isOpen())
	{
		dt = clock.restart();

		// printf("fps: %f\n", (1.0/dt.asSeconds()));

		while(window.pollEvent(e))
		{
			switch(e.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyPressed:
				{
					ih.keyPressed(e.key.code, &player);
				}break;
				case sf::Event::KeyReleased:
				{
					ih.keyReleased(e.key.code, &player);
				}break;
			}
		}

		currView.setCenter(player.getX(), player.getY());
		window.setView(currView);

		player.update(dt);

		//clear
		window.clear();
		//draw
		window.draw(r);
		window.draw(player);
		//display
		window.display();
	}

	return 0;
}