#pragma once

#include"../GameObject.h"

class Enemy :public GameObject
{

private:
	//アニメーション画像
	int animation[2];
	//アニメーション時間
	int animation_count;
	//進行方向
	Vector2D direction;

public:
	Enemy();
	~Enemy();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;
	//当たり判定通知処理
	virtual void OnHitCollision(GameObject* hit_object) override;

private:

	//移動処理
	void Movement();
	//アニメーション制御
	void AnimationControl();

};