#include "tile.h"
using namespace sf;
Tile::Tile(float startX, float startY, float initialSize) {
	position.x = startX;
	position.y = startY;
	size = initialSize;

	tileShape.setSize(sf::Vector2f(size, size));
	tileShape.setPosition(position);
	tileShape.setFillColor(Color(0, 0, 255));


}
Tile::Tile() {
	position.x = 0;
	position.y = 0;
	size = 10;
	tileShape.setSize(sf::Vector2f(size, size));
	tileShape.setPosition(position);
	tileShape.setFillColor(Color(0, 0, 255));
}
FloatRect Tile::getPosition() {
	return tileShape.getGlobalBounds();

}
void Tile::setPosition(float posX, float posY) {
	position.x = posX;
	position.y = posY;
	tileShape.setPosition(position);
}
Vector2f Tile::getLocation() {
	return position;
}
RectangleShape Tile::getShape() {
	return tileShape;
}
void Tile::checkForUser(Vector2f userPosition) {
	float topBound = position.y;
	float bottomBound = topBound + tileShape.getGlobalBounds().height;
	float leftBound = position.x;
	float rightBound = leftBound + tileShape.getGlobalBounds().width;
	if ((userPosition.y > topBound && userPosition.y < bottomBound) && (userPosition.x > leftBound && userPosition.x < rightBound)) {
		userIsInTile = true;
	}
	else {
		userIsInTile = false;
	}
}

void Tile::update() {
	if (Keyboard::isKeyPressed(Keyboard::Enter)) {
		if (userIsInTile) {
			if (tileState != "wall") {
				tileState = "wall";
			}
			else {
				tileState = "null";
			}
		}
	}
	if (tileState == "wall") {
		tileShape.setFillColor(Color(0, 0, 0));
	}
	else {
		if (userIsInTile) {
			tileShape.setFillColor(Color(255, 0, 0));
		}
		else {
			tileShape.setFillColor(Color(0, 0, 255));
		}
	}
}