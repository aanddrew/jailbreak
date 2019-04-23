#include "Dialogue.h"

Dialogue::Dialogue(Actor* actor1, Actor* actor2)
{
	this->actor1 = actor1;
	this->actor2 = actor2;

	lines = actor2->getDialogueSheet()->getRandLines();

	if (!font.loadFromFile("resources/fonts/arial.ttf"))
	{
		printf("Error loading font!!!\n");
	}

	text.setString(lines[0]);
}

void Dialogue::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	sf::View winView = target.getView();
	sf::Vector2f center = winView.getCenter();

	sf::Vector2f boxCorner(center.x - width/2, center.y + 100);

	//creating the bounding rectangle
	sf::RectangleShape rectangle;
	rectangle.setFillColor(sf::Color::Black);
	rectangle.setSize(sf::Vector2f(width,height));
	rectangle.setPosition(boxCorner);

	//now setting the text up
	sf::Text textCopy = text;
	textCopy.setPosition(boxCorner.x + 10, boxCorner.y + 10);
	textCopy.setString(lines[0]);
	textCopy.setCharacterSize(24);
	textCopy.setFillColor(sf::Color::White);
	// std::cout << textCopy.getString().toAnsiString() << std::endl;

	// printf("%s\n", );

	target.draw(rectangle);
	target.draw(textCopy);
}