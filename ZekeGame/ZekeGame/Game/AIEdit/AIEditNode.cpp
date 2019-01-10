#include "stdafx.h"
#include "AIEditNode.h"

#include "../GameCursor.h"

// THIS IS CAMERA.
#include "../../GameCamera.h"

#include "AIEditNodeHp.h"
#include "AIEditNodeInequ.h"

AIEditNode::~AIEditNode()
{
	DeleteGO(m_spriteRender);
	//DeleteGO(m_spriteRender1);
	//DeleteGO(m_spriteRender2);
	//DeleteGO(m_spriteRender3);
	//DeleteGO(m_spriteRender4);
	//DeleteGO(m_spriteRender5);
}



bool AIEditNode::Start()
{

	m_gamecursor = FindGO<GameCursor>("cursor");

	//UIの基盤
	m_spriteRender = NewGO<SpriteRender>(3, "firstwin");
	m_spriteRender->Init(L"Assets/sprite/winkari.dds", 150, 250);
	CVector3 cursorpos = m_gamecursor->GetCursor();
	m_position = cursorpos;
	m_spriteRender->SetPosition(m_position);			//カーソルの座標

	//ボタン１～
	//SetPointPos(-70, 140);														//ボタンの座標指定
	//m_spriteRender1= NewGO<SpriteRender>(2, "miniwin1");						//表示
	//m_spriteRender1->Init(L"Assets/sprite/Hp.dds", 140, 100, true);				//画像のファイルパス
	//m_spriteRender1->SetPosition(m_pointposition);								//座標セット

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

	int x = 35;			//ボタンのX座標
	int y = 120;		//ボタンのY座標
	
	//ボタン専用
	for (int i = 0; i < button; i++)		//iは数を回すだけのハム太郎  
	{
		x *= -1;					

		if (i % 2 == 0)
		{
			y -= 50;

		}

		SetPointPos(x,y);
		SpriteRender* sr = NewGO<SpriteRender>(0, "miniwin");
		sr->Init(L"Assets/sprite/karipoint.dds", 70, 50, true);
		sr->SetPosition(m_pointposition);
		m_spriteRenders.push_back(sr);
		
	}
	return true;

}

//選択ボタンの手打ち補助
void AIEditNode::SetPointPos(int numx, int numy)
{
	//仮の値
	float x = 0;
	float y = 0;
	x = m_position.x;
	y = m_position.y;
	m_pointposition.x = x + numx;
	m_pointposition.y = y + numy;


}

void AIEditNode::Inequ()
{
	if (Mouse::isTrigger(enLeftClick))	//rightクリック
	{
		NewGO<AIEditNodeInequ>(0, "Inequality");

		Choice1 = true;
	}

}

void AIEditNode::Update()
{
	CVector3 cursorpos = m_gamecursor->GetCursor();

	for (int i = 0; i < button; i++) {

		m_spriteRenders[i]->SetCollisionTarget(cursorpos);

	}
	if (Choice1 == false) { //何も選択していないとき
		if (m_spriteRenders[0]->isCollidingTarget())	//Hpを選択しているか	
		{
			Inequ();
		}

		if (m_spriteRenders[1]->isCollidingTarget())	//Mpを選択しているか	
		{
			Inequ();
		}

		if (m_spriteRenders[2]->isCollidingTarget())	//Atkを選択しているか	
		{
			Inequ();
		}

		if (m_spriteRenders[3]->isCollidingTarget())	//Defを選択しているか	
		{
			Inequ();
		}
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


	//CVector3 pos = m_spriteRender->GetPosition();

	//m_font.Begin();
	//wchar_t text[256];
	//swprintf_s(text, L" HP ");
	//m_font.Draw(text, { pos.x,pos.y });
	//m_font.End();
}