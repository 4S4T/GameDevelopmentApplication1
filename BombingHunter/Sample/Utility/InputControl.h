#pragma once

#define D_KEYCODE_MAX 256

class InputControl
{
private:

	//���݂̓��͒l
	static char now_key[D_KEYCODE_MAX];
	//�O��̓��͒l
	static char old_key[D_KEYCODE_MAX];

public:
	//�X�V����
	static void Update();

	//���������Ă��邩�H
	static bool GetKey(int key_code);
	//�������u��
	static bool GetKeyDown(int key_code);
	//�������u��
	static bool GetKeyUp(int key_code);

	//�O�����J�̕K�v����������΁A�v���C�x�[�g
private:
	//�L�[�R�[�h�͈̓`�F�b�N
	static bool CheckkeyCodeRange(int key_code);
};