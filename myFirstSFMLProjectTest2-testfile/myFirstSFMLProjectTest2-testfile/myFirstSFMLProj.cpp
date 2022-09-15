// iD Tech Game Plan - SFML Template
#include <SFML/Graphics.hpp>

int main()
{
	// Create a Window to Display Graphics, Define Size and Window Name
	sf::RenderWindow window(sf::VideoMode(400, 200), "SFML Works");
	/* CREATE OBJECTS AND ASSIGN OBJECT ATTRIBUTES HERE */
	sf::CircleShape circle;
	/* DEFINE VARIABLES HERE */
	circle.setRadius(50);
	circle.setPosition(200, 100);
	circle.setFillColor(sf::Color::Cyan);
	// Run the Program while the Window is Open
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(circle);
		window.display();

	}
}