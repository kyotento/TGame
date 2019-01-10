#include "stdafx.h"
#include "AIEditNodeHp.h"

#include "../GameCursor.h"

#include "../../GameCamera.h"

#include "AIEditNode.h"


AIEditNodeHp::~AIEditNodeHp()
{

	DeleteGO(m_spriteRender);
}


bool AIEditNodeHp::Start()
{
	m_gamecursor = FindGO<GameCursor>("cursor");
	//m_aieditnode = FindGO<AIEditNode>("firstwin");

	//UI�̊��
	m_spriteRender = NewGO<SpriteRender>(1, "firstwinhp");
	m_spriteRender->Init(L"Assets/sprite/winkari.dds", 300, 500);
	CVector3 cursorpos = m_gamecursor->GetCursor();
	cursorpos.x += 270.0f;
	cursorpos.y += -140.0f;
	m_position = cursorpos;
	m_spriteRender->SetPosition(m_position);	//AIEditNode�̃{�^���̍��W���W
	/*CVector3 kaku = m_aieditnode->m_position;
	m_spriteRender->SetPosition(m_position);	*/		


	//SetPointPos(-70, 140);
	//m_spriteRender = NewGO<SpriteRender>(0, "miniwin1");
	//m_spriteRender->Init(L"Assets/sprite/karipoint.dds", 140, 100);
	//m_spriteRender->SetPosition(m_pointposition);

	//SetPointPos(70, 140);
	//m_spriteRender = NewGO<SpriteRender>(0, "miniwin2");
	//m_spriteRender->Init(L"Assets/sprite/karipoint.dds", 140, 100);
	//m_spriteRender->SetPosition(m_pointposition);

	//SetPointPos(-70, 40);
	//m_spriteRender = NewGO<SpriteRender>(0, "miniwin3");
	//m_spriteRender->Init(L"Assets/sprite/karipoint.dds", 140, 100);
	//m_spriteRender->SetPosition(m_pointposition);

	//SetPointPos(70, 40);
	//m_spriteRender = NewGO<SpriteRender>(0, "miniwin4");
	//m_spriteRender->Init(L"Assets/sprite/karipoint.dds", 140, 100);
	//m_spriteRender->SetPosition(m_pointposition);

	//SetPointPos(0, 200);
	//m_spriteRender = NewGO<SpriteRender>(0, "miniwin5");
	//m_spriteRender->Init(L"Assets/sprite/karipoint.dds", 140, 100);
	//m_spriteRender->SetPosition(m_pointposition);


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

		SetPointPos(x, y);
		SpriteRender* sr = NewGO<SpriteRender>(0, "miniwin");
		sr->Init(L"Assets/sprite/karipoint.dds", 140, 100, true);
		sr->SetPosition(m_pointposition);
		m_spriteRenders.push_back(sr);

	}
	return true;
}



//�I���{�^���̎�ł��⏕
void AIEditNodeHp::SetPointPos(int numx, int numy)
{
	//���̒l
	float x = 0;
	float y = 0;
	x = m_position.x;
	y = m_position.y;
	m_pointposition.x = x + numx;
	m_pointposition.y = y + numy;

}



void AIEditNodeHp::Update()
{

}