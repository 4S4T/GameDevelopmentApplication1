#include"Scene.h"

#include"../Objects/Player/Player.h"
#include"../Objects/Enemy/Enemy.h"

//コンストラクタ
Scene::Scene() :objects()
{

}

//デストラクタ
Scene::~Scene()
{
	Finalize();
}

//初期化処理
void Scene::Initialize()
{
	//プレイヤーを生成する
	CreateObject<Player>(Vector2D(320.0f, 240.0f));
	CreateObject<Enemy>(Vector2D(320.0f, 400.0f));
}

//更新処理
void Scene::Update()
{
	//シーンに存在するオブジェクトの更新処理
	for (GameObject* obj : objects)
	{
		obj->Update();
	}
}

//描画処理
void Scene::Draw()const
{
	//シーンに存在するオブジェクトの描画処理
	for (GameObject* obj : objects)
	{
		obj->Draw();
	}
}

//終了時処理
void Scene::Finalize()
{
	if (objects.empty())
	{
		return;
	}
	//各オブジェクトを削除する
	for (GameObject* obj :objects)
	{
		obj->Finalize();
		delete obj;
	}
	//動的配列の解放
	objects.clear();
}