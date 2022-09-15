#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace sf;

class Tile {
private:
	Vector2f position;
	RectangleShape tileShape;
	float size;
public:
	bool userIsInTile = false;
	string tileState = "null";
	Tile(float startX, float startY, float initialSize);
	Tile();
	Vector2f getLocation();
	FloatRect getPosition();
	RectangleShape getShape();
	void setPosition(float posX, float posY);
	void checkForUser(Vector2f userPosition);
	void update();
};