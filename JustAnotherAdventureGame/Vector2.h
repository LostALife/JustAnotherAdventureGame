#pragma once
#include <cmath>

class Vector2
{
public:
	int m_x;
	int m_y;

public:
	Vector2();
	Vector2(int _x, int _y);

public:
	int Magnitude();

	static int Distance(Vector2 a, Vector2 b) {
		return (a - b).Magnitude();
	}

public:
	Vector2 operator+(const int _other) const {
		return Vector2(m_x + _other, m_y + _other);
	}

	Vector2 operator+(const Vector2& _other) const {
		return Vector2(m_x + _other.m_x, m_y + _other.m_y);
	}

	Vector2 operator-(const int _other) const {
		return Vector2(m_x - _other, m_y - _other);
	}

	Vector2 operator-(const Vector2& _other) const {
		return Vector2(m_x - _other.m_x, m_y - _other.m_y);
	}

	Vector2& operator+=(const int _other) {
		m_x += _other;
		m_y += _other;

		return *this;
	}

	Vector2& operator+=(const Vector2& _other) {
		m_x += _other.m_x;
		m_y += _other.m_y;

		return *this;
	}

	Vector2& operator-=(const int _other) {
		m_x -= _other;
		m_x -= _other;

		return *this;
	}

	Vector2& operator-=(const Vector2& _other) {
		m_x -= _other.m_x;
		m_y -= _other.m_y;

		return *this;
	}

	Vector2& operator=(const int _other) {
		m_x = _other;
		m_y = _other;

		return *this;
	}

	Vector2& operator=(const const Vector2& _other) {
		m_x = _other.m_x;
		m_y = _other.m_y;

		return *this;
	}

	bool operator==(const Vector2& _other) const {
		return m_x == _other.m_x && m_y == _other.m_y;
	}

	bool operator!=(const Vector2& _other) const {
		return m_x != _other.m_x && m_y != _other.m_y;
	}
};

