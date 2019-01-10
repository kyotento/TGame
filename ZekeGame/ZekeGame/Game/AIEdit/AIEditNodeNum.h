#pragma once

class AIEditnode;
class AIEditNodeInequ;
class AIEditNodeNum : public GameObject
{
public:

	~AIEditNodeNum();

	bool Start() override final;
	void Update() override final;
	void SetPointPos(int numx, int numy);

private:

	SpriteRender * m_spriteRender;
	AIEditNode * m_aieditnode;
	GameCursor * m_gamecursor;
	CVector3 m_position = CVector3::Zero();
	CVector3 m_pointposition = CVector3::Zero();

	std::vector<SpriteRender*> m_spriteRenders;
};