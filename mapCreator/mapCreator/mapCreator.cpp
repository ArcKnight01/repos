// iD Tech Game Plan - SFML Template
#include "tile.h"
#include "user.h"
// Include Needed for SFML
#include <SFML/Graphics.hpp>
// Include Needed for Animations
#include <SFML/Graphics/Rect.hpp>
// Include Needed for Text
#include <SFML/Graphics/Text.hpp>
using namespace sf;
/* DEFINE GAMESTATES HERE */

int main()
{
	const int windowWidth = 400;
	const int windowHeight = 400;
	const int tileSize = 10;

	int tileOrigin = tileSize / 2;
	const int tileCollumnsAmount = windowWidth / tileSize;
	const int tileRowsAmount = windowHeight / tileSize;
	const int total = tileCollumnsAmount*tileRowsAmount;
	//Tile tile(windowWidth / 2, windowHeight / 2, tileSize);
	Tile tiles[total];
	tiles[0].setPosition(100, 100);
	int tileNumber = 0;
	
	int imax = tileCollumnsAmount, jmax = tileRowsAmount;
	for (int i = 0; i < imax; i++) {
		for (int j = 0; j < jmax; j++) {
			tiles[tileNumber].setPosition(i*tileSize, j * tileSize);
			tileNumber++;
		}
	}


	// Create a Window to Display Graphics, Define Size and Window Name
	RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Map");
	
	/* CREATE OBJECTS AND ASSIGN OBJECT ATTRIBUTES HERE */
	//Tile tile(windowWidth / 2, windowHeight / 2, tileSize);
	User user(200, 200, 10);

	float userVelocity = 0.5f;

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
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			user.moveLeft();
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right)) {
			user.moveRight();
		}
		else if (Keyboard::isKeyPressed(Keyboard::Up)) {
			user.moveUp();
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down)) {
			user.moveDown();
		}
		//tile.checkForUser(user.getLocation());
		int checkTileNumber = 0;
		for (int i = 0; i < imax; i++) {
			for (int j = 0; j < jmax; j++) {
				//tiles[tileNumber].setPosition(tileOrigin + i * tileSize, tileOrigin + i * tileSize);
				tiles[checkTileNumber].checkForUser(user.getLocation());
				checkTileNumber++;
			}
		}
		//tile.update();
		int updateTileNumber = 0;
		for (int i = 0; i < imax; i++) {
			for (int j = 0; j < jmax; j++) {
				//tiles[tileNumber].setPosition(tileOrigin + i * tileSize, tileOrigin + i * tileSize);
				tiles[updateTileNumber].update();
				updateTileNumber++;
			}
		}
		user.update();

		window.clear(Color(0, 255, 0));
		/* DRAW OBJECTS HERE */
		//window.draw(tile.getShape());
		int drawTileNumber = 0;
		for (int i = 0; i < imax; i++) {
			for (int j = 0; j < jmax; j++) {
				//tiles[tileNumber].setPosition(tileOrigin + i * tileSize, tileOrigin + i * tileSize);
				window.draw(tiles[drawTileNumber].getShape());
				drawTileNumber++;
			}
		}
		window.draw(user.getShape());
		window.display();
	}
}