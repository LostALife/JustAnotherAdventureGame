#pragma once
class Vector2
{
public:
	Vector2();
	Vector2(int _x, int _y);

public:
	int m_x;
	int m_y;

public:
	// Should these first two be references like the others?
	Vector2 operator+(const int _other);
	Vector2 operator+(const Vector2& _other);
	Vector2& operator+=(const int _other);
	Vector2& operator+=(const Vector2& _other);
	Vector2& operator=(const int _other);
	Vector2& operator=(const Vector2& _other);

	bool operator==(const Vector2& _other);
	bool operator!=(const Vector2& _other);
};

