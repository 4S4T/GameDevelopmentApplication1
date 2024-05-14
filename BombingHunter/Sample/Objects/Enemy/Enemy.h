#pragma once

#include"../GameObject.h"

class Enemy :public GameObject
{

private:
	//�A�j���[�V�����摜
	int animation[2];
	//�A�j���[�V��������
	int animation_count;
	//�i�s����
	Vector2D direction;

public:
	Enemy();
	~Enemy();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;
	//�����蔻��ʒm����
	virtual void OnHitCollision(GameObject* hit_object) override;

private:

	//�ړ�����
	void Movement();
	//�A�j���[�V��������
	void AnimationControl();

};