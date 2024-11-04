#include "Ball.h"
#include <SFML/Graphics.hpp>

Ball::Ball(float startX, float startY) : m_Position(startX, startY)
{
	m_Shape.setSize(sf::Vector2f(10, 10));
	m_Shape.setPosition(m_Position);
}

sf::FloatRect Ball::getPosition()
{
	return m_Shape.getGlobalBounds();
}

sf::RectangleShape Ball::getShape()
{
	return m_Shape;
}

float Ball::getXVelocity()
{
	return m_DirectionX;
}

float Ball::getYVelocity()
{
	return m_DirectionY;
}

void Ball::reboundSides()
{
	m_DirectionX = -m_DirectionX;
}

void Ball::reboundTopOrBottom()
{
	m_DirectionY = -m_DirectionY;
}

void Ball::update(sf::Time dt)
{
	// Update the ball's position
	m_Position.y += m_DirectionY * m_Speed * dt.asSeconds();
	m_Position.x += m_DirectionX * m_Speed * dt.asSeconds();
	// Move the ball
	m_Shape.setPosition(m_Position);
}