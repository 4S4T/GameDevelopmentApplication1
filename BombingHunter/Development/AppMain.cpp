#include "DxLib.h"
#include "Utility/InputControl.h"
#include "Scene/Scene.h"

// メイン関数
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpcmdLine, _In_ int nShowCmd) {
	// ウィンドウモードで起動
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを設定
	SetGraphMode(640, 480, 32);

	// DXライブラリの初期化
	if (DxLib_Init() == -1) {
		return -1;
	}

	// ローカル変数定義
	Scene* scene = new Scene();
	int result = 0;

	// 描画先指定
	SetDrawScreen(DX_SCREEN_BACK);


	try {
		// シーン初期化
		scene->Initialize();

		// メインループ
		while (ProcessMessage() != -1 && CheckHitKey(KEY_INPUT_ESCAPE) != TRUE) {
			// 入力機能の更新
			InputControl::Update();
			// シーンの更新処理
			scene->Update();
			// 画面の初期化
			ClearDrawScreen();
			// シーンの描画処理
			scene->Draw();
			// 裏画面の内容を表画面に反映する
			ScreenFlip();
		}
	}
	catch (const char* error_log) {
		// エラー情報をLog.txtに出力する
		OutputDebugString(error_log);
		// 異常状態に変更する
		result = -1;
	}

	// シーン情報の削除する
	if (scene != nullptr) {
		scene->Finalize();
		delete scene;
		scene = nullptr;
	}

	// DXライブラリの終了時処理
	DxLib_End();
	// 終了状態を通知
	return result;
}
