#pragma once

#define D_KEYCODE_MAX 256

class InputControl
{
private:

	//現在の入力値
	static char now_key[D_KEYCODE_MAX];
	//前回の入力値
	static char old_key[D_KEYCODE_MAX];

public:
	//更新処理
	static void Update();

	//押し続けているか？
	static bool GetKey(int key_code);
	//押した瞬間
	static bool GetKeyDown(int key_code);
	//離した瞬間
	static bool GetKeyUp(int key_code);

	//外部公開の必要性が無ければ、プライベート
private:
	//キーコード範囲チェック
	static bool CheckkeyCodeRange(int key_code);
};