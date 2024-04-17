#include "DxLib.h"
#include"Utility/InputControl.h"
#include"Scene/Scene.h"

//���C���֐�
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpcmdLine, _In_ int nShowCmd)
{
	//�E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	//�`���w��
	SetDrawScreen(DX_SCREEN_BACK);

	//�I�u�W�F�N�g�̐���
	GameObject* object1 = new GameObject();
	Player* object2 = new Player();

	//����������
	object1->Initialize();
	object2->Initialize();

	//���C�����[�v
	while (ProcessMessage() != -1 && InputControl::GetKeyUp(KEY_INPUT_ESCAPE) == false)
	{

		//���͋@�\�F�X�V����
		InputControl::Update();

		//�X�V����
		object1->Update();
		object2->Update();

		//��ʏ���������
		ClearDrawScreen();

		//�`��
		object1->Draw();
		object2->Draw();

		//����ʂ̓��e��\��ʂɔ��f
		ScreenFlip();
	}

	//�폜
	delete object1;
	delete object2;

	//�I��
	DxLib_End();

	return 0;
}