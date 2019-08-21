#include "Game.h"
#include <iostream>

bool Game::winCheck() {
	if (squares[0].getOwner() == player && squares[1].getOwner() == player && squares[2].getOwner() == player)
	{
		win = true;
		return win;
	}
	if (squares[0].getOwner() == player && squares[4].getOwner() == player && squares[8].getOwner() == player)
	{
		win = true;
		return win;
	}
	if (squares[0].getOwner() == player && squares[3].getOwner() == player && squares[6].getOwner() == player)
	{
		win = true;
		return win;
	}
	if (squares[1].getOwner() == player && squares[4].getOwner() == player && squares[7].getOwner() == player)
	{
		win = true;
		return win;
	}
	if (squares[2].getOwner() == player && squares[5].getOwner() == player && squares[8].getOwner() == player)
	{
		win = true;
		return win;
	}
	if (squares[2].getOwner() == player && squares[4].getOwner() == player && squares[6].getOwner() == player)
	{
		win = true;
		return win;
	}
	if (squares[3].getOwner() == player && squares[4].getOwner() == player && squares[5].getOwner() == player)
	{
		win = true;
		return win;
	}if (squares[6].getOwner() == player && squares[7].getOwner() == player && squares[8].getOwner() == player)
	{
		win = true;
		return win;
	}
	return win;
}

bool Game::winStatus() {
	return win;
}

bool Game::drawCheck() {
	if (turn > 9)
		return true;
	return false;
}

void Game::playerSwitch() {
	if (player == 'x')
	{
		player = 'o';
	}
	else {
		player = 'x';
	}
}

char Game::getPlayer() {
	return player;
}

void Game::gameLogic(int x, int y) {

	auto squareListSize = squares.size();

	for (int i = 0; i < squareListSize; i++) 
	{
		if (x >= squares[i].getXinitial() && x <= squares[i].getXfinal()) 
		{
			if(y >= squares[i].getYinitial() && y <= squares[i].getYfinal())
			{
				if (squares[i].isOwned())
					return;
				squares[i].clicked(player);
				turn++;
				if (winCheck()) 
					return;
				playerSwitch();
			}
		}
	}
	return;
}

char Square::getOwner() {
	return owner;
}
bool Square::isOwned() {
	return owned;
}

int Square::getXinitial() {
	return xi;
}

int Square::getXfinal(){
	return xf;
}

int Square::getYfinal() {
	return yf;
}

int Square::getYinitial() {
	return yi;
}

void Square::clicked(char player) {
	owned = true;
	owner = player;
	setSprite();
}
void Square::setBounds(int x, int y) {
	xi = x;
	yi = y;
	yf = yi + 80;
	xf = xi + 80;
}

void Square::setSprite()
{
	switch (square)
	{
	case 1:
		if (isOwned()) {
			if (owner == 'x' && texture.loadFromFile("topleftx.png"))
				sprite.setTexture(texture);
			if (owner == 'o' && texture.loadFromFile("toplefto.png"))
				sprite.setTexture(texture);
		}
		if (!isOwned() && texture.loadFromFile("topleft.png"))
			sprite.setTexture(texture);
		setBounds(0, 0);
		sprite.setPosition(xi, yi);
		break;
	case 2:
		if (isOwned()) {
			if (owner == 'x' && texture.loadFromFile("middletopx.png"))
				sprite.setTexture(texture);
			if (owner == 'o' && texture.loadFromFile("middletopo.png"))
				sprite.setTexture(texture);
		}
		if (!isOwned() && texture.loadFromFile("middletop.png"))
			sprite.setTexture(texture);
		setBounds(80, 0);
		sprite.setPosition(xi, yi);
		break;
	case 3:
		if (isOwned()) {
			if (owner == 'x' && texture.loadFromFile("toprightx.png"))
				sprite.setTexture(texture);
			if (owner == 'o' && texture.loadFromFile("toprighto.png"))
				sprite.setTexture(texture);
		}
		if (!isOwned() && texture.loadFromFile("topright.png"))
			sprite.setTexture(texture);
		setBounds(160, 0);
		sprite.setPosition(xi, yi);
		break;
	case 4:
		if (isOwned()) {
			if (owner == 'x' && texture.loadFromFile("middleleftx.png"))
				sprite.setTexture(texture);
			if (owner == 'o' && texture.loadFromFile("middlelefto.png"))
				sprite.setTexture(texture);
		}
		if (!isOwned() && texture.loadFromFile("middleleft.png"))
			sprite.setTexture(texture);
		setBounds(0, 80);
		sprite.setPosition(xi, yi);
		break;
	case 5:
		if (isOwned()) {
			if (owner == 'x' && texture.loadFromFile("middlex.png"))
				sprite.setTexture(texture);
			if (owner == 'o' && texture.loadFromFile("middleo.png"))
				sprite.setTexture(texture);
		}
		if (!isOwned() && texture.loadFromFile("middle.png"))
			sprite.setTexture(texture);
		setBounds(80, 80);
		sprite.setPosition(xi, yi);
		break;
	case 6:
		if (isOwned()) {
			if (owner == 'x' && texture.loadFromFile("middlerightx.png"))
				sprite.setTexture(texture);
			if (owner == 'o' && texture.loadFromFile("middlerighto.png"))
				sprite.setTexture(texture);
		}
		if (!isOwned() && texture.loadFromFile("middleright.png"))
			sprite.setTexture(texture);
		setBounds(160, 80);
		sprite.setPosition(xi, yi);
		break;
	case 7:
		if (isOwned()) {
			if (owner == 'x' && texture.loadFromFile("bottomleftx.png"))
				sprite.setTexture(texture);
			if (owner == 'o' && texture.loadFromFile("bottomlefto.png"))
				sprite.setTexture(texture);
		}
		if (!isOwned() && texture.loadFromFile("bottomleft.png"))
			sprite.setTexture(texture);
		setBounds(0, 160);
		sprite.setPosition(xi, yi);
		break;
	case 8:
		if (isOwned()) {
			if (owner == 'x' && texture.loadFromFile("middlebottomx.png"))
				sprite.setTexture(texture);
			if (owner == 'o' && texture.loadFromFile("middlebottomo.png"))
				sprite.setTexture(texture);
		}
		if (!isOwned() && texture.loadFromFile("middlebottom.png"))
			sprite.setTexture(texture);
		setBounds(80, 160);
		sprite.setPosition(xi, yi);
		break;
	case 9:
		if (isOwned()) {
			if (owner == 'x' && texture.loadFromFile("bottomrightx.png"))
				sprite.setTexture(texture);
			if (owner == 'o' && texture.loadFromFile("bottomrighto.png"))
				sprite.setTexture(texture);
		}
		if (!isOwned() && texture.loadFromFile("bottomright.png"))
			sprite.setTexture(texture);
		setBounds(160, 160);
		sprite.setPosition(xi, yi);
		break;
	default:
		break;
	}
}



void Window::run() 
{
	Square topLeft(1), topMiddle(2), topRight(3), middleLeft(4), middle(5), middleRight(6), lowerLeft(7), middleLower(8), lowerRight(9);
	std::vector<Square> squares{ topLeft, topMiddle, topRight, middleLeft, middle, middleRight, lowerLeft, middleLower, lowerRight };
	Game game(squares);
	auto squaresSize = squares.size();

	for (int i = 0; i < squaresSize; i++)
		squares[i].setSprite();


	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left) {
					game.gameLogic(event.mouseButton.x, event.mouseButton.y);
				}
			}

		}

		if (game.winStatus()) {
			std::cout << game.getPlayer() << " has won the game.";
			window.close();
			return;
		}
		if (game.drawCheck()) {
			std::cout << "Draw";
			window.close();
			return;
		}

		window.clear(sf::Color::Green);
		for (int i = 0; i < squaresSize; i++)
			window.draw(squares[i].sprite);
		window.display();
	}
	return;
}