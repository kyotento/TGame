#include "stdafx.h"
#include "AIEditNode.h"

#include "../GameCursor.h"

// THIS IS CAMERA.
#include "../../GameCamera.h"

#include "AIEditNodeHp.h"


AIEditNode::~AIEditNode()
{
	DeleteGO(m_spriteRender);
	DeleteGO(m_spriteRender1);
	DeleteGO(m_spriteRender2);
	DeleteGO(m_spriteRender3);
	DeleteGO(m_spriteRender4);
	DeleteGO(m_spriteRender5);
}



bool AIEditNode::Start()
{

	m_gamecursor = FindGO<GameCursor>("cursor");

	//UI�̊��
	m_spriteRender = NewGO<SpriteRender>(3, "firstwin");
	m_spriteRender->Init(L"Assets/sprite/winkari.dds", 300, 500);
	CVector3 cursorpos = m_gamecursor->GetCursor();
	m_position = cursorpos;
	m_spriteRender->SetPosition(m_position);			//�J�[�\���̍��W

	//�{�^���P�`
	//SetPointPos(-70, 140);														//�{�^���̍��W�w��
	//m_spriteRender1= NewGO<SpriteRender>(2, "miniwin1");						//�\��
	//m_spriteRender1->Init(L"Assets/sprite/Hp.dds", 140, 100, true);				//�摜�̃t�@�C���p�X
	//m_spriteRender1->SetPosition(m_pointposition);								//���W�Z�b�g

	//SetPointPos(70, 140);
	//m_spriteRender2 = NewGO<SpriteRender>(2, "miniwin2");
	//m_spriteRender2->Init(L"Assets/sprite/Mp.dds", 140, 100, true);
	//m_spriteRender2->SetPosition(m_pointposition);

	//SetPointPos(-70, 40);
	//m_spriteRender3 = NewGO<SpriteRender>(2, "miniwin3");
	//m_spriteRender3->Init(L"Assets/sprite/karipoint.dds", 140, 100, true);
	//m_spriteRender3->SetPosition(m_pointposition);

	//SetPointPos(70, 40);
	//m_spriteRender4 = NewGO<SpriteRender>(2, "miniwin4");
	//m_spriteRender4->Init(L"Assets/sprite/karipoint.dds", 140, 100, true);
	//m_spriteRender4->SetPosition(m_pointposition);

	//SetPointPos(-70, -40);
	//m_spriteRender5 = NewGO<SpriteRender>(2, "miniwin5");
	//m_spriteRender5->Init(L"Assets/sprite/karipoint.dds", 140, 100, true);
	//m_spriteRender5->SetPosition(m_pointposition);

	int x = 70;			//�{�^����X���W
	int y = 240;		//�{�^����Y���W
	
	//�{�^����p
	for (int i = 0; i < 5; i++)		//i�͐����񂷂����̃n�����Y
	{
		x *= -1;					

		if (i % 2 == 0)
		{
			y -= 100;

		}

		SetPointPos(x,y);
		SpriteRender* sr = NewGO<SpriteRender>(0, "miniwin");
		sr->Init(L"Assets/sprite/karipoint.dds", 140, 100, true);
		sr->SetPosition(m_pointposition);
		m_spriteRenders.push_back(sr);
		
	}
	return true;

}

//�I���{�^���̎�ł��⏕
void AIEditNode::SetPointPos(int numx, int numy)
{
	//���̒l
	float x = 0;
	float y = 0;
	x = m_position.x;
	y = m_position.y;
	m_pointposition.x = x + numx;
	m_pointposition.y = y + numy;


}

void AIEditNode::Update()
{
	CVector3 cursorpos = m_gamecursor->GetCursor();

	//m_spriteRender1->SetCollisionTarget(cursorpos);
	m_spriteRenders[0]->SetCollisionTarget(cursorpos);


		if (m_spriteRenders[0]->isCollidingTarget())	//Hp��I�����Ă��邩	
		{

			if (Mouse::isTrigger(enLeftClick))	//�E�N���b�N
				NewGO<AIEditNodeHp>(0, "Hp");

		}
	
	
}

void AIEditNode::PostRender()
{
	//for (int i = 0; i < 5; i++) {
	//	m_font.Begin();
	//	wchar_t text[256];
	//	swprintf_s(text, L" HP ");

	//	m_font.Draw(text, { 0 , 0 });
	//	m_font.End();
	//}
}