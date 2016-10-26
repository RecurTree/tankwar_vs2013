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
	tank m_enemytank1;
	tank m_enemytank2;
	tank m_enemytank3;
	vector<bullet> m_vecbullet1;
	vector<bullet> m_vecbullet2;
	game();
	~game();
	bool isplayer1 = true;
	bool issingle = true;
	void initgamewindow();
protected:
	void initsingleplayergame();
	void initenemytank();
	void initdoubleplayergame();
	bool singleplayerloop();
	bool doubleplayerloop();
	bool player1time();
	bool player2time();
	char getdirfromrand(int rand);
	bool enemy1time();
	bool enemy2time();
	bool enemy3time();
	bool getinput(_Out_ char &ch,_In_ int leixing,_In_ int who);
	bool bullet1time();
	bool bullet2time();
	bool tankmovecrash(DWORD dwdir,tank &tank_);
	void setmapvaluetank(int x, int y, int nvalue);
	void setmapvaluebullet(int x, int y, int nvalue);
	bool createbullet(tank &tank_, unsigned int nid, bullet &bullet_);
	bool bulletcrashall(CPoint &ptbullet);
	bool bulletcrashwall(int &nvalue, CPoint &ptbullet);
};

