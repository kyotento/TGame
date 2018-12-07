#pragma once
#include "../../Engine/character/CharacterController.h"

class MonsterAction;
class MonsterEffect;
class PythonBridge;
class Monster:public GameObject
{
public:
	~Monster();

	void init(int HP, int MP, float speed, float radius, float height, SkinModelRender* smr, int animnum);

	bool Start() override final;
	void Update() override final;

	//Monster�̃A�N�V���������s����֐�
	void execute();

	//�ړ�����Ƃ��Ɏg���֐�
	void Move();

	//��]����Ƃ��Ɏg���֐�
	void Turn();

	//�m�b�N�o�b�N���Ɏg���֐�
	void Knockback();

	//�m�b�N�o�b�N�̎n�܂�
	//v: �m�b�N�o�b�N����x�N�g��
	void StartKnockback(CVector3 v);

	//���
	enum en_State
	{
		en_NowLoading,
		en_Execute,
		en_Dead,
	};

	//�g��python�̃t�@�C����ݒ肷��
	//st: �t�@�C���̖��O
	void SetpyFile(const char* st)
	{
		m_pyFile = st;
	}

	//�g��python�t�@�C���̖��O��Ԃ�
	const char* GetpyFile()
	{
		return m_pyFile;
	}

	//HP��Ԃ�
	int GetHP()
	{
		return m_HP;
	}

	//�_���[�W
	//d: �H�炤�_���[�W
	void Damage(int d)
	{
		m_HP -= d;
	}

	//MP��Ԃ�
	int GetMP()
	{
		return m_MP;
	}

	//�R���C�_�[�̔��a��Ԃ�
	float Getradius()
	{
		return m_radius;
	}

	//�R���C�_�[�̍�����Ԃ�
	float Getheight()
	{
		return m_height;
	}

	//���݂̃|�W�V������Ԃ�
	CVector3 Getpos()
	{
		return m_pos;
	}

	//�|�W�V������ݒ肷��
	//v: �ݒ肷��|�W�V����
	void Setpos(CVector3 v)
	{
		m_pos = v;
	}

	//�X�s�[�h��Ԃ�
	CVector3 Getspeed()
	{
		return m_movespeed;
	}

	//�X�s�[�h��ݒ肷��
	//v: �X�s�[�h�x�N�g��
	void Setspeed(CVector3 v)
	{
		m_oldmovespeed = m_movespeed;
		m_movespeed = v;
	}

	//
	CVector3 GetFrontvec()
	{
		CVector3 vec = m_movespeed;
		if (vec.Length() > 1.0f)
		{
			vec.Normalize();
			m_front = vec;
		}

		return m_front;
	}

	void SetRotation(CQuaternion rot);

	//�������Ă��邩��ݒ肷��
	void Setiswalk(bool b)
	{
		m_iswalk = b;
	}

	//�`�[����Ԃ�
	int Getteam()
	{
		return m_team;
	}

	//�`�[����ݒ肷��
	//t: �`�[��
	void Setteam(int t)
	{
		m_team = t;
	}

	//num��Ԃ�
	int Getnum()
	{
		return m_num;
	}

	//num��ݒ肷��
	//num: num
	void Setnum(int num)
	{
		m_num = num;
	}

	//ID��Ԃ�
	int GetID()
	{
		return m_ID;
	}

	//���ꂢ��Ȃ�
	Monster* Getmon()
	{
		return this;
	}

	//�A�N�V������������Ƃ��Ɏg��
	//ma: �����X�^�[�A�N�V����
	void AddAction(MonsterAction* ma);

	//�s���Ă���E�s���\��̃A�N�V������Ԃ�
	std::vector<MonsterAction*> Getactions()
	{
		return m_actions;
	}

	//�A�j���[�V����������Ƃ��͕K����������g�����ƁB
	void anim_idle();
	void anim_walk();
	void anim_atack();
	void anim_defense();
	void anim_recovery();

	//�A�j���[�V�����̏��
	enum anim
	{
		en_idle,
		en_walk,
		en_atack,
		en_defense,
		en_recovery,
	};

protected:
	const char* m_pyFile = NULL;				//�g��python�t�@�C���̖��O
	int m_ID = 0;								//�����X�^�[�̎�ނ𔻒f���邽�߂�ID
	int m_num = 0;								//�w�ԍ��݂����Ȋ���
	int m_team = 0;								//�`�[���ԍ�

	CharacterController m_cc;					//�L�����R��
	float m_radius = 0.0f;						//���a
	float m_height = 0.0f;						//����
	SkinModelRender* m_smr = nullptr;			//�X�L�����f�������_�[
	int m_HP = 0;								//HP
	int m_MP = 0;								//MP
	float m_gravity = 50.0f;					//�d��
	float m_speed = 0.0f;						//�X�s�[�h
	CVector3 m_movespeed = CVector3::Zero();	//���[�u�X�s�[�h
	CVector3 m_oldmovespeed = CVector3::Zero();	//�Ẫ��[�u�X�s�[�h
	CVector3 m_front = CVector3::Zero();		//�O����
	bool m_iswalk = false;						//
	bool m_isKnockback = false;					//
	CVector3 m_vKnockback = CVector3::Zero();	//
	CVector3 m_vSubKnock = CVector3::Zero();
	CVector3 m_pos = CVector3::Zero();			//�|�W�V����
	CQuaternion m_rot = CQuaternion::Identity();//��]

	PythonBridge* m_PB;

	std::vector<MonsterAction*> m_actions;		//�g���A�N�V����
	en_State m_state = en_NowLoading;
	bool isLoading = false;

	MonsterEffect* m_effect;

	int m_AnimNum = 0;							//�A�j���[�V�����̌�

	float m_time = 0.0f;
};