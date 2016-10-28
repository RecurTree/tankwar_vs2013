#include "mysucai.h"
#include "draw.h"
#include "game.h"
draw::draw()
{
	memcpy_s(m_gnmapCpy, sizeof(int) * 40 * 40, m_gnmap, sizeof(int) * 40 * 40);
}
draw::~draw()
{
}
int draw::m_gntankshape[4][3][3] =
{
	{
		0, 1, 0,
		1, 2, 1,
		1, 0, 1
	},
	{
		1, 0, 1,
		1, 2, 1,
		0, 1, 0
	},
	{
		0, 1, 1,
		1, 2, 0,
		0, 1, 1
	},
	{
		1, 1, 0,
		0, 2, 1,
		1, 1, 0
	}
};
int draw::m_gnmap[40][40] =
{
	WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_STO, WALL_STO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_STO, WALL_STO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_STO, WALL_STO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_STO, WALL_STO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_STO, WALL_STO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_STO, WALL_STO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_STO, WALL_STO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_STO, WALL_STO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_STO, WALL_STO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_STO, WALL_STO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_STO, WALL_STO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_STO, WALL_STO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_STO, WALL_STO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_STO, WALL_STO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_STO, WALL_STO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_STO, WALL_STO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_STO, WALL_STO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_STO, WALL_STO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_STO, WALL_STO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_STO, WALL_STO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, 0, 0, 0, WALL_DIA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, 0, 99, 0, WALL_DIA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, 0, 0, 0, WALL_DIA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA
};
//设置窗口标题和大小
bool draw::setwindowssize(char *pszwindowtitle, short nx, short ny)
{
	SetConsoleTitleA(pszwindowtitle);
	HANDLE hstdIn, hstdOut;
	hstdIn = GetStdHandle(STD_INPUT_HANDLE);
	hstdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = GetLargestConsoleWindowSize(hstdOut);
	COORD buffersize = { pos.X + 1, pos.Y + 1 };

	if (!SetConsoleScreenBufferSize(hstdOut, buffersize))
	{
		printf("buffer err(%d,%d)%d\n", buffersize.X, buffersize.Y, GetLastError());
		return false;
	}
	SMALL_RECT srcWindow = { 0, 0, nx, ny };
	if (!SetConsoleWindowInfo(hstdOut, true, &srcWindow))
	{
		printf("size err%d\n", GetLastError());
		return false;
	}
	COORD buffer = { nx + 1, ny + 1 };
	if (!SetConsoleScreenBufferSize(hstdOut, buffer))
	{
		printf("buffer err(%d%d)%d\n", buffersize.X, buffersize.Y, GetLastError());
		return false;
	}

	return true;
}
//指定位置打印字符
template<typename T>
void draw::writechar(int wide, int high, T pszchar, WORD warr)
{
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	COORD loc;
	loc.X = wide * 2;
	loc.Y = high;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), warr);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), loc);
	cout << pszchar;
}
//画地图
void draw::drawmap()
{
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			if (0 == m_gnmap[i][j])
			{
				writechar(j, i, "  ", 0x00);
			}
			else if (WALL_DIA == m_gnmap[i][j])
			{
				writechar(j, i, "〓", F_WHITE);
			}
			else if (WALL_COB == m_gnmap[i][j])
			{
				writechar(j, i, "■", F_YELLOW);
			}
			else if (WALL_STO == m_gnmap[i][j])
			{
				writechar(j, i, "■", 0x0F);
			}
			else if (WALL_IRO == m_gnmap[i][j])
			{
				writechar(j, i, "※", F_RED);
			}
			else if (99 == m_gnmap[i][j])
			{
				writechar(j, i, "★", F_RED);
			}
			else
			{
				continue;
			}
		}
	}
}
void draw::drawstartmenu()
{
	drawmapborder();
	writechar(10, 10, "***************************************", F_RED);
	writechar(10, 11, "*                                     *", F_RED);
	writechar(10, 12, "*          **1*.**开*始*游*戏**       *", F_RED);
	writechar(10, 13, "*          **2*.**双*人*游*戏**       *", F_RED);
	writechar(10, 14, "*          **3*.**绘*制*地*图**       *", F_RED);
	writechar(10, 15, "*          **4*.**退*出*游*戏**       *", F_RED);
	writechar(10, 16, "*                                     *", F_RED);
	writechar(10, 17, "***************************************", F_RED);
}
//画出地图边框
void draw::drawmapborder()
{

	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			if (i == 0 || j == 0 || i == 39 || j == 39)
			{
				writechar(j, i, "〓", F_WHITE);
			}
			else
			{
				writechar(j, i, "  ", F_WHITE);
			}
		}
	}
}
//画计分板
void draw::drawscoringboard(int m_boardtype)
{
	for (int i = 0; i < 40; i++)
	{
		for (int j = 40; j < 50; j++)
		{
			if (i == 0 || i == 39 || j == 49)
			{
				writechar(j, i, "〓", F_WHITE);
			}

		}
	}
	if (m_boardtype==1)
	{
		writechar(41, 10, "             ", F_RED);
		writechar(41, 12, "             ", F_RED);
		writechar(41, 13, "             ", F_RED);
		writechar(41, 14, "             ", F_RED);
		writechar(41, 15, "             ", F_RED);
		writechar(41, 10, "  请按照提示  ", F_RED);
		writechar(41, 12, "选择相应的选项", F_RED);
	}
	if (m_boardtype==2)
	{
		writechar(41, 10, "             ", F_RED);
		writechar(41, 12, "             ", F_RED);
		writechar(41, 13, "             ", F_RED);
		writechar(41, 14, "             ", F_RED);
		writechar(41, 15, "             ", F_RED);
		writechar(41, 10, "杀敌目标:", F_RED);
		writechar(46, 10,  m_targets, F_RED);
		writechar(41, 12, "PLAYER1:", F_RED);
		writechar(46, 12, player1_score*500, F_RED);
		writechar(41, 13, "P1 生命", F_RED);
		writechar(46, 13, player1life, F_RED);

	}
	if (m_boardtype == 3)
	{
		writechar(41, 10, "             ", F_RED);
		writechar(41, 12, "             ", F_RED);
		writechar(41, 13, "             ", F_RED);
		writechar(41, 14, "             ", F_RED);
		writechar(41, 15, "             ", F_RED);
		writechar(41, 10, "杀敌目标:", F_RED);
		writechar(46, 10, m_targets, F_RED);
		writechar(41, 12, "PLAYER1:", F_RED);
		writechar(46, 12, player1_score*500, F_RED);
		writechar(41, 13, "P1 生命", F_RED);
		writechar(46, 13, player1life, F_RED);
		writechar(41, 14, "PLAYER2:", F_RED);
		writechar(46, 14, player2_score*500, F_RED);
		writechar(41, 15, "P1 生命", F_RED);
		writechar(46, 15, player2life, F_RED);

	}

}
//画坦克
void draw::drawtank(int ndir, int nx, int ny, char *center, char *frame,WORD color)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (1 == m_gntankshape[ndir][i][j])
			{
				writechar(nx - 1 + j, ny - 1 + i, frame, color);
			}
			else if (2 == m_gntankshape[ndir][i][j])
			{
				writechar(nx - 1 + j, ny - 1 + i, center, F_RED);
			}
		}
	}
}
//清除坦克
void draw::cleartank(int ndir, int nx, int ny)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (m_gntankshape[ndir][i][j])
			{
				writechar(nx - 1 + j, ny - 1 + i,"  ", F_YELLOW);
			}
		}
	}
}
//画子弹
void draw::drawbullet(int nx, int ny,char *center)
{
	writechar(nx, ny, center, F_PURPLE);
}
//清除子弹
void draw::clearbullet(int nx, int ny)
{
	writechar(nx, ny, " ", 0);
}
//清除一个点
void draw::drawblank(int nx, int ny)
{
	writechar(nx, ny, " ", 0);
}
//画游戏获胜
void draw::drawwinmenu()
{
	PlaySound(TEXT("res\\win.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
	drawmapborder();
	writechar(10, 10, "***************************************", F_RED);
   	writechar(10, 11, "*         **  恭喜你获得胜利  **      *", F_RED);
	writechar(10, 12, "*                                     *", F_RED);
	writechar(10, 13, "*          **1*.**继*续*游*戏**       *", F_RED);
	writechar(10, 14, "*                                     *", F_RED);
	writechar(10, 15, "*          **0*.**退*出*游*戏**       *", F_RED);
	writechar(10, 16, "*                                     *", F_RED);
	writechar(10, 17, "***************************************", F_RED);
	drawscoringboard(1);
}
void draw::drawlostmenu()
{
	PlaySound(TEXT("res\\lost.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
	drawmapborder();
	writechar(10, 10, "***************************************", F_RED);
	writechar(10, 11, "*         **  很抱歉，你输了  **       *", F_RED);
	writechar(10, 12, "*                                     *", F_RED);
	writechar(10, 13, "*          **1*.**重*新*游*戏**       *", F_RED);
	writechar(10, 14, "*                                     *", F_RED);
	writechar(10, 15, "*          **0*.**退*出*游*戏**       *", F_RED);
	writechar(10, 16, "*                                     *", F_RED);
	writechar(10, 17, "***************************************", F_RED);
	drawscoringboard(1);
}
void draw::drawstopmenu()
{
	drawmapborder();
	writechar(10, 10, "***************************************", F_RED);
	writechar(10, 11, "*         **    游戏暂停中    **       *", F_RED);
	writechar(10, 12, "*                                     *", F_RED);
	writechar(10, 13, "*          **1*.**继*续*游*戏**       *", F_RED);
	writechar(10, 14, "*                                     *", F_RED);
	writechar(10, 15, "*          **0*.**退*出*游*戏**       *", F_RED);
	writechar(10, 16, "*                                     *", F_RED);
	writechar(10, 17, "***************************************", F_RED);
	drawscoringboard(1);
}

