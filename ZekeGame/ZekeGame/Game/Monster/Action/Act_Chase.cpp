#include "stdafx.h"
#include "Act_Chase.h"
//#include "MonsterAction.h"
#include "../Monster.h"

bool Act_Chase::Action(Monster* me)
{
	if (m_target == nullptr)
	{
		me->Setspeed(CVector3::Zero());
		//me->Setiswalk(false);
		me->anim_idle();
		return true;
	}

	CVector3 v = m_target->Getpos() - me->Getpos();
	if (v.Length() < 30+m_target->Getradius())
	{
		me->Setspeed(CVector3::Zero());
		//me->Setiswalk(false);
		me->anim_idle();
		return true;
	}
	me->anim_walk();
	v.Normalize();
	v *= 15;
	me->Setspeed(v);
	me->Setiswalk(true);

	m_time += IGameTime().GetFrameDeltaTime();
	if (m_time > 15.0f)
	{
		me->Setspeed(CVector3::Zero());
		me->anim_idle();
		return true;
	}

	return false;
}
