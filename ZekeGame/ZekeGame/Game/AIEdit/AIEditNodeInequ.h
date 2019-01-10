#pragma once

class GameCursor;
// THIS IS CAMERA.
class GameCamera;
class AIEditNode;
class AIEditNodeNum;
class AIEditNodeInequ : public GameObject
{

public:

	~AIEditNodeInequ();
	bool Start() override final;
	void Update() override final;
	void SetPointPos(int numx, int numy);
	void Num();

private:

	AIEditNode * m_aieditnode;
	SpriteRender * m_spriteRender;
	GameCursor * m_gamecursor;
	AIEditNodeNum* m_aieditnodenum;
	CVector3 m_position = CVector3::Zero();
	CVector3 m_pointposition = CVector3::Zero();
	

	std::vector<SpriteRender*> m_spriteRenders;

};