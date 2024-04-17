#pragma once

#include"../Utility/Vector2D.h"

class GameObject
{
protected:

	unsigned int color; //色情報
	Vector2D location; //位置情報
	Vector2D box_size; //箱の大きさ

public:
	GameObject(); //インストラクタ
	virtual ~GameObject(); //デストラクト

	void Initialize(); 
	void Update(); 
	void Draw()const;
	void Finalize();

public:

	void SetLocation(Vector2D location); //位置を変更処理
	Vector2D GetLocation() const; //位置情報取得
	Vector2D GetBoxSize()const; //大きさ取得
};