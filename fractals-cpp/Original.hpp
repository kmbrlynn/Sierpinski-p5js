#ifndef Original_h
#define Original_h 
#include <SFML/Graphics.hpp>

class Original : public sf::Drawable
{
public:
	// con/destructors
	Original(int, float, sf::Vector2f, float);
	~Original();

	// given a point and a float, shift x by the float
	sf::Vector2f shiftHoriz(sf::Vector2f, float);

	// given a point and a float, shift y by the float
	sf::Vector2f shiftVert(sf::Vector2f, float);
		
private:
	// override abstract draw function, found in sf::Drawable
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	int _depth;
	float _radius;
	sf::Vector2f _position;
	float _outline;

	// each Original object contains pointers to 4 add'l ones
	Original* _innerCirc1;
	Original* _innerCirc2;
	Original* _innerCirc3;
	Original* _innerCirc4;
};

#endif

















