#pragma once
#include<windows.h>
#include<atltypes.h>
class bullet
{
public:
	bullet(unsigned int dwdir=0,unsigned int dwx=0,unsigned int dwy=0,unsigned int dwid=0);
	~bullet();
	typedef struct _sbullet
	{
		unsigned int ndirection;
		unsigned int nx;
		unsigned int ny;
		unsigned int nblood;
		unsigned int nid;
	}sbullet,*pbullet;
	void getforwardpoint(_Out_ CPoint & ptforward);
	bool bulletmove();
	sbullet m_obj;
};

