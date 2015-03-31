#include <SFML/Graphics.hpp>
#include "Sierpinski.hpp"
#include <cstdlib> // atoi
#include <math.h> // sqrt

int main(int argc, char* argv[]) 
{
	// parameters to main
	int recursionDepth = std::atoi(argv[1]);
	int size = std::atoi(argv[2]);

	// window
	double windowHeight = (sqrt(3)/2)*size;
	sf::RenderWindow window(sf::VideoMode(size, windowHeight), "Sierpinski's Triangle");
	window.setPosition(sf::Vector2i(200, 50));

	// points of largest baseTri
	sf::Vector2f A(0, windowHeight);
	sf::Vector2f B(size/2, 0);
	sf::Vector2f C(size, windowHeight);

	while(window.isOpen())
	{
		sf::Event event;
		Sierpinski tri(recursionDepth, A, B, C);

		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}
	
		window.clear(sf::Color::Blue);
		window.draw(tri);
		window.display();
	}

	return 0;
}




