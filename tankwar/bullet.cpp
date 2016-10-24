#include "mysucai.h"
#include "bullet.h"
bullet::bullet(unsigned int dwdir, unsigned int dwx, unsigned int dwy, unsigned int dwid)
{
	m_obj.ndirection = dwdir;
	m_obj.nx = dwx;
	m_obj.ny = dwy;
	m_obj.nblood = 1;
	m_obj.nid = dwid;
}
bullet::~bullet()
{
}
void bullet::getforwardpoint(_Out_ CPoint &ptforward)
{
	ptforward = { (int)m_obj.nx, (int)m_obj.ny };
	switch (m_obj.ndirection)
	{
	case UP:
		ptforward.y--;
		break;
	case DOWN:
		ptforward.y++;
		break;
	case LEFT:
		ptforward.x--;
		break;
	case RIGHT:
		ptforward.x++;
		break;
	}
}
bool bullet::bulletmove()
{
	switch (m_obj.ndirection)
	{
	case UP:
		m_obj.ny--;
		break;
	case DOWN:
		m_obj.ny++;
		break;
	case LEFT:
		m_obj.nx--;
		break;
	case RIGHT:
		m_obj.nx++;
		break;
	}
	return true;
}