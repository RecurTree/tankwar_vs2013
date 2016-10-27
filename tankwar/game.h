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
	tank m_tank1;
	tank m_tank2;
	tank m_enemytank3;
	tank m_enemytank4;
	tank m_enemytank5;
	vector<tank> m_vecEnemy;
	vector<bullet> m_vecbullet1;
	vector<bullet> m_vecbullet2;
	vector<bullet> m_vecbullet3;
	vector<bullet> m_vecbullet4;
	vector<bullet> m_vecbullet5;
	game();
	~game();
	bool isplayer1 = true;
	bool issingle = true;
	void rungame();
protected:
	void progameshow();
	void drawandselectmenu();
	void initplayer1();
	void initplayer2();
	void initenemytank3();
	void initenemytank4();
	void initenemytank5();
	void initenemytank();
	void initsingleplayergame();
	void initdoubleplayergame();
	bool singleplayerloop();
	bool doubleplayerloop();
	bool player1time();
	bool player2time();
	char getdirfromrand(int rand);
	bool enemytime(tank &);
	bool enemy3time();
	bool enemy4time();
	bool enemy5time();
	bool getinput(_Out_ char &ch,_In_ int leixing,_In_ int who);
	bool bullet1time();
	bool bullet2time();
	bool bullet3time();
	bool bullet4time();
	bool bullet5time();
	bool tankmovecrash(DWORD dwdir,tank &tank_);
	void setmapvaluetank(int x, int y, int nvalue);
	void setmapvaluebullet(int x, int y, int nvalue);
	bool createbullet(tank &tank_, unsigned int nid, bullet &bullet_);
	bool bulletcrashall(CPoint &ptbullet, bullet &bullet_id);
	bool bulletcrashtank(int &nvalue, CPoint &ptbullet, bullet &bullet_id);
	bool bulletcrashwall(int &nvalue, CPoint &ptbullet);
};

