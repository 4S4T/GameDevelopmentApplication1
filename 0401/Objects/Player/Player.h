#pragma once

#include"../GameObject.h"
#include<vector>

class Player : public GameObject
{
private:
	//�����x
	Vector2D velocity;
	//�A�j���[�V�����f�[�^
	std::vector<int> animation_data;
	//�A�j���[�V�����̎���
	int animation_count;

	public:
	Player();
		virtual ~Player();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Draw() const override;
		virtual void Finalize() override;

	private:
		//�ړ�����
		void Movement();
		//�A�j���[�V�����̐���
		void AnimationControl();
};