#pragma once

class Monster;
class MonsterAction:public GameObject
{
public:
	//�A�N�V�����̉��z�֐��B������p�������A�N�V�����͊�{�I�ɂ��ꂾ�����g��
	//me: �A�N�V�������g�����񂷂��[
	virtual bool Action(Monster* me) { return false; };
	
	//�A�N�V�������s���Ώۂ̃����X�^�[�̐ݒ������
	//num: �Ώۃ����X�^�[��num
	void Settarget(int num);
	//void Resettarget();

	//���ڃ����X�^�[��ݒ肷��
	//mon: �Ώۃ����X�^�[
	void Settarget(Monster* mon)
	{
		m_target = mon;
	}

	//�Ώۃ����X�^�[��Ԃ�
	Monster* Gettarget()
	{
		return m_target;
	}
protected:
	int m_ActionId = 0;				//�A�N�V������ID
	int m_targetNum = 0;			//�^�[�Q�b�g��num
	Monster* m_me = nullptr;		//�g�����񂷂��[
	Monster* m_target = nullptr;	//�^�[�Q�b�g

	float m_time = 0.0f;			//����
};