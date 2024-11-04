#pragma once
#include <SFML/Graphics.hpp>

class Ball 
{
	private:
		sf::Vector2f m_Position;
		sf::RectangleShape m_Shape;
		float m_Speed = 1000.0f;
		float m_DirectionX = 0.2f;
		float m_DirectionY = 0.2f;
	
	public:
		Ball(float startX, float startY);
		sf::FloatRect getPosition();
		sf::RectangleShape getShape();
		float getXVelocity();
		float getYVelocity();
		void reboundSides();
		void reboundTopOrBottom();
		void update(sf::Time dt);
};
