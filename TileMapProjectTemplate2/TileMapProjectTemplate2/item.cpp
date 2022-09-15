#include "item.h"
using namespace sf;
Item::Item(Board& bref, int spawnPos) {
	boardref = &bref;
	tilePosition = spawnPos;

	position = boardref->getTilePos(tilePosition);
	velocity = sf::Vector2f(0.f, 0.f);
	acceleration = sf::Vector2f(0.f, 0.f);

	sf::IntRect rect[2];
	rect[0] = sf::IntRect(0, 0, 10, 10); //section of sprite image
	rect[1] = sf::IntRect(0, 0, 20, 20);

	itemShape.setFillColor(sf::Color::Blue);
	height = boardref->tileH, width = boardref->tileW;
	

	itemTexture.loadFromFile("Textures/emptyTile.png"); //for now, change in future...
	itemSprite.setTexture(itemTexture);
	itemSprite.setTextureRect(rect[1]); //make section of sprite image apear
	itemSprite.setScale(width / 20, height / 20);
}
void Item::draw(sf::RenderWindow& window) {
	sf::Vector2f tilePos;
	//set positions
	itemShape.setPosition(tilePos);
	itemSprite.setPosition(tilePos);
	
	//draw item
	window.draw(itemSprite);
}

void Item::update()
{
//	draw();
}
