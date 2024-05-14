#include "Player.h"
#include "../../Utility/InputControl.h"
#include "../../Utility/UserTemplate.h"
#include "DxLib.h"

Player::Player() : velocity(0.0f) {
}

Player::~Player() {
}

void Player::Initialize() {
	color = GetColor(255, 255, 255);
	box_size = Vector2D(32.0f);
	location = Vector2D(320.0f, 240.0f);
}

void Player::Update() {
	Movement();
}

void Player::Draw() const {
	Vector2D upper_left = location - (box_size / 2.0f);
	Vector2D lower_right = location + (box_size / 2.0f);

	DrawBoxAA(upper_left.x, upper_left.y, lower_right.x, lower_right.y, color, TRUE);
}

void Player::Finalize() {
}

void Player::Movement() {
	Vector2D direction = Vector2D(0.0f);

	if (InputControl::GetKey(KEY_INPUT_LEFT)) {
		direction.x = -0.5f;
		float max_speed = Abs<float>((5.0f * direction.x));
		velocity.x += direction.x;
		velocity.x = Min<float>(Max<float>(velocity.x, -max_speed), max_speed);
	}
	else if (InputControl::GetKey(KEY_INPUT_RIGHT)) {
		direction.x = 0.5f;
		float max_speed = Abs<float>((5.0f * direction.x));
		velocity.x += direction.x;
		velocity.x = Min<float>(Max<float>(velocity.x, -max_speed), max_speed);
	}
	else {
		if (velocity.x > 1e-6f) {
			float calc_speed = velocity.x - 0.1f;
			velocity.x = Min<float>(Max<float>(calc_speed, 0.0f), velocity.x);
		}
		else if (velocity.x < -1e-6f) {
			float calc_speed = velocity.x + 0.1f;
			velocity.x = Min<float>(Max<float>(calc_speed, velocity.x), 0.0f);
		}
	}

	if (location.x < (box_size.x / 2.0f)) {
		velocity.x = 0.0f;
		location.x = box_size.x / 2.0f;
	}
	else if (location.x > (640.0f - box_size.x / 2.0f)) {
		velocity.x = 0.0f;
		location.x = 640.0f - box_size.x / 2.0f;
	}
	location += velocity;
}