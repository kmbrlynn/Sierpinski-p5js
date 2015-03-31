#include <SFML/Graphics.hpp>
#include "Sierpinski.hpp"
#include <math.h> // sqrt

/*  =======================================================================================
	
	- "baseTri" refers to large/white rightside-up triangles
	- "subTri" refers to small/black upside-down triangles

						 +  B
						/ \
					   /   \
					  /     \
	  midpt(A, B)    /_______\    midpt(B, C)
			  		/ \\\|/// \
				   /   \\|//   \
				  /     \|/     \
	   	      A  + ----- + ----- +  C
				  
				  	midpt(A, C)

*/

// ============================================================= recursive constructor
Sierpinski::Sierpinski(int depth, sf::Vector2f A, sf::Vector2f B, sf::Vector2f C) : 
	_depth(depth), _A(A), _B(B), _C(C)
{
	int shallowerDepth = _depth-1;
	
	// make a center subTri
	subTriangle(_depth, _A, _B, _C);

	// recursively create 3 child baseTris
	if(shallowerDepth > 0)
	{
		_topTri = new Sierpinski(shallowerDepth, midpt(_A, _B), _B, midpt(_B, _C)); 
		_leftTri = new Sierpinski(shallowerDepth, _A, midpt(_A, _B), midpt(_C, _A));
		_rightTri = new Sierpinski(shallowerDepth, midpt(_C, A), midpt(_B, _C), _C);
	} 
	else
	{
		_topTri = NULL;
		_leftTri = NULL;
		_rightTri = NULL;
	}
}

// ======================================================================== destructor
Sierpinski::~Sierpinski()
{
	if(_topTri != NULL)
	{
		delete (_topTri);
		delete (_leftTri);
		delete (_rightTri);
	}
}

// ================================================================= midpoint function
sf::Vector2f Sierpinski::midpt(sf::Vector2f point1, sf::Vector2f point2)
{
	sf::Vector2f midpoint((point1.x + point2.x)/2, (point1.y + point2.y)/2);
	return midpoint;
}

// ==================================================================== subTri function
void Sierpinski::subTriangle(int depth, sf::Vector2f A, sf::Vector2f B, sf::Vector2f C)
{
	_subA = midpt(A, B);
	_subB = midpt(B, C);
	_subC = midpt(C, A);
}

// =================================================== overridden virtual draw function
void Sierpinski::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// make a baseTri
	sf::ConvexShape baseTri;
	baseTri.setFillColor(sf::Color::White);
	baseTri.setPointCount(3);
	baseTri.setPoint(0, _A);
	baseTri.setPoint(1, _B);
	baseTri.setPoint(2, _C);

	// make a subTri
	sf::ConvexShape subTri;
	subTri.setFillColor(sf::Color::Black);
	subTri.setPointCount(3);
	subTri.setPoint(0, _subA);
	subTri.setPoint(1, _subB);
	subTri.setPoint(2, _subC);

	// draw them
	target.draw(baseTri, states);
	target.draw(subTri, states);
	if(_topTri != NULL)
	{
		_topTri-> draw(target, states);
		_leftTri-> draw(target, states);
		_rightTri-> draw(target, states);
	}
}


