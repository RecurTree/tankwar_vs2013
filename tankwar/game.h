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
	tank m_tank2;
	vector<bullet> m_vecbullet;
	game();
	~game();
	bool issingle = true;
	void initgamewindow();
protected:
	void initsingleplayergame();
	bool singleplayerloop();
	void initdoubleplayergame();
	bool doubleplayerloop();
	bool player1time();
	bool player2time();
	bool getinput(_Out_ char &keydown,_In_ int leixing);
	bool bullet1time();
	bool bullet2time();
	bool tankmovecrash(DWORD dwdir,tank &tank_);
	void setmapvaluetank(int x, int y, int nvalue);
	void setmapvaluebullet(int x, int y, int nvalue);
	bool createbullet(tank &tank_, unsigned int nid, bullet &bullet_);
	bool bulletcrashall(CPoint &ptbullet);
	bool bulletcrashwall(int &nvalue, CPoint &ptbullet);
};

