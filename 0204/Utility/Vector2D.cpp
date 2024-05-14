#include "Vector2D.h"
#include <math.h>

// �R���X�g���N�^
Vector2D::Vector2D() : x(0.0f), y(0.0f) {
}

Vector2D::Vector2D(float scalar) : x(scalar), y(scalar) {
}

Vector2D::Vector2D(float mx, float my) : x(mx), y(my) {
}

// �f�X�g���N�^
Vector2D::~Vector2D() {
}

// ���ȑ��
Vector2D& Vector2D::operator=(const Vector2D& location) {
	// ���g�̃����o�ϐ���X�̈����̒l��������
	this->x = location.x;
	// ���g�̃����o�ϐ���Y�̈����̒l��������
	this->y = location.y;

	// �������g��Ԃ�
	return *this;
}

// ���Z����
const Vector2D Vector2D::operator+(const Vector2D& location) const {
	Vector2D result = Vector2D(0.0f);

	result.x = this->x + location.x;
	result.y = this->y + location.y;

	return result;
}

// ���ȑ��
Vector2D& Vector2D::operator+=(const Vector2D& location) {
	this->x += location.x;
	this->y += location.y;

	return *this;
}

// ���Z����
const Vector2D Vector2D::operator-(const Vector2D& location) const {
	Vector2D result = Vector2D(0.0f);

	result.x = this->x - location.x;
	result.y = this->y - location.y;

	return result;
}

// ���ȑ��
Vector2D& Vector2D::operator-=(const Vector2D& location) {
	this->x -= location.x;
	this->y -= location.y;

	return *this;
}

// ��Z����
const Vector2D Vector2D::operator*(const float& scalar) const {
	Vector2D result = Vector2D(0.0f);

	result.x = this->x * scalar;
	result.y = this->y * scalar;

	return result;
}

// ���ȑ��
const Vector2D Vector2D::operator*(const Vector2D& location) const {
	Vector2D result = Vector2D(0.0f);

	result.x = this->x * location.x;
	result.y = this->y * location.y;

	return result;
}

// ���Z����
Vector2D& Vector2D::operator*=(const float& scalar) {
	this->x *= scalar;
	this->y *= scalar;

	return *this;
}

// ���ȑ��
Vector2D& Vector2D::operator*=(const Vector2D& location) {
	this->x *= location.x;
	this->y *= location.y;

	return *this;
}

// ���ȑ��
const Vector2D Vector2D::operator/(const float& scalar) const {
	if (fabsf(scalar) < 1e-6f) {
		return Vector2D(0.0f);
	}
	return Vector2D(this->x / scalar, this->y / scalar);
}

const Vector2D Vector2D ::operator/(const Vector2D& location) const {
	if ((fabsf(location.x) < 1e-6f) || (fabsf(location.y) < 1e-6f)) {
		return Vector2D(0.0f);
	}
	return Vector2D(this->x / location.x, this->y / location.y);
}

Vector2D& Vector2D::operator/=(const float& scalar) {
	if (fabsf(scalar) < 1e-6f) {
		this->x = 0.0f;
		this->y = 0.0f;
	}
	else {
		this->x /= scalar;
		this->y /= scalar;
	}

	return *this;
}


Vector2D& Vector2D::operator/=(const Vector2D& location) {
	if ((fabsf(location.x) < 1e-6f) || (fabsf(location.y) < 1e-6f)) {
		this->x = 0.0f;
		this->y = 0.0f;
	}
	else {
		this->x /= location.x;
		this->y /= location.y;
	}

	return *this;
}

// �����l�ɃL���X�g
void Vector2D::ToInt(int* x, int* y) const {
	*x = static_cast<int>(this->x);
	*y = static_cast<int>(this->y);
}