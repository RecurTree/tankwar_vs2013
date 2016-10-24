#pragma once
#include "bullet.h"
#include "draw.h"
#include "tank.h"
#include<vector>
using std::vector;

class game
{
public:
	draw m_draw;
	tank m_tank;
	vector<bullet> m_vecbullet;
	game();
	~game();
	void initgame();
protected:
	bool singleplayerloop();
	bool playertime();
	bool getinput(_Out_ char &keydown,_In_ int leixing);
	bool bullettime();
	bool tankmovecrash(DWORD dwdir);
	void setmapvaluetank(int x, int y, int nvalue);
	void setmapvaluebullet(int x, int y, int nvalue);
	bool createbullet(const tank &tank_, unsigned int nid, bullet &bullet_);
	bool bulletcrashall(CPoint &ptbullet);
	bool bulletcrashwall(int &nvalue, CPoint &ptbullet);
};

