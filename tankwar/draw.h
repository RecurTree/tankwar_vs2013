#pragma once
#include <windows.h>
#include <iostream>
using namespace std;
class draw
{
public:
	static int m_gnmap[40][40];
	static int m_gntankshape[4][3][3];
	draw();
	virtual ~draw();
	bool setwindowssize(char *pszwindowtitle,short nx,short ny);
	void drawmap();
	void drawmenu();
	void drawscoringboard(int );
	void drawwin();
	void drawlost();
	void drawmapborder();
	void drawtank(int ndir,int nx,int ny,char *center,char *frame);
	void drawtank(int ndir, int nx, int ny, char *center, char *frame,WORD color);
	void cleartank(int ndir,int nx,int ny);
	void drawbullet(int nx,int ny,char *center);
	void clearbullet(int nx,int ny);
	void drawblank(int nx,int ny);
protected:

	template <typename T>
	void writechar(int wide,int high,T pszchar,WORD warr);
};

