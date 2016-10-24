#include "mysucai.h"
#include "draw.h"

draw::draw()
{
}
draw::~draw()
{
}
//坦克形状
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
	WALL_DIA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_IRO, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_COB, WALL_COB, WALL_COB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_COB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_COB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_COB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, WALL_STO, WALL_STO, WALL_STO, WALL_STO, WALL_STO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_COB, 0, 0, 0, WALL_COB, 0, 0, 0, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, 0, 0, WALL_STO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_COB, 0, 0, 0, WALL_COB, 0, 0, 0, 0, 0, WALL_DIA, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, 0, 0, WALL_STO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_COB, 0, 0, 0, WALL_COB, 0, 0, 0, 0, 0, WALL_DIA, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, 0, 0, WALL_STO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_COB, 0, 0, 0, WALL_COB, 0, 0, 0, 0, 0, WALL_DIA, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, WALL_STO, WALL_STO, WALL_STO, WALL_STO, WALL_STO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_COB, 0, 0, 0, WALL_COB, 0, 0, 0, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, 0, 0, WALL_STO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_COB, WALL_COB, WALL_DIA, 0, 0, 0, WALL_DIA, WALL_COB, WALL_COB, 0, 0, 0, WALL_DIA, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, 0, 0, WALL_STO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, 0, 0, WALL_STO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, 0, 0, WALL_STO, WALL_STO, WALL_STO, WALL_STO, WALL_STO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, WALL_DIA, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, WALL_IRO, 0, 0, WALL_IRO, WALL_IRO, WALL_IRO, 0, WALL_IRO, WALL_IRO, 0, 0, WALL_IRO, WALL_IRO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, WALL_IRO, WALL_IRO, 0, 0, WALL_IRO, 0, 0, 0, WALL_IRO, 0, WALL_IRO, 0, WALL_IRO, 0, WALL_IRO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, WALL_IRO, 0, 0, WALL_IRO, 0, 0, 0, WALL_IRO, 0, WALL_IRO, 0, WALL_IRO, 0, WALL_IRO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, WALL_IRO, 0, 0, WALL_IRO, WALL_IRO, 0, 0, WALL_IRO, 0, WALL_IRO, 0, WALL_IRO, 0, WALL_IRO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, WALL_IRO, 0, 0, 0, 0, WALL_IRO, 0, WALL_IRO, WALL_IRO, 0, 0, WALL_IRO, WALL_IRO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, WALL_IRO, 0, 0, 0, 0, WALL_IRO, 0, WALL_IRO, 0, 0, 0, WALL_IRO, 0, WALL_IRO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, WALL_IRO, 0, 0, 0, 0, WALL_IRO, 0, WALL_IRO, 0, 0, 0, WALL_IRO, 0, WALL_IRO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, WALL_IRO, 0, 0, 0, 0, WALL_IRO, 0, WALL_IRO, 0, 0, 0, WALL_IRO, 0, WALL_IRO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, 0, WALL_IRO, 0, 0, WALL_IRO, 0, WALL_IRO, 0, WALL_IRO, 0, 0, 0, WALL_IRO, 0, WALL_IRO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, \
	WALL_DIA, 0, WALL_IRO, WALL_IRO, WALL_IRO, 0, 0, WALL_IRO, 0, 0, WALL_IRO, 0, 0, 0, WALL_IRO, WALL_IRO, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, WALL_DIA, \
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

	if (!SetConsoleScreenBufferSize(hstdOut,buffersize))
	{
		printf("buffer err(%d,%d)%d\n", buffersize.X, buffersize.Y, GetLastError());
		return false;
	}
	SMALL_RECT srcWindow = { 0, 0, nx, ny };
	if (!SetConsoleWindowInfo(hstdOut, true,&srcWindow))
	{
		printf("size err%d\n", GetLastError());
		return false;
	}
	COORD buffer = { nx + 1, ny + 1 };
	if (!SetConsoleScreenBufferSize(hstdOut,buffer))
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
				writechar(j, i, "〓", F_H_CYAN);
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
				writechar(j, i, "※", F_H_PURPLE);
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