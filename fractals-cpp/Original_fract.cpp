#include <SFML/Graphics.hpp>
#include "Original.hpp"
#include <cstdlib> // atoi
#include <math.h> // sqrt

int main(int argc, char* argv[]) 
{
	// parameters to main
	int recursionDepth = std::atoi(argv[1]);
	int size = std::atoi(argv[2]);

	// window
	sf::RenderWindow window(sf::VideoMode(size, size), "Circles!");
	window.setPosition(sf::Vector2i(200, 50));

	// initial circle values
	int radius = size/2;
	sf::Vector2f position(size/2, size/2);
	float outline = radius/20;
	sf::Color color(255/recursionDepth, 150, 150);

	while(window.isOpen())
	{
		sf::Event event;
		Original circ(recursionDepth, radius, position, outline);

		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}
	
		window.clear(sf::Color::White);
		window.draw(circ);
		window.display();
	}

	return 0;
}




