#include "DxLib.h"
#include"Utility/InputControl.h"
#include"Scene/Scene.h"

//メイン関数
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpcmdLine, _In_ int nShowCmd)
{
	//ウィンドウモードで起動
	ChangeWindowMode(TRUE);

	//DXライブラリの初期化
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	//描画先指定
	SetDrawScreen(DX_SCREEN_BACK);

	//オブジェクトの生成
	GameObject* object1 = new GameObject();
	Player* object2 = new Player();

	//初期化処理
	object1->Initialize();
	object2->Initialize();

	//メインループ
	while (ProcessMessage() != -1 && InputControl::GetKeyUp(KEY_INPUT_ESCAPE) == false)
	{

		//入力機能：更新処理
		InputControl::Update();

		//更新処理
		object1->Update();
		object2->Update();

		//画面初期化処理
		ClearDrawScreen();

		//描画
		object1->Draw();
		object2->Draw();

		//裏画面の内容を表画面に反映
		ScreenFlip();
	}

	//削除
	delete object1;
	delete object2;

	//終了
	DxLib_End();

	return 0;
}