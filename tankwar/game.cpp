#include "mysucai.h"
#include "game.h"
#include<conio.h>
game::game()
{
}
game::~game()
{
}
void game::initgamewindow()
{
	//设置窗口大小和标题
	m_draw.setwindowssize("Tank War v0.1", 100, 39);
	while (true)
	{
		char ch;
		m_draw.drawmenu();
		getinput(ch,menu);
	}
}
void game::initsingleplayergame()
{
	m_draw.drawmap();
	tank::stank stank{ 0, 10, 10, 10, 1 };
	m_tank.inittankinfo(stank);
	m_draw.drawtank(0, 10, 10, "①", "1");
}
bool game::singleplayerloop()
{
	DWORD dwplayerbegin = GetTickCount(), dwbullebegin = GetTickCount(), dwplayerend, dwbulletend;
	while (true)
	{
		dwplayerend = GetTickCount();
		if (dwplayerend - dwplayerbegin > 100)
		{
			dwplayerbegin = dwplayerend;
			playertime();
		}
		dwbulletend = GetTickCount();
		if (dwbulletend-dwbullebegin>50)
		{
			dwbullebegin = dwbulletend;
			bullettime();
		}
		//剩下的交给敌军表演
	}
	return false;
}
void game::initdoubleplayergame()
{
	initsingleplayergame();
	tank::stank stank2{ 0, 10, 30, 10, 1 };
	m_tank.inittankinfo(stank2);
	m_draw.drawtank(0, 30, 10, "②", "2");
}
bool game::doubleplayerloop()
{
	DWORD dwplayer1begin = GetTickCount(), dwbullet1begin = GetTickCount(), 
		dwplayer2begin=GetTickCount(),dwbullet2begin=GetTickCount(),
		dwplayer1end, dwbullet1end,
		dwplayer2end, dwbullet2end;
	while (true)
	{
		dwplayer1end = GetTickCount();
		if (dwplayer1end - dwplayer1begin > 100)
		{
			dwplayer1begin = dwplayer1end;
			playertime();
		}
		dwbullet1end = GetTickCount();
		if (dwbullet1end - dwbullet1begin > 50)
		{
			dwbullet1begin = dwbullet1end;
			bullettime();
		}
		dwplayer2end = GetTickCount();
		if (dwplayer2end - dwplayer2begin > 100)
		{
			dwplayer2begin = dwplayer2end;
			playertime();
		}
		dwbullet2end = GetTickCount();
		if (dwbullet2end - dwbullet2begin > 50)
		{
			dwbullet2begin = dwbullet2end;
			bullettime();
		}
		//剩下的交给敌军表演
	}
	return false;

}
bool game::playertime()
{
	char ch;
	m_draw.cleartank(m_tank.m_obj.ndirection, m_tank.m_obj.nx, m_tank.m_obj.ny);
	setmapvaluetank(m_tank.m_obj.nx, m_tank.m_obj.ny, 0);
	getinput(ch,control);
	m_draw.drawtank(m_tank.m_obj.ndirection, m_tank.m_obj.nx, m_tank.m_obj.ny, "①", tank_pic[1]);
	setmapvaluetank(m_tank.m_obj.nx, m_tank.m_obj.ny, m_tank.m_obj.nid);
	return true;
}
bool game::getinput(_Out_ char &KEYDOWN,_In_ int leixing)
{
	if (leixing == control)
	{
		if (KEYDOWN('w') || KEYDOWN('W'))
		{
			if (tankmovecrash(UP))
			{
				m_tank.tankmove(UP);
			}
		}
		if (KEYDOWN('S') || KEYDOWN('s'))
		{
			if (tankmovecrash(DOWN))
			{
				m_tank.tankmove(DOWN);
			}
		}
		if (KEYDOWN('A') || KEYDOWN('a'))
		{
			if (tankmovecrash(LEFT))
			{
				m_tank.tankmove(LEFT);
			}
		}
		if (KEYDOWN('D') || KEYDOWN('d'))
		{
			if (tankmovecrash(RIGHT))
			{
				m_tank.tankmove(RIGHT);
			}
		}
		if (KEYDOWN('P') || KEYDOWN('p'))
		{
			_getch();
		}
		if (KEYDOWN(VK_SPACE))
		{
			bullet bullet_;
			if (createbullet(m_tank, BULLET_ID_MINE, bullet_))
			{

				m_vecbullet.push_back(bullet_);
				m_draw.drawbullet(bullet_.m_obj.nx, bullet_.m_obj.ny, "o");
				setmapvaluebullet(bullet_.m_obj.nx, bullet_.m_obj.ny, BULLET_MINE);
			}

		}
		if (KEYDOWN(VK_ESCAPE))
		{
			initgamewindow();
		}
	}
	else if (leixing==menu)
	{
		if (KEYDOWN('1'))
		{
			initsingleplayergame();
			singleplayerloop();
		}
		if (KEYDOWN('2'))
		{
			initdoubleplayergame();
			doubleplayerloop();
		}
		if (KEYDOWN('3'))
		{
			
		}
		if (KEYDOWN('4'))
		{
			exit(0);
		}
	}
	return true;
}
bool game::bullettime()
{
	for (UINT i = 0; i < m_vecbullet.size();i++)
	{
		bullet &bullet_ = m_vecbullet[i];
		m_draw.clearbullet(bullet_.m_obj.nx, bullet_.m_obj.ny);
		setmapvaluebullet(bullet_.m_obj.nx, bullet_.m_obj.ny, 0);
		CPoint ptforward;
		bullet_.getforwardpoint(ptforward);
		if (bulletcrashall(ptforward))
		{
			m_vecbullet.erase(m_vecbullet.begin() + i);
			i--;
		}
		else
		{
			bullet_.bulletmove();
			m_draw.drawbullet(bullet_.m_obj.nx, bullet_.m_obj.ny, "o");
			setmapvaluebullet(bullet_.m_obj.nx, bullet_.m_obj.ny, bullet_.m_obj.nid | OBJ_TYPE_BULLET);
		}
	}
	return true;
}
bool game::tankmovecrash(DWORD dwdir)
{
	CPoint pt[3] = {};
	if (dwdir!=m_tank.m_obj.ndirection)
	{
		return true;
	}
	else
	{
		m_tank.getthreepoint(pt);
	}
	for (int i= 0; i < 3;i++)
	{
		if (m_draw.m_gnmap[pt[i].y][pt[i].x])
		{
			return false;
		}
	}
	return true;
}
void game::setmapvaluetank(int x, int y, int nvalue)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			m_draw.m_gnmap[y - 1 + i][x - 1 + j] = nvalue;
		}
	}
}
void game::setmapvaluebullet(int x, int y, int nvalue)
{
	m_draw.m_gnmap[y][x] = nvalue;
}
bool game::createbullet(const tank &tank_, unsigned int nid, bullet &bullet_)
{
	CPoint pt[3] = {};
	m_tank.getthreepoint(pt);
	bullet_ = { tank_.m_obj.ndirection, (unsigned int)pt[0].x, (unsigned int)pt[0].y, nid };
	if (!bulletcrashall(pt[0]))
	{
		return true;
	}
	return false;
}
bool game::bulletcrashall(CPoint &ptbullet)
{
	int &nvalue = m_draw.m_gnmap[ptbullet.y][ptbullet.x];
	if (!nvalue)
	{
		return false;
	}
	if (nvalue&OBJ_TYPE_WALL)
	{
		bulletcrashwall(nvalue, ptbullet);
	}
	else if (nvalue&OBJ_TYPE_TANK)
	{
		//子弹撞坦克的检测函数
	}
	return true;
}
bool game::bulletcrashwall(int &nvalue, CPoint &ptbullet)
{
	if (nvalue&WALL_ID_DIA)
	{
		return true;
	}
	else
	{
		nvalue--;
		if ((nvalue&WALL_BLOOD)==0)
		{
			nvalue = 0;
			m_draw.drawblank(ptbullet.x, ptbullet.y);
		}
	}
	return true;
}

