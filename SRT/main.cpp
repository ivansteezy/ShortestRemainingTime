#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include "BarChart.h"


#define CHECK_IF_APP_CLOSED(WINDOW, EVENT) \
while (WINDOW->pollEvent(ev)) \
{\
	if (EVENT.type == sf::Event::Closed)\
	{\
		WINDOW->close();\
	}\
}

int main()
{
	auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "Title");
	sf::Event ev;

	std::multimap<int, int> mymap;
	mymap.insert(std::make_pair<int, int>(12, 12));
	mymap.insert(std::make_pair<int, int>(12, 12));
	mymap.insert(std::make_pair<int, int>(12, 12));

	SRT::BarChart chart(mymap, sf::Color::Red, sf::Color::Red, window);


	while (window->isOpen())
	{
		CHECK_IF_APP_CLOSED(window, ev);
		window->clear();
		chart.Graph();
		window->display();
	}
	return 0;
}