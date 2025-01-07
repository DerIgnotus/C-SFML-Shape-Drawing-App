#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>


class Game
{
public:
	Game(sf::RenderWindow& window)
		: m_window{ window } {}

	void Run();

private:
	void HandleInput();
	void DrawRectangle();
	void DrawCircle();
	void SetMousePositions();

	sf::RenderWindow& m_window;
	std::vector<sf::RectangleShape> m_rectangles;
	std::vector<sf::CircleShape> m_circles;
	sf::Color m_current_color{ sf::Color::White };
	std::string m_current_shape{ "Rectangle" };
	float m_x_pos_init{ 0.0f };
	float m_y_pos_init{ 0.0f };
	float m_x_pos_final{ 0.0f };
	float m_y_pos_final{ 0.0f };
	sf::RectangleShape m_current_rect;
	sf::CircleShape m_current_circle;
};

