#include "Vector2.h"

// Constructors

Vector2::Vector2() : m_x(0), m_y(0)
{
}

Vector2::Vector2(int _x, int _y)
{
	m_x = _x;
	m_y = _y;
}


// Functions

int Vector2::Magnitude()
{
	return sqrt(m_x * m_x + m_y * m_y);
}
