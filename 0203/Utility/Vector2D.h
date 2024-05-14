#pragma once

class Vector2D {
public:
	float x;
	float y;

public:
	// コンストラクタ
	Vector2D();
	Vector2D(float scalar);
	Vector2D(float mx, float my);
	// デストラクタ
	~Vector2D();

public:
	// 各演算処理

	Vector2D& operator=(const Vector2D& location);

	const Vector2D operator+(const Vector2D& location) const;
	Vector2D& operator+=(const Vector2D& location);

	const Vector2D operator-(const Vector2D& location) const;
	Vector2D& operator-=(const Vector2D& location);

	const Vector2D operator*(const float& scalar) const;
	const Vector2D operator*(const Vector2D& location) const;
	Vector2D& operator*=(const float& scalar);
	Vector2D& operator*=(const Vector2D& location);

	const Vector2D operator/(const float& scalar) const;
	const Vector2D operator/(const Vector2D& location) const;
	Vector2D& operator/=(const float& scalar);
	Vector2D& operator/=(const Vector2D& location);

	// 整数値にキャスト
	void ToInt(int* x, int* y) const;
};