#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Game.h"

//Enumerator for checkertype moved to Game.h

class Piece {
public:
	//poitner refrences to the board and game
	Board* boardref; //pointers
	Game* gameref;
	int position;// positon
	bool alive = true;//check if piece is alive
	bool selected = false;//see if the piece has been selected 
	checkertype color;
	bool kinged = false;//check if the piece has 
	sf::CircleShape checkerShape; 

	Piece();//defualt constructor
	Piece(checkertype col, int pos, Board &ref, Game &gref);
	void drawPiece(sf::RenderWindow &window);//creates piece
	void update(std::vector<Piece*> checkers); //updates board when the piece is moved
	void selectPiece();
	void placePiece(std::vector<Piece*> checkers); //place pieces on the board and define where they are
};
