#include "Game.h"


void Game::Run()
{
	while (m_window.isOpen())
	{
		m_window.clear();

		for (int i = 0; i < m_rectangles.size(); i++)
		{
			m_window.draw(m_rectangles[i]);
		}
		for (int j = 0; j < m_circles.size(); j++)
		{
			m_window.draw(m_circles[j]);
		}

		HandleInput();

		m_window.display();
	}
}

void Game::HandleInput()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}

		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				m_x_pos_init = 0.0f;
				m_y_pos_init = 0.0f;
				m_x_pos_final = 0.0f;
				m_y_pos_final = 0.0f;

				if (m_current_shape == "Rectangle")
				{
					m_rectangles.push_back(m_current_rect);
				}
				else if (m_current_shape == "Circle")
				{
					m_circles.push_back(m_current_circle);
				}
				else
				{
					std::cout << "Something Went Wrong! Check Strings!" << std::endl;
				}
			}
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) m_current_shape = "Rectangle";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) m_current_shape = "Circle";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) m_current_color = sf::Color::White;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) m_current_color = sf::Color::Blue;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) m_current_color = sf::Color::Red;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) m_current_color = sf::Color::Green;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) m_current_color = sf::Color::Magenta;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) m_current_color = sf::Color::Cyan;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) m_current_color = sf::Color::Yellow;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (m_current_shape == "Rectangle")
		{
			SetMousePositions();

			DrawRectangle();
		}
		else if (m_current_shape == "Circle")
		{
			SetMousePositions();

			DrawCircle();
		}
		else
		{
			std::cout << "Something Went Wrong! Check Strings!" << std::endl;
		}
	}
}

void Game::DrawRectangle()
{
	m_current_rect = sf::RectangleShape();
	m_current_rect.setSize(sf::Vector2f(m_x_pos_final - m_x_pos_init, m_y_pos_final - m_y_pos_init));
	m_current_rect.setFillColor(m_current_color);
	m_current_rect.setPosition(m_x_pos_init, m_y_pos_init);
	m_window.draw(m_current_rect);
}

void Game::DrawCircle()
{
	m_current_circle = sf::CircleShape();
	float radius = std::sqrt(std::pow(m_x_pos_final - m_x_pos_init, 2) + std::pow(m_y_pos_final - m_y_pos_init, 2));
	m_current_circle.setRadius(radius / 2);
	m_current_circle.setPosition(m_x_pos_init, m_y_pos_init - radius);
	m_current_circle.setFillColor(m_current_color);
	m_window.draw(m_current_circle);
}

void Game::SetMousePositions()
{
	if (m_x_pos_init == 0.0f && m_x_pos_init == 0.0f)
	{
		m_x_pos_init = sf::Mouse::getPosition(m_window).x;
		m_y_pos_init = sf::Mouse::getPosition(m_window).y;
	}

	m_x_pos_final = sf::Mouse::getPosition(m_window).x;
	m_y_pos_final = sf::Mouse::getPosition(m_window).y;
}
