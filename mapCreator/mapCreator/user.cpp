#include "user.h"
using namespace sf;
User::User(float startX, float startY, float initialSize) {
	position.x = startX;
	position.y = startY;
	size = initialSize;

	userShape.setSize(sf::Vector2f(size, size));
	userShape.setPosition(position);
}
FloatRect User::getPosition() {
	return userShape.getGlobalBounds();
}
Vector2f User::getLocation() {
	return position;
}
RectangleShape User::getShape() {
	return userShape;
}
void User::moveLeft() {
	position.x -= userSpeed;
}
void User::moveRight() {
	position.x += userSpeed;
}
void User::moveUp() {
	position.y -= userSpeed;
}
void User::moveDown() {
	position.y += userSpeed;
}
void User::update() {
	userShape.setPosition(position);
}