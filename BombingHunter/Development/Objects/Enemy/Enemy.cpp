#include "Enemy.h"
#include "../../Utility/InputControl.h"
#include "DxLib.h"

// �R���X�g���N�^
Enemy::Enemy() : animation_count(0), flip_flag(FALSE) {
	animation[0] = NULL;
	animation[1] = NULL;
}

// �f�X�g���N�^
Enemy::~Enemy() {
}

// ����������
void Enemy::Initialize() {
	// �摜�̓ǂݍ���
	animation[0] = LoadGraph("Resource/Images/BoxEnemy/1.png");
	animation[1] = LoadGraph("Resource/Images/BoxEnemy/2.png");

	// �G���[�`�F�b�N
	if (animation[0] == -1 || animation[1] == -1) {
		throw("���G�̉摜������܂���\n");
	}

	// �����̐ݒ�
	radian = 0.0f;
	// �傫���̐ݒ�
	scale = 64.0f;
	// �����摜�̐ݒ�
	image = animation[0];
}


// �X�V����
void Enemy::Update() {
	// �ړ�����
	Movement();
	// �A�j���[�V��������
	AnimationControl();
}

// �`�揈��
void Enemy::Draw() const {
	DrawRotaGraphF(location.x, location.y, 1.0, radian, image, TRUE, flip_flag);

	// �f�o�b�N�p
#if _DEBUG

	// �����蔻��̉���
	Vector2D box_collision_upper_left = location - (Vector2D(1.0f) * (float)scale / 2.0f);
	Vector2D box_collision_lower_right = location + (Vector2D(1.0) * (float)scale / 2.0f);
	DrawBoxAA(box_collision_upper_left.x, box_collision_upper_left.y, box_collision_lower_right.x, box_collision_lower_right.y, GetColor(255, 0, 0), FALSE);
#endif
}

// �I��������
void Enemy::Finalize() {
	// �g�p�����摜���������
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
}

// �����蔻��ʒm����
void Enemy::OnHitCollision(GameObject* hit_object) {
	// �����������̏���
}

// �ړ�����
void Enemy::Movement() {
	// �ړ��̑���
	Vector2D velocity = 0.0f;

	//����1���i��
		velocity.x += 1.0f;

	// ���݂̈ʒu���W�ɑ��������Z����
	location += velocity;

	//X��640�ɂ�������A�߂�
	if (location.x == 640)
	{
		location.x = 0;
	}
}

// �A�j���[�V��������
void Enemy::AnimationControl() {
	// �t���[���J�E���g�����Z����
	animation_count++;

	// 60�t���[���ڂɓ��B������
	if (animation_count >= 60) {
		// �J�E���g���Z�b�g
		animation_count = 0;

		// �摜�̐ؑ�
		if (image == animation[0]) {
			image = animation[1];
		}
		else {
			image = animation[0];
		}
	}
}