#include "Dialogue.h"

Dialogue::Dialogue(Actor* actor1, Actor* actor2, sf::RenderTarget& target) :
rect(),
text(),
font()
{
	this->line = 0;
	this->character = 0;

	this->timer = 0;

	this->actor1 = actor1;
	this->actor2 = actor2;

	lines = actor2->getDialogueSheet()->getRandLines();

	if (!font.loadFromFile("resources/fonts/arial.ttf"))
	{
		printf("Error loading font!!!\n");
	}

	sf::View winView = target.getView();
	sf::Vector2f center = winView.getCenter();

	sf::Vector2f boxCorner(center.x - width/2, center.y + 100);

	rect.setFillColor(sf::Color::Black);
	rect.setSize(sf::Vector2f(width,height));
	rect.setPosition(boxCorner);
	
	text.setFont(font);
	text.setPosition(boxCorner.x + 10, boxCorner.y + 10);
	text.setString(sf::String(lines[line]));
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
}

void Dialogue::advance()
{
	if (character < lines[line].length())
	{
		character = lines[line].length();
		return;
	}

	if (line < lines.size()-1)
	{
		line++;
		character = 0;
		timer = 0;
	}
}

void Dialogue::update(sf::Time dt)
{
	timer += dt.asSeconds();
	if (timer - character*timePerCharacter > 0 
			&& character < lines[line].length())
	{
		character++;
	}

	text.setString(sf::String(lines[line].substr(0, character)));
}

void Dialogue::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	// std::cout << (text.getString().toAnsiString()) << std::endl;
	target.draw(rect);
	target.draw(text);
}