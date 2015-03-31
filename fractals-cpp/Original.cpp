#include <SFML/Graphics.hpp>
#include "Original.hpp"
#include <math.h> // sqrt
				
// ============================================================= recursive constructor
Original::Original(int depth, float radius, sf::Vector2f position, float outline) 
		: _depth(depth), _radius(radius), _position(position), _outline(outline)
{
	int shallowerDepth = _depth-1;
	
	// recursively create a child circle
	if(shallowerDepth > 0)
	{	
		// larger circles on the left and right
		_innerCirc1 = new Original(shallowerDepth, _radius/2, shiftHoriz(_position, _radius/2), _outline/2); 
		_innerCirc2 = new Original(shallowerDepth, _radius/2, shiftHoriz(_position, _radius/(-2)), _outline/2);
		// slightly smaller circles on the top and bottom
		_innerCirc3 = new Original(shallowerDepth, _radius/3, shiftVert(_position, _radius/2), _outline/3);
		_innerCirc4 = new Original(shallowerDepth, _radius/3, shiftVert(_position, _radius/(-2)), _outline/3);
	}
	else
	{
		_innerCirc1 = NULL;
		_innerCirc2 = NULL;
		_innerCirc3 = NULL;
		_innerCirc4 = NULL;
	}
}

// ======================================================================== destructor
Original::~Original()
{
	if(_innerCirc1 != NULL)
	{
		delete (_innerCirc1);
		delete (_innerCirc2);
		delete (_innerCirc3);
		delete (_innerCirc4);
	}
}

// ============================================================ horizontal shift function
sf::Vector2f Original::shiftHoriz(sf::Vector2f point, float distX)
{
	sf::Vector2f newPoint(point.x+(distX), point.y);
	return newPoint;
}

// ============================================================= vertical shift function
sf::Vector2f Original::shiftVert(sf::Vector2f point, float distY)
{
	sf::Vector2f newPoint(point.x, point.y+(distY));
	return newPoint;
}


// =================================================== overridden virtual draw function
void Original::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::CircleShape circ(_radius);
	circ.setOrigin(_radius, _radius);
	circ.setPosition(_position.x, _position.y);
	circ.setOutlineThickness(_outline);
	// outline is consistently blue
	circ.setOutlineColor(sf::Color(100, 150, 255));
	// with each recursion, fill is a slightly different color of pink.
	// opacity also decreases, which counterbalances the circles becoming
	// overly opaque due to layering
	circ.setFillColor(sf::Color(100, 150/_depth, 255/_depth, 255/_depth));

	// draw them
	target.draw(circ, states);

	if(_innerCirc1 != NULL)
	{
		_innerCirc1-> draw(target, states);
		_innerCirc2-> draw(target, states);
		_innerCirc3-> draw(target, states);
		_innerCirc4-> draw(target, states);
	}
}


















