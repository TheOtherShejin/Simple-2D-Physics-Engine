#include <Physics2D/Math/Vector2.h>

Vector2::Vector2() : x(0), y(0) {}
Vector2::Vector2(real n) : x(n), y(n) {}
Vector2::Vector2(real x, real y) : x(x), y(y) {}

Vector2 Vector2::operator+(Vector2 other) {
	Vector2 temp = *this;
	temp += other;
	return temp;
}
Vector2 Vector2::operator-(Vector2 other) {
	Vector2 temp = *this;
	temp -= other;
	return temp;
}
Vector2 Vector2::operator*(real other) {
	Vector2 temp = *this;
	temp *= other;
	return temp;
}
Vector2 Vector2::operator/(real other) {
	Vector2 temp = *this;
	temp /= other;
	return temp;
}

void Vector2::operator+=(Vector2 other) {
	x += other.x;
	y += other.y;
}
void Vector2::operator-=(Vector2 other) {
	x -= other.x;
	y -= other.y;
}
void Vector2::operator*=(real other) {
	x *= other;
	y *= other;
}
void Vector2::operator/=(real other) {
	x /= other;
	y /= other;
}

real Vector2::Dot(Vector2& other) {
	return x * other.x + y * other.y;
}
real Vector2::Magnitude() {
	return sqrt(x * x + y * y);
}
real Vector2::MagnitudeSqrd() {
	return x * x + y * y;
}
Vector2 Vector2::Normalize() {
	return *this / Magnitude();
}
void Vector2::SetZero() {
	x = 0;
	y = 0;
}

std::ostream& operator<<(std::ostream& os, Vector2 const& vec) {
	os << '(' << vec.x << ", " << vec.y << ")";
	return os;
}