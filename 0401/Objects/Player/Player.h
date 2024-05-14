#pragma once

#include"../GameObject.h"
#include<vector>

class Player : public GameObject
{
private:
	//加速度
	Vector2D velocity;
	//アニメーションデータ
	std::vector<int> animation_data;
	//アニメーションの時間
	int animation_count;

	public:
	Player();
		virtual ~Player();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Draw() const override;
		virtual void Finalize() override;

	private:
		//移動処理
		void Movement();
		//アニメーションの制御
		void AnimationControl();
};