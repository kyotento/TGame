#include "stdafx.h"
#include "AIEditNode.h"

#include "../GameCursor.h"

// THIS IS CAMERA.
#include "../../GameCamera.h"



AIEditNode::~AIEditNode()
{

}



bool AIEditNode::Start()
{

	return true;

}



void AIEditNode::Update()
{
	
		//��ԏ��߂�window
		if ("�}�E�X�E�N���b�N")
		{
			m_spriteRender = NewGO<SpriteRender>(0, "firstwin");
			m_spriteRender->Init(L"sprite/kariwin.dds", 700, 400);
			m_spriteRender->SetPosition(/*���̉�*/);

		}

		//����L�΂��������������ɏo�Ă���window
		if ()
		{

		}

}