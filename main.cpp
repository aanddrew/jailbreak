#include "Actors/Actor.h"
#include "SpriteSheet.h"
#include "commands/ActorCommands.h"
#include "commands/InputHandler.h"
#include "Room.h"
#include "gameFunctions/Dialogue.h"

#include <SFML/Graphics.hpp>

#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <iostream>

static unsigned int SCREEN_HEIGHT = 640;
static unsigned int SCREEN_WIDTH =480;

Actor* getProximityActor(Actor* target, std::vector<Actor*> actors,
												 float maxDist)
{
	float leastDist = maxDist;
	Actor* returned = nullptr;
	for(int i = 0; i < actors.size(); i++)
	{
		// std::cout << i << ": " << actors[i] << std::endl;
		if(actors[i] == target)
			continue;
		float xDiff = target->getX() - actors[i]->getX();
		float yDiff = target->getY() - actors[i]->getY();
		float dist = sqrt(xDiff*xDiff + yDiff*yDiff);
		if (dist < leastDist)
		{
			leastDist = dist;
			returned = actors[i];
		}
	}
	return returned;
}

bool compareActors(Actor* a1, Actor* a2)
{
	return a1->getY() < a2->getY();
}

void kickOutOfBounds(Actor& actor, sf::FloatRect bounding)
{
	//if they are out of bounds on top rect
	if (actor.getX() < bounding.left)
		actor.setPosition(bounding.left + 0.001, actor.getY());
	else if (actor.getX() > bounding.left + bounding.width)
		actor.setPosition(bounding.left + bounding.width -0.001, actor.getY());

	if (actor.getY() < bounding.top)
		actor.setPosition(actor.getX(), bounding.top +0.001);
	else if (actor.getY() > bounding.top + bounding.height)
		actor.setPosition(actor.getX(), bounding.top + bounding.height - 0.001);
}

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

	Actor bot2("resources/jerry_sheet.png", 64,96, "resources/dialogues/terry.txt");

	std::vector<Actor*> actors;
	actors.push_back(&player);
	actors.push_back(&bot);
	actors.push_back(&bot2);

	sf::Event e;
	sf::Time dt;
	sf::Clock clock;

	//DEBUG: remove later - this is to test the room
	std::vector<Door> doorsTest;
	Room r("resources/cells.png", doorsTest);
	r.setBounds(sf::FloatRect(0, 224, 1048, 354));

		//setting the view and stuff
	sf::View currView = window.getView();
	currView.setCenter(player.getX(), player.getY());
	window.setView(currView);

	//DONE INITIALIZING

	//housekeeping, put the player in the center of the game.
	player.setPosition(r.getCenter().x, r.getCenter().y);
	bot.setPosition(r.getCenter().x, r.getCenter().y+200);
	bot2.setPosition(r.getCenter().x-400, r.getCenter().y+200);

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
					ih.keyPressed(e.key.code, &player);
					switch(e.key.code)
					{
						//return => opens dialogue
						case sf::Keyboard::Return:
						{
							Actor* converser = getProximityActor(&player, actors, 50);
							if (!dialogueOpened && converser != nullptr)
							{
								currentDialogue = new Dialogue(&player, converser, window);
								dialogueOpened = true;
							}
							//if theres already a dialogue open => advance
							else if (dialogueOpened)
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
					ih.keyReleased(e.key.code, &player);
				}break;
			}
		}

		//center the view around the player
		currView.setCenter(player.getX(), player.getY());
		window.setView(currView);

		player.update(dt);

		kickOutOfBounds(player, r.getBounds());

		//clear
		window.clear();
	//-------------RENDERING ORDER--------------
		//draw the room
		window.draw(r);
		//sort the actors by their x distance, so they are drawn correctly
		std::sort(actors.begin(), actors.end(), compareActors);
		//draw the actors
		for(int i = 0; i < actors.size(); i++)
		{
			window.draw(*actors[i]);
		}
		//draw the dialogue
		if (currentDialogue)
		{
			currentDialogue->update(dt);
			window.draw(*currentDialogue);
		}
	//-------------RENDERING DONE----------------
		//display
		window.display();
	}

	return 0;
}