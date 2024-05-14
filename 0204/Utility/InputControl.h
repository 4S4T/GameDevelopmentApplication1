#pragma once

#define D_KEYCODE_MAX 256 // �L�[���͍ő�

class InputControl {
private:
	static char now_key[D_KEYCODE_MAX]; // ���݂̓��͒l
	static char old_key[D_KEYCODE_MAX]; // �O��̓��͒l

public:
	static void Update(); // �X�V����

	static bool GetKey(int key_code);	  // ���������Ă��邩
	static bool GetKeyDown(int key_code); // �������u�Ԃ�
	static bool GetKeyUp(int key_code);	  // �������u�Ԃ�

private:
	static bool CheckkeyCodeRange(int key_code); // �L�[�R�[�h�͈̓`�F�b�N
};