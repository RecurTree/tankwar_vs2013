#pragma once
#include "bullet.h"
#include "draw.h"
#include "tank.h"
#include <mmsystem.h>//WINDOWS的基本WAV文件播放
#pragma comment(lib,"WinMM.Lib")
#include<vector>
using std::vector;

class game
{
public:

	draw m_draw;
	tank m_tank1;
	tank m_tank2;
	vector<tank> m_vecEnemy;
	vector<bullet> m_vecbullet;
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
	void initenemytank(int nInit = 4);
	void initsingleplayergame();
	void initdoubleplayergame();
	bool singleplayerloop();
	bool doubleplayerloop();
	bool runtime(tank &,int who);
	bool player1time();
	bool player2time();
	char getdirfromrand(int rand);
	bool enemytime(tank &,int );
	bool getinput(_Out_ char &ch, _In_ int who);
	bool getstartmenuselect(_Out_ char &ch);
	bool getstopmenuselect(_Out_ char &ch);
	bool getlostmenuselect(_Out_ char &ch);
	bool getwinmenuselect(_Out_ char &ch);
	bool bullettime();
	bool tankmovecrash(DWORD dwdir,tank &tank_);
	void setmapvaluetank(int x, int y, int nvalue);
	void setmapvaluebullet(int x, int y, int nvalue);
	bool createbullet(tank &tank_, unsigned int nid, bullet &bullet_);
	bool bulletcrashall(CPoint &ptbullet, bullet &bullet_id);
	bool bulletcrashtank(int &nvalue, CPoint &ptbullet, bullet &bullet_id);
	bool bulletcrashwall(int &nvalue, CPoint &ptbullet);
};

