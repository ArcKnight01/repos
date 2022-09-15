#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

enum tiletype {
	black,
	white
};

class Board {
public:
	sf::RectangleShape tileShape; //board spaces 
	int boardH, boardW; //board width and height 
	int tileH, tileW; //tile width and height 
	//rows per tile and col
	int tilesPerRow; 
	int tilesPerCol;
	//total number of tiles 
	int tileCount;
	std::vector<tiletype> tileTypes;
	int clickPos; //click position 
	bool newClick = false; //checks to see if you've clicked 
	bool pieceJumping = false; //check to see if the piece has been jumped over

	//constructor: dictates the  board height and width 
	Board(sf::RenderWindow &window, int height, int width, int tilesInRow, int tilesInCol);
	void drawBoard(sf::RenderWindow &window); //draws board
	//gets the position of the tile
	int getTileN(float x, float y);
	sf::Vector2f getTilePos(int N);
};