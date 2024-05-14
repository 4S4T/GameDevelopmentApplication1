#include "DxLib.h"
#include"Utility/InputControl.h"
#include"Objects/Player/Player.h"


int WINAPI WinMain(_In_ HINSTANCE hInstance,_In_opt_ HINSTANCE hPrevInstance, _In_
LPSTR lpCmdLine, _In_ int nShowCmd)

{

		// ウィンドウモードで起動

	ChangeWindowMode(TRUE);



	// Dxライブラリの初期化処理

	if (DxLib_Init() == -1)


	{

		return -1;
	}

	GameObject* objects[2] = { nullptr, nullptr };
	objects[0] = new GameObject();
	objects[1] = new Player();

	for (int i = 0; i < 2; i++)
	{
		objects[i]->Initialize();
	}

	SetDrawScreen(DX_SCREEN_BACK);

	while (ProcessMessage() != -1)
	{
		InputControl::Update();

		for (int i = 0; i < 2; i++)
		{
			objects[i]->Update();
		}
		ClearDrawScreen();
		for (int i = 0; i < 2; i++)
		{
			objects[i]->Draw();
		}
		ScreenFlip();

		if (InputControl::GetKeyUp(KEY_INPUT_ESCAPE))
		{
			break;
		}
	}
	
	for (int i = 0; i < 2; i++)
	{
		objects[i]->Finalize();
		delete objects[i];
	}

	// Dxライブラリ使用の終了処理

	DxLib_End();



	return 0;

}
	
