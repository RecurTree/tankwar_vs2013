#pragma once
#include<windows.h>
#include<atltypes.h>
class tank
{
public:
	typedef struct _stank
	{
		unsigned int ndirection;
		unsigned int nx;
		unsigned int ny;
		unsigned int nblood;
		unsigned int nid;
	}stank, *ptank;
	tank();
	~tank();
	void inittankinfo(stank &stank);
	void tankmove(DWORD dwdir);
	CPoint getcenter();
	void getthreepoint(CPoint *ptthree);
	stank m_obj;
};

