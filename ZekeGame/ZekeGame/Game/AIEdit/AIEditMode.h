#pragma once

class GameCursor;
// THIS IS CAMERA.
class GameCamera;

class AIEditNode;
/*
	AI��GUI�ō�邽�߂̃N���X
*/
class AIEditMode :public GameObject
{
public:
	//�f�X�g���N�^
	~AIEditMode();

	bool Start() override final;
	void Update() override final;
	//�K�v�ɉ����Ċ֐�������Ă������I�I	
	

private:
	//�����o�ϐ��͊�{�����ɏ������I�I
	
	//std::vector<SpriteRender*> m_sprits;


	GameCursor* m_cursor = nullptr;				// This is cursor
	GameCamera* m_camera = nullptr;				//<-THIS IS CAMERA
	AIEditNode* m_aieditnode = nullptr;
	SpriteRender * m_spriteRender;

};