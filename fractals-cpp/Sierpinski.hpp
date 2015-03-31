#ifndef Sierpinski_h
#define Sierpinski_h 
#include <SFML/Graphics.hpp>

class Sierpinski : public sf::Drawable
{
public:
	// con/destructors
	Sierpinski(int, sf::Vector2f, sf::Vector2f, sf::Vector2f);
	~Sierpinski();

	// given 2 points, return their midpoint
	sf::Vector2f midpt(sf::Vector2f, sf::Vector2f);
	
	// given baseTri points, determine subTri points
	void subTriangle(int, sf::Vector2f, sf::Vector2f, sf::Vector2f);
		
private:
	// override abstract draw function, found in sf::Drawable
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	int _depth;
	
	// points of a baseTri
	sf::Vector2f _A;
	sf::Vector2f _B;
	sf::Vector2f _C;

	// points of a subTri
	sf::Vector2f _subA;
	sf::Vector2f _subB;
	sf::Vector2f _subC;

	// each Sierpinski object contains pointers to three add'l ones
	Sierpinski* _topTri;
	Sierpinski* _leftTri;
	Sierpinski* _rightTri;
};

#endif











































