#include "Actors/Actor.h"
#include "SpriteSheet.h"
#include "commands/ActorCommands.h"
#include "commands/InputHandler.h"
#include "Room.h"
#include "gameFunctions/Dialogue.h"

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

	//INITIALIZING GAME OBJECTS
	Actor player("resources/char_sheet_new.png",64,64, 
							 "resources/dialogues/player.txt");
	InputHandler ih;

	Actor bot("resources/jerry_sheet.png", 64,96, "resources/dialogues/jerry.txt");

	sf::Event e;
	sf::Time dt;
	sf::Clock clock;

	//DEBUG: remove later - this is to test the room
	std::vector<Door> doorsTest;
	Room r("resources/cells.png", doorsTest);

		//setting the view and stuff
	sf::View currView = window.getView();
	currView.setCenter(player.getX(), player.getY());
	window.setView(currView);

	//DONE INITIALIZING

	//housekeeping, put the player in the center of the game.
	player.setPosition(r.getCenter().x, r.getCenter().y);
	bot.setPosition(r.getCenter().x, r.getCenter().y);

	Dialogue * currentDialogue = nullptr;
	bool dialogueOpened = false;

	while(window.isOpen())
	{
		//get time for this frame
		dt = clock.restart();

		// printf("fps: %f\n", (1.0/dt.asSeconds()));

		//handle events
		while(window.pollEvent(e))
		{
			switch(e.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyPressed:
				{
					if (!dialogueOpened)
					{
						ih.keyPressed(e.key.code, &player);
					}
					switch(e.key.code)
					{
						//return => opens dialogue
						case sf::Keyboard::Return:
						{
							if (!dialogueOpened)
							{
								currentDialogue = new Dialogue(&player, &bot, window);
								dialogueOpened = true;
							}
							//if theres already a dialogue open => advance
							else
							{
								currentDialogue->advance();
							}
						}break;
						//right shift => cancels dialogue
						case sf::Keyboard::RShift:
						{
							if (dialogueOpened)
							{
								delete currentDialogue;
								currentDialogue = nullptr;
								dialogueOpened = false;
							}
						}break;
					}//end switch statement
				}break;
				case sf::Event::KeyReleased:
				{
					if (!dialogueOpened)
					{
						ih.keyReleased(e.key.code, &player);
					}
				}break;
			}
		}

		//center the view around the player
		currView.setCenter(player.getX(), player.getY());
		window.setView(currView);

		player.update(dt);

		//clear
		window.clear();
		//draw
		window.draw(r);
		window.draw(player);
		window.draw(bot);
			//dialogue
		if (currentDialogue)
		{
			currentDialogue->update(dt);
			window.draw(*currentDialogue);
		}
		//display
		window.display();
	}

	return 0;
}