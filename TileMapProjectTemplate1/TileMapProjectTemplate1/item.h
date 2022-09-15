#pragma once
#include "Tile.h"
#include <SFML/Graphics.hpp>
// Include Needed for Animations
#include <SFML/Graphics/Rect.hpp>
// Include Needed for Text
#include <SFML/Graphics/Text.hpp>
#include <vector>
#include <iostream>
#include <string>
using namespace sf;

class Item {
	public:
		//reference to board
		Board* boardref;

		//the tile position of item on board
		int tilePosition;
		//the coordinates of the item's position (x,y)
		Vector2f position;
		Vector2f velocity; 
		Vector2f acceleration;

		//CircleShape itemShape;
		RectangleShape itemShape;
		sf::Texture itemTexture;
		sf::Sprite itemSprite;
		//dimensions of item
		float height, width;

		//name of item
		string itemName = "";

		Item(Board& bref, int spawnPos);
		void draw(sf::RenderWindow& window);
		void spawn();
		void update();

	private:

};