#pragma once

class GameCursor;
// THIS IS CAMERA.
class GameCamera;
class AIEditNodeHp;
class AIEditNodeInequ;
class AIEditNode : public GameObject
{

public:

	~AIEditNode();

	bool Start() override final;
	void Update() override final;
	void SetPointPos(int numx, int numy);
	void PostRender() override final;
	void Inequ();

		
private:

	int button = 5;
	bool Choice1 = false;				//‰½‚©‚ð‘I‘ð‚·‚é‚Ætrue‚É‚È‚é

	GameCursor * m_gamecursor;
	AIEditNodeHp * m_aieditnodehp;
	AIEditNodeInequ* m_aieditnodeinequ;
	SpriteRender * m_spriteRender;
	SpriteRender * m_spriteRender1;
	SpriteRender * m_spriteRender2;
	SpriteRender * m_spriteRender3;
	SpriteRender * m_spriteRender4;
	SpriteRender * m_spriteRender5;
	CVector3 m_position = CVector3::Zero();
	CVector3 m_pointposition = CVector3::Zero();
	CFont m_font;

	std::vector<SpriteRender*> m_spriteRenders;
};