#pragma once

#include"../Utility/Vector2D.h"

class GameObject
{
protected:

	unsigned int color; //�F���
	Vector2D location; //�ʒu���
	Vector2D box_size; //���̑傫��

public:
	GameObject(); //�C���X�g���N�^
	virtual ~GameObject(); //�f�X�g���N�g

	void Initialize(); 
	void Update(); 
	void Draw()const;
	void Finalize();

public:

	void SetLocation(Vector2D location); //�ʒu��ύX����
	Vector2D GetLocation() const; //�ʒu���擾
	Vector2D GetBoxSize()const; //�傫���擾
};