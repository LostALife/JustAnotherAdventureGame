#include "Vector2.h"

Vector2::Vector2() : m_x(0), m_y(0)
{
}

Vector2::Vector2(int _x, int _y)
{
	m_x = _x;
	m_y = _y;
}

Vector2 Vector2::operator+(const int _other)
{
	Vector2 result{};

	result.m_x + _other;
	result.m_y + _other;

	return result;
}

Vector2 Vector2::operator+(const Vector2& _other)
{
	Vector2 result{};

	result.m_x + _other.m_x;
	result.m_y + _other.m_y;

	return result;
}

Vector2& Vector2::operator+=(const int _other)
{
	m_x + _other;
	m_y + _other;

	return *this;
}

Vector2& Vector2::operator+=(const Vector2& _other)
{
	m_x + _other.m_x;
	m_y + _other.m_y;

	return *this;
}

Vector2& Vector2::operator=(const int _other)
{
	m_x = _other;
	m_y = _other;
}

Vector2& Vector2::operator=(const Vector2& _other)
{
	m_x = _other.m_x;
	m_y = _other.m_y;
}

bool Vector2::operator==(const Vector2& _other)
{
	if (m_x == _other.m_x && m_y == _other.m_y) {
		return true;
	}
}

bool Vector2::operator!=(const Vector2& _other)
{
	if (!(m_x == _other.m_x) && !(m_y == _other.m_y)) {
		return true;
	}
}
