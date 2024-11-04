#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace sf;
int main() 
{
	VideoMode vm(1920, 1080);
	RenderWindow window(vm, "Pong", Style::Fullscreen);

	int score = 0;
	int lives = 3;

	//Initialize bats to left and right vertical centered on screen
	Bat bat1(0, 1080/2);
	Bat bat2(1915, 1080/2);
	Ball ball(1920 / 2, 0);
	Clock clock;

	Text Score;
	Text Player1Score;
	Text Player2Score;

	Font font;
	font.loadFromFile("fonts/DS-DIGIB.TTF");

	Score.setFont(font);
	Player1Score.setFont(font);
	Player2Score.setFont(font);

	Score.setCharacterSize(75);
	Player1Score.setCharacterSize(75);
	Player2Score.setCharacterSize(75);

	Score.setFillColor(Color::White);
	Player1Score.setFillColor(Color::White);
	Player2Score.setFillColor(Color::White);

	Score.setPosition(1920 / 2 - 75, 10);
	Player1Score.setPosition(1920 / 2 - 150, 20);
	Player2Score.setPosition(1920 / 2 + 150, 20);

	Score.setString("Score");


	int player1Score = 0;
	int player2Score = 0;

	while (window.isOpen())
	{
		Time dt = clock.restart();
		// Handle player input
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			if (bat1.getPosition().top > 0)
			{
				bat1.stopDown();
				bat1.moveUp();
				bat1.update(dt);
			}
			
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			if (bat2.getPosition().top > 0)
			{
				bat2.stopDown();
				bat2.moveUp();
				bat2.update(dt);
			}

		}
		
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			
			if (bat1.getPosition().top + 50 < 1080)
			{
				bat1.stopUp();
				bat1.moveDown();
				bat1.update(dt);
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			if (bat2.getPosition().top + 50 < 1080)
			{
				bat2.stopUp();
				bat2.moveDown();
				bat2.update(dt);
			}
		}

		
		if (ball.getPosition().top > window.getSize().y ||
			ball.getPosition().top < 0)
		{
			ball.reboundTopOrBottom();
		}

		//ball hits left side so right player scores
		if (ball.getPosition().left < 0)
		{
			player2Score++;
			ball.reboundSides();
		}

		//ball hits right side so left player scores
		if (ball.getPosition().left > window.getSize().x)
		{
			player1Score++;
			ball.reboundSides();
		}

		// Has the ball hit the bat?
		if (ball.getPosition().intersects(bat1.getPosition()) ||
			ball.getPosition().intersects(bat2.getPosition()))
		{
			
			ball.reboundSides();
		}

		std::stringstream ss;
		ss << player1Score;
		Player1Score.setString(ss.str());
		std::stringstream ss2;
		ss2 << player2Score;
		Player2Score.setString(ss2.str());

		ball.update(dt);
		

		window.clear();
		window.draw(Score);
		window.draw(Player1Score);
		window.draw(Player2Score);
		window.draw(ball.getShape());
		window.draw(bat1.getShape());
		window.draw(bat2.getShape());
		window.display();

		
	}
	return 0;
}