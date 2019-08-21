#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <SFML/System.hpp>

class Square {
private:
	int square;
	int xi, xf, yi, yf;
	char owner;
	bool owned = false;
public:
	sf::Sprite sprite;
	sf::Texture texture;

	Square(int i) : square(i)
	{}
	void setSprite();
	void setBounds(int x, int y);
	void clicked(char player);
	int getXinitial();
	int getYinitial();
	int getXfinal();
	int getYfinal();
	bool isOwned();
	char getOwner();
};

class Game {
private:
	char player = 'x';
	std::vector<Square>& squares;
	int turn = 1;
	bool win = false;
	bool draw = false;
public:
	Game(std::vector<Square>& SQUARES) : squares(SQUARES) {}
	void gameLogic(int x, int y);
	void playerSwitch();
	char getPlayer();
	bool winCheck();
	bool drawCheck();
	bool winStatus();
};


class Window {
private:
	sf::RenderWindow& window;
	bool gameCreated = false;
public:
	void run();
	Window(sf::RenderWindow& WINDOW) : window(WINDOW)
	{}
};
