#include "BarChart.h"

namespace SRT
{
	BarChart::BarChart(const std::multimap<int, int>& data, const sf::Color& barColor, const sf::Color& currentBarColor, std::shared_ptr<sf::RenderWindow> currentWindow) :
		m_data(data),
		m_barColor(barColor),
		m_currentBarColor(currentBarColor),
		m_currentWindow(currentWindow)
	{

	}

	int BarChart::NumberOfColumns() const
	{
		return 0;
	}

	void BarChart::Graph()
	{
		BuildBars();
		for (auto i : m_bars)
		{
			m_currentWindow->draw(i);
		}
	}

	void BarChart::BuildBars()
	{
		sf::Vector2f size(50, 100);
		sf::Vector2f position(20, 20);

		for (auto i : m_data)
		{
			sf::RectangleShape rectangle;
			rectangle.setSize(size);
			rectangle.setOutlineColor(sf::Color::Green);
			rectangle.setOutlineThickness(5);
			rectangle.setPosition(position);
			m_bars.push_back(rectangle);

			position.x = position.x + size.x + 30;
		}
	}
}