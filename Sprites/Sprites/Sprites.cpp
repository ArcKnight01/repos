// iD Tech Game Plan - SFML Template

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
	sf::RenderWindow window(sf::VideoMode(600, 780), "Sprites!");

	/* CREATE OBJECTS AND ASSIGN OBJECT ATTRIBUTES HERE */
	sf::Texture playerTex;
	playerTex.loadFromFile("Textures/player_ship.png");
	sf::Sprite playerSprite;
	playerSprite.setTexture(playerTex);
	playerSprite.setScale(1.5, 1.5);
	playerSprite.setPosition(100, 100);
	playerSprite.setOrigin(32, 32); // sizeofSprite/2 = 64/2 = 32

	/* DEFINE VARIABLES HERE */
	bool movingUp = false;
	bool movingDown = false;
	bool movingLeft = false;
	bool movingRight = false;

	// Run the Program while the Window is Open
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{	
			// When X Button Clicked, Close Window
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			/* DEFINE EVENTS (i.e. KEY PRESS & RELEASE) HERE */
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::W) {
					movingUp = true;
				}
				if (event.key.code == sf::Keyboard::S) {
					movingDown = true;
				}
				if (event.key.code == sf::Keyboard::A) {
					movingLeft = true;
				}
				if (event.key.code == sf::Keyboard::D) {
					movingRight = true;
				}
			}
			if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::W) {
					movingUp = false;
				}
				if (event.key.code == sf::Keyboard::S) {
					movingDown = false;
				}
				if (event.key.code == sf::Keyboard::A) {
					movingLeft = false;
				}
				if (event.key.code == sf::Keyboard::D) {
					movingRight = false;
				}
			}

		}

		/* DEFINE ACTIONS (i.e. MOVEMENT) HERE */
		sf::Vector2f movement(0, 0);
		int speed = 5;
		if (movingUp)
			movement.y -= speed * 0.1f;
		if (movingDown)
			movement.y += speed * 0.1f;
		if (movingLeft)
			movement.x -= speed * 0.1f;
		if (movingRight)
			movement.x += speed * 0.1f;

		playerSprite.move(movement);

		window.clear();
		/* DRAW OBJECTS HERE */
		window.draw(playerSprite); 
		window.display();
	}
}