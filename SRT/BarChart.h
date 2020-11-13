#ifndef BARCHART_H
#define BARCHART_H
#include <SFML/Graphics.hpp>
#include <map>

namespace SRT
{
	class BarChart
	{
	public:
		BarChart() = default;
		BarChart(const std::multimap<int, int>& data, const sf::Color& barColor, const sf::Color& currentBarColor, std::shared_ptr<sf::RenderWindow> currentWindow);

	public:
		void Graph();

	private:
		int NumberOfColumns() const;
		void BuildBars();

	private:
		std::multimap<int, int> m_data;
		sf::Color m_barColor;
		sf::Color m_currentBarColor;
		std::vector<sf::RectangleShape> m_bars;
		std::shared_ptr<sf::RenderWindow> m_currentWindow;
	};
}

#endif
