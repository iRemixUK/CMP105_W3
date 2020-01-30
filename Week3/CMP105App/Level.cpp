#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	//Red rectangle
	rect.setSize(sf::Vector2f(50, 25));
	rect.setPosition(100, 100);
	rect.setFillColor(sf::Color::Red);

	speed = -200.f;
	

	
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
}

// Update game objects
void Level::update(float dt)
{
	//update/move circle
	rect.move(speed * dt, 0);
	sf::Vector2f rectpos = rect.getPosition();
	sf::Vector2u size = window->getSize();
	if (rectpos.x == 675 || rectpos.x == 0)
	{
		speed = -200.f;
	}
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(rect);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}