#include "Enemy.h"
#include "../../Utility/InputControl.h"
#include "DxLib.h"

// コンストラクタ
Enemy::Enemy() : animation_count(0), flip_flag(FALSE) {
	animation[0] = NULL;
	animation[1] = NULL;
}

// デストラクタ
Enemy::~Enemy() {
}

// 初期化処理
void Enemy::Initialize() {
	// 画像の読み込み
	animation[0] = LoadGraph("Resource/Images/BoxEnemy/1.png");
	animation[1] = LoadGraph("Resource/Images/BoxEnemy/2.png");

	// エラーチェック
	if (animation[0] == -1 || animation[1] == -1) {
		throw("箱敵の画像がありません\n");
	}

	// 向きの設定
	radian = 0.0f;
	// 大きさの設定
	scale = 64.0f;
	// 初期画像の設定
	image = animation[0];
}


// 更新処理
void Enemy::Update() {
	// 移動処理
	Movement();
	// アニメーション制限
	AnimationControl();
}

// 描画処理
void Enemy::Draw() const {
	DrawRotaGraphF(location.x, location.y, 1.0, radian, image, TRUE, flip_flag);

	// デバック用
#if _DEBUG

	// 当たり判定の可視化
	Vector2D box_collision_upper_left = location - (Vector2D(1.0f) * (float)scale / 2.0f);
	Vector2D box_collision_lower_right = location + (Vector2D(1.0) * (float)scale / 2.0f);
	DrawBoxAA(box_collision_upper_left.x, box_collision_upper_left.y, box_collision_lower_right.x, box_collision_lower_right.y, GetColor(255, 0, 0), FALSE);
#endif
}

// 終了時処理
void Enemy::Finalize() {
	// 使用した画像を解放する
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
}

// 当たり判定通知処理
void Enemy::OnHitCollision(GameObject* hit_object) {
	// 当たった時の処理
}

// 移動処理
void Enemy::Movement() {
	// 移動の速さ
	Vector2D velocity = 0.0f;

	//ｘが1ずつ進む
		velocity.x += 1.0f;

	// 現在の位置座標に速さを加算する
	location += velocity;

	//Xが640にいったら、戻る
	if (location.x == 640)
	{
		location.x = 0;
	}
}

// アニメーション制御
void Enemy::AnimationControl() {
	// フレームカウントを加算する
	animation_count++;

	// 60フレーム目に到達したら
	if (animation_count >= 60) {
		// カウントリセット
		animation_count = 0;

		// 画像の切替
		if (image == animation[0]) {
			image = animation[1];
		}
		else {
			image = animation[0];
		}
	}
}