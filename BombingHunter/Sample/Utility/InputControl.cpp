#include "InputControl.h"
#include"DxLib.h"

//静的メンバ変数定義
char InputControl::now_key[D_KEYCODE_MAX] = {};
char InputControl::old_key[D_KEYCODE_MAX] = {};

//更新処理
void InputControl::Update()
{
	//前回入力値を更新する
	memcpy(old_key, now_key, (sizeof(char) * D_KEYCODE_MAX));
	//現在の入力値を更新する
	GetHitKeyStateAll(now_key);
}

//押し続けているか？
bool InputControl::GetKey(int key_code)
{
	return CheckkeyCodeRange(key_code) && ((now_key[key_code] == TRUE) && (old_key[key_code]) == TRUE);
}
//押した瞬間
bool InputControl::GetKeyDown(int key_code)
{
	return CheckkeyCodeRange(key_code) && ((now_key[key_code] == TRUE) && (old_key[key_code]) == FALSE);
}
//離した瞬間
bool InputControl::GetKeyUp(int key_code)
{
	return CheckkeyCodeRange(key_code) && ((now_key[key_code] == FALSE) && (old_key[key_code]) == TRUE);
}
//キーコード範囲チェック
bool InputControl::CheckkeyCodeRange(int key_code)
{
	return (0 <= key_code && key_code < D_KEYCODE_MAX);
}