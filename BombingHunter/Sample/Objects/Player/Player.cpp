#include "Player.h"
#include"../../Utility/InputControl.h"
#include"DxLib.h"

Player::Player() :animation_count(0), flip_flag(FALSE)
{
	animation[0] = NULL;
	animation[1] = NULL;
}

Player::~Player()
{

}

