// iD Tech Game Plan - SFML Template
//new version by aidan carrier
// Include Needed for SFML
#include <SFML/Graphics.hpp>
// Include Needed for Animations
#include <SFML/Graphics/Rect.hpp>
// Include Needed for Text
#include <SFML/Graphics/Text.hpp>

/* DEFINE GAMESTATES HERE */

int main()
{
	// Create a Window to Display Graphics, Define Size and Window Name
	sf::RenderWindow window(sf::VideoMode(400, 200), "SFML Template Window");

	/* CREATE OBJECTS AND ASSIGN OBJECT ATTRIBUTES HERE */

	/* DEFINE VARIABLES HERE */

	// Run the Program while the Window is Open
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// When X Button Clicked, Close Window
			if (event.type == sf::Event::Closed)
				window.close();

			/* DEFINE EVENTS (i.e. KEY PRESS & RELEASE) HERE */
		}

		/* DEFINE ACTIONS (i.e. MOVEMENT) HERE */

		window.clear();
		/* DRAW OBJECTS HERE */
		window.display();
	}
}