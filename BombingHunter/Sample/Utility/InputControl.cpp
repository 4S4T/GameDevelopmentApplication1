#include "InputControl.h"
#include"DxLib.h"

//�ÓI�����o�ϐ���`
char InputControl::now_key[D_KEYCODE_MAX] = {};
char InputControl::old_key[D_KEYCODE_MAX] = {};

//�X�V����
void InputControl::Update()
{
	//�O����͒l���X�V����
	memcpy(old_key, now_key, (sizeof(char) * D_KEYCODE_MAX));
	//���݂̓��͒l���X�V����
	GetHitKeyStateAll(now_key);
}

//���������Ă��邩�H
bool InputControl::GetKey(int key_code)
{
	return CheckkeyCodeRange(key_code) && ((now_key[key_code] == TRUE) && (old_key[key_code]) == TRUE);
}
//�������u��
bool InputControl::GetKeyDown(int key_code)
{
	return CheckkeyCodeRange(key_code) && ((now_key[key_code] == TRUE) && (old_key[key_code]) == FALSE);
}
//�������u��
bool InputControl::GetKeyUp(int key_code)
{
	return CheckkeyCodeRange(key_code) && ((now_key[key_code] == FALSE) && (old_key[key_code]) == TRUE);
}
//�L�[�R�[�h�͈̓`�F�b�N
bool InputControl::CheckkeyCodeRange(int key_code)
{
	return (0 <= key_code && key_code < D_KEYCODE_MAX);
}