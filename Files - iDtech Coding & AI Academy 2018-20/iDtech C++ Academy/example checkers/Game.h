#pragma once
#include <SFML/Graphics.hpp>
#include <string>

const int playerCount = 2; //keeps track of how many players

//enumerator allwoing to compare redteam and whiteteam
//similar to the board tiles
enum checkertype {
	redteam,
	whiteteam
};

class Game {
public:
	int playerTurn = 0; //keeps track of whose trun it is
	//rectangle that is either red or white depending on whose turn it is
	sf::RectangleShape turnIndicator; 
	checkertype turnColor;
	int pieceTotal [playerCount]; //array that keeps track of the total pieces

	//text and style for the victory message
	std::string victoryMsg [playerCount];
	sf::Text victoryText;
	sf::Font victoryFont;

	//constructor 
	Game(int startingPieces); //overloaded constructor
	void changeTurn(); //exchange turns
	void drawTurn(sf::RenderWindow &window); 
	void drawVictory(sf::RenderWindow &window); //draw victory window
	bool losePiece(checkertype color);  //allows piece to go away
};