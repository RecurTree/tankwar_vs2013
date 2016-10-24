#include "mysucai.h"
#include "tank.h"
tank::tank()
{
}
tank::~tank()
{
}
void tank::inittankinfo(stank &stank)
{
	memcpy_s(&m_obj, sizeof(stank), &stank, sizeof(stank));
}
void tank::tankmove(DWORD dwdir)
{
	if (dwdir!=m_obj.ndirection)
	{
		m_obj.ndirection = dwdir;
	}
	else
	{
		switch (dwdir)
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
	}
}
CPoint tank::getcenter()
{
	return CPoint(m_obj.nx, m_obj.ny);
}
void tank::getthreepoint(CPoint *ptthree)
{
	CPoint ptcenter(m_obj.nx, m_obj.ny);
	switch (m_obj.ndirection)
	{
	case UP:
		{
			ptthree[0] += ptcenter + CPoint(0, -2);
			ptthree[1] += ptcenter + CPoint(-1, -2);
			ptthree[2] += ptcenter + CPoint(1, -2);
		}
		break;
	case DOWN:
		{
			ptthree[0] += ptcenter + CPoint(0, 2);
			ptthree[1] += ptcenter + CPoint(-1, 2);
			ptthree[2] += ptcenter + CPoint(1, 2);
		}
		break;
	case LEFT:
		{
			ptthree[0] += ptcenter + CPoint(-2, 0);
			ptthree[1] += ptcenter + CPoint(-2, -1);
			ptthree[2] += ptcenter + CPoint(-2, 1);
		}
		break;
	case RIGHT:
		{
			ptthree[0] += ptcenter + CPoint(2, 0);
			ptthree[1] += ptcenter + CPoint(2, -1);
			ptthree[2] += ptcenter + CPoint(2, 1);
		}
		break;
	}
}
