#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace sf;

class User {
private:
	Vector2f position;
	RectangleShape userShape;
	float size;
public:
	User(float startX, float startY, float initialSize);
	float userSpeed = 0.5f;
	FloatRect getPosition();
	RectangleShape getShape();
	Vector2f getLocation();
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void update();
};