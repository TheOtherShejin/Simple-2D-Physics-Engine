#pragma once

#include <iostream>
#include <Physics2D/Precisions.h>

class Vector2 {
public:
	real x, y;

	Vector2();
	Vector2(real n);
	Vector2(real x, real y);
	
	Vector2 operator+(Vector2 other);
	Vector2 operator-(Vector2 other);
	Vector2 operator*(real other);
	Vector2 operator/(real other);

	void operator+=(Vector2 other);
	void operator-=(Vector2 other);
	void operator*=(real other);
	void operator/=(real other);

	real Dot(Vector2& other);
	real Magnitude();
	real MagnitudeSqrd();
	Vector2 Normalize();
	void SetZero();
};

std::ostream& operator<<(std::ostream& os, Vector2 const& vec);