#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	//Rectangle
	rect.setSize(sf::Vector2f(50, 25));
	rect.setPosition(100, 100);
	rect.setFillColor(sf::Color::Red);

	// Bounce rectangle
	rectr.setSize(sf::Vector2f(50, 25));
	rectr.setPosition(500, 300);
	rectr.setFillColor(sf::Color::Blue);
	speedrx = 200.f;
	speedry = 100.f;
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Up)) // Up
	{
		speedy = -200.f;
	}
	else if (input->isKeyDown(sf::Keyboard::Down)) // Down
	{
		speedy = 200.f;
	}
	else
	{
		speedy = 0;
	}

	if (input->isKeyDown(sf::Keyboard::Left)) // Left
	{
		speedx = -200.f;
	}
	else if (input->isKeyDown(sf::Keyboard::Right)) // Right
	{
		speedx = 200.f;
	}
	else
	{
		speedx = 0;
	}
}

// Update game objects
void Level::update(float dt)
{
	//update/move circle
	
	sf::Vector2f rectpos = rect.getPosition();
	sf::Vector2f rectsize = rect.getSize();

	sf::Vector2f rectrpos = rectr.getPosition();
	sf::Vector2f rectrsize = rectr.getSize();

	sf::Vector2u size = window->getSize();

	if (rectpos.x >= size.x - rectsize.x)
	{
		speedx = 0;
		speedx = -200.f;
	}

	if (rectpos.x <= 0)
	{
		speedx = 0;
		speedx = 200.f;
	}

	if (rectpos.y >= size.y - rectsize.y)
	{
		speedy = 0;
		speedy = -200.f;

	}

	if (rectpos.y <= 0)
	{
		speedy = 0;
		speedy = 200.f;
	}

	rect.move(speedx * dt, speedy * dt);
	rectr.move(speedrx * dt, speedry * dt);
	if (rectrpos.x >= size.x - rectrsize.x)
	{
		speedrx = -200.f;
	}

	if (rectrpos.x <= 0)
	{
		speedrx = 200.f;
	}

	if (rectrpos.y >= size.y - rectrsize.y)
	{
		speedry = -100.f;

	}

	if (rectrpos.y <= 0)
	{
		speedry = 100.f;
	}
	
	rectr.move(speedrx * dt, speedry * dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(rect);
	window->draw(rectr);
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