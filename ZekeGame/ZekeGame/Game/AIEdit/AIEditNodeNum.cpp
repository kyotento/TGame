#include "stdafx.h"
#include "AIEditMode.h"
#include "AIEditNode.h"
#include "../GameCursor.h"

// THIS IS CAMERA.
#include "../../GameCamera.h"
#include "AIEditNodeNum.h"
AIEditNodeNum::~AIEditNodeNum()
{
	DeleteGO(m_spriteRender);
}


bool AIEditNodeNum::Start()
{
	m_gamecursor = FindGO<GameCursor>("cursor");

	//UIの基盤
	m_spriteRender = NewGO<SpriteRender>(1, "firstwinhp");
	m_spriteRender->Init(L"Assets/sprite/winkari.dds", 150, 250);
	CVector3 cursorpos = m_gamecursor->GetCursor();
	cursorpos.x += 135.0f;
	cursorpos.y += -140.0f;
	m_position = cursorpos;
	m_spriteRender->SetPosition(m_position);	//AIEditNodeのボタンの座標座標

	int x = 35;			//ボタンのX座標
	int y = 180;		//ボタンのY座標

						//ボタン専用
	for (int i = 0; i < 12; i++)		//iは数を回すだけのハム太郎 i<x xのところがボタンの数
	{
		x *= -1;

		if (i % 2 == 0)
		{
			y -= 50;

		}

		SetPointPos(x, y);
		SpriteRender* sr = NewGO<SpriteRender>(0, "miniwin");
		sr->Init(L"Assets/sprite/karipoint.dds", 70, 50, true);
		sr->SetPosition(m_pointposition);
		m_spriteRenders.push_back(sr);

	}
	return true;
}


void AIEditNodeNum::Update()
{


}


//選択ボタンの手打ち補助
void AIEditNodeNum::SetPointPos(int numx, int numy)
{
	//仮の値
	float x = 0;
	float y = -20;
	x = m_position.x;
	y = m_position.y;
	m_pointposition.x = x + numx;
	m_pointposition.y = y + numy;

}