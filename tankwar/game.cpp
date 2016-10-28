#include "mysucai.h"
#include "game.h"
#include<conio.h>
#include<time.h>
game::game()
{
}
game::~game()
{
}
void game::rungame()
{
	//设置窗口大小和标题
	m_draw.setwindowssize("Tank War v0.1", 100, 39);
	//画边框
	m_draw.drawmapborder();
	//画计分板1
	m_draw.drawscoringboard(1);
	drawandselectmenu();
}
void game::drawandselectmenu()
{
	//画开始菜单
	m_draw.drawstartmenu();
	m_draw.drawscoringboard(1);
	char ch;
	getstartmenuselect(ch);
}
void game::initplayer1()
{
	tank::stank stank{ 0, 13, 37, 2, TANK_ID_MINE1 };
	m_tank1.inittankinfo(stank);
	m_draw.drawtank(0, 13, 37, "①", tank_pic[1], F_YELLOW);
}
void game::initplayer2()
{
	tank::stank stank2{ 0, 27, 37, 2, TANK_ID_MINE2 };
	m_tank2.inittankinfo(stank2);
	m_draw.drawtank(0, 27, 37, "①", tank_pic[1], F_YELLOW);
}
void game::initenemytank(int nInit)
{
	tank::stank enemy[] = {
		1, 2, 2, 2, TANK_ID_ENEMY3,
		1, 20, 2, 2, TANK_ID_ENEMY4,
		1, 36, 2, 2, TANK_ID_ENEMY5
	};
	tank temp;
	if (nInit == 4)
	{
		for (int i = 0; i < 3; i++)
		{
			temp.inittankinfo(enemy[i]);
			m_vecEnemy.push_back(temp);
			m_draw.drawtank(
				enemy[i].ndirection,
				enemy[i].nx,
				enemy[i].ny,
				"③",
				tank_pic[4],
				F_RED);
		}
		return;
	}
	temp.inittankinfo(enemy[nInit]);
	m_vecEnemy[nInit] = temp;
	m_targets--;
	m_draw.drawscoringboard(2);
	
}
void game::initsingleplayergame()
{
	m_targets = 5;
	player1life = 5;
	m_draw.drawscoringboard(2);
	initplayer1();
	initenemytank();
}
void game::initdoubleplayergame()
{
	m_targets = 5;
	player1life = 5;
	player2life = 5;
	m_draw.drawscoringboard(3);
	initplayer1();
	initplayer2();
	initenemytank();
}
bool game::singleplayerloop()
{
	issingle = true;
	m_draw.drawscoringboard(2);
	DWORD dwplayerbegin = GetTickCount(), dwbullebegin = GetTickCount(), dwplayerend, dwbulletend;
	while (true)
	{
		if (m_targets ==0)
		{
			char ch;
 			m_draw.drawwinmenu();
			getwinmenuselect(ch);
			
		}
		if (player1life==0)
		{
			char ch;
			m_draw.drawlostmenu();
			getlostmenuselect(ch);
		}
		dwplayerend = GetTickCount();
		if (dwplayerend - dwplayerbegin > 100)
		{
			dwplayerbegin = dwplayerend;
			runtime(m_tank1,singlegame[0]);
			for (UINT i = 0; i < m_vecEnemy.size(); i++)
			{
				enemytime(m_vecEnemy[i],singlegame[i+2]);
			}
		}
		dwbulletend = GetTickCount();
		if (dwbulletend-dwbullebegin>50)
		{
			dwbullebegin = dwbulletend;
			bullettime();
		
		}
	}
	return false;
}
bool game::doubleplayerloop()
{
	m_draw.drawscoringboard(3);
	issingle =false;
	DWORD dwplayerbegin = GetTickCount(), dwbulletbegin = GetTickCount(),
		dwplayerend, dwbulletend;
	while (true)
	{
		if (m_targets == 0)
		{
			char ch;
			m_draw.drawwinmenu();
			getwinmenuselect(ch);
		}
		if (player1life == 0 && player2life == 0)
		{
			char ch;
			m_draw.drawstopmenu();
			getlostmenuselect(ch);
		}
		dwplayerend = GetTickCount();
		if (dwplayerend - dwplayerbegin > 100)
		 {
			dwplayerbegin = dwplayerend;
			if (player1life!=0)
			{
				runtime(m_tank1, doublegame[0]);
			}
			if (player2life!=0)
			{
				runtime(m_tank2, doublegame[1]);
			}
			for (size_t i = 0; i < m_vecEnemy.size(); i++)
			{
				enemytime(m_vecEnemy[i], doublegame[i + 2]);
			}
		}
		dwbulletend = GetTickCount();
		if (dwbulletend - dwbulletbegin > 50)
		{
			dwbulletbegin = dwbulletend;
			bullettime();
			
		}
	}
	return false;
}
bool game::runtime(tank &tank_,int who)
{
	char ch;
	m_draw.cleartank(tank_.m_obj.ndirection, tank_.m_obj.nx, tank_.m_obj.ny);
	setmapvaluetank(tank_.m_obj.nx, tank_.m_obj.ny, 0);
	getinput(ch,who);
	m_draw.drawtank(tank_.m_obj.ndirection, tank_.m_obj.nx, tank_.m_obj.ny, "①", tank_pic[1], F_YELLOW);
	setmapvaluetank(tank_.m_obj.nx, tank_.m_obj.ny, tank_.m_obj.nid);
	return true;
}

char game::getdirfromrand(int rand)
{
	switch (rand)
	{
	case 1:
		return '1';
		break;
	case 2:
		return '2';
		break;
	case 3:
		return '3';
		break;
	case 4:
		return '4';
		break;
	default:
		break;
	} 
	return '5';
}

bool game::enemytime(tank & enemytank,int who)
{
	char ch;
	int random = rand() % 5 + 1;
	ch = getdirfromrand(random);
	m_draw.cleartank(enemytank.m_obj.ndirection, enemytank.m_obj.nx, enemytank.m_obj.ny);
	setmapvaluetank(enemytank.m_obj.nx, enemytank.m_obj.ny, 0);
	getinput(ch, who);
	m_draw.drawtank(enemytank.m_obj.ndirection, enemytank.m_obj.nx, enemytank.m_obj.ny, "③", tank_pic[3], F_RED);
	setmapvaluetank(enemytank.m_obj.nx, enemytank.m_obj.ny, enemytank.m_obj.nid);
	return true;
}

//获取来自who变量的输入
bool game::getinput(_Out_ char &ch, _In_ int who)
{

	if (who == play1)
	{
		if (player1life == 0)
		{
			return false;
		}
		if (KEYDOWN('w') || KEYDOWN('W'))
		{
			if (tankmovecrash(UP, m_tank1))
			{
				m_tank1.tankmove(UP);
			}
		}
		if (KEYDOWN('S') || KEYDOWN('s'))
		{
			if (tankmovecrash(DOWN, m_tank1))
			{
				m_tank1.tankmove(DOWN);
			}
		}
		if (KEYDOWN('A') || KEYDOWN('a'))
		{
			if (tankmovecrash(LEFT, m_tank1))
			{
				m_tank1.tankmove(LEFT);
			}
		}
		if (KEYDOWN('D') || KEYDOWN('d'))
		{
			if (tankmovecrash(RIGHT, m_tank1))
			{
				m_tank1.tankmove(RIGHT);
			}
		}
		if (KEYDOWN(VK_SPACE))
		{
			bullet bullet_1;
			if (createbullet(m_tank1, BULLET_ID_MINE1, bullet_1))
			{
				m_vecbullet.push_back(bullet_1);
				m_draw.drawbullet(bullet_1.m_obj.nx, bullet_1.m_obj.ny, bullet_pic[1]);
				setmapvaluebullet(bullet_1.m_obj.nx, bullet_1.m_obj.ny, BULLET_ID_MINE1);
			}
		}
		if (KEYDOWN(VK_ESCAPE))
		{
			char ch;
			m_draw.drawstopmenu();
			getstopmenuselect(ch);
			singleplayerloop();
		}
		return true;
	}
	if (who == play2)
	{
		if (player2life == 0)
		{
			return false;
		}
		if (KEYDOWN('i') || (KEYDOWN('I')))
		{
			if (tankmovecrash(UP, m_tank2))
			{
				m_tank2.tankmove(UP);
			}
		}
		if (KEYDOWN('K') || KEYDOWN('k'))
		{
			if (tankmovecrash(DOWN, m_tank2))
			{
				m_tank2.tankmove(DOWN);
			}
		}
		if (KEYDOWN('j') || KEYDOWN('J'))
		{
			if (tankmovecrash(LEFT, m_tank2))
			{
				m_tank2.tankmove(LEFT);
			}
		}
		if (KEYDOWN('L') || KEYDOWN('l'))
		{
			if (tankmovecrash(RIGHT, m_tank2))
			{
				m_tank2.tankmove(RIGHT);
			}
		}
		if (KEYDOWN(VK_ESCAPE))
		{
			//drawandselectmenu();
		}
		if (KEYDOWN('o') || KEYDOWN('O'))
		{
			bullet bullet_2;
			if (createbullet(m_tank2, BULLET_ID_MINE2, bullet_2))
			{
				m_vecbullet.push_back(bullet_2);
				m_draw.drawbullet(bullet_2.m_obj.nx, bullet_2.m_obj.ny, bullet_pic[1]);
				setmapvaluebullet(bullet_2.m_obj.nx, bullet_2.m_obj.ny, BULLET_ID_MINE2);
			}
		}
	}
	if (who == enemy3)
	{
		if (ch == '1')
		{
			if (tankmovecrash(UP, m_vecEnemy[0]))
			{
				m_vecEnemy[0].tankmove(UP);
			}
		}
		if (ch == '2')
		{
			if (tankmovecrash(DOWN, m_vecEnemy[0]))
			{
				m_vecEnemy[0].tankmove(DOWN);
			}
		}
		if (ch == '3')
		{
			if (tankmovecrash(LEFT, m_vecEnemy[0]))
			{
				m_vecEnemy[0].tankmove(LEFT);
			}
		}
		if (ch == '4')
		{
			if (tankmovecrash(RIGHT, m_vecEnemy[0]))
			{
				m_vecEnemy[0].tankmove(RIGHT);
			}
		}
		if (ch == '5')
		{
			bullet bullet_3;
			if (createbullet(m_vecEnemy[0], BULLET_ID_ENEMY3, bullet_3))
			{
				m_vecbullet.push_back(bullet_3);
				m_draw.drawbullet(bullet_3.m_obj.nx, bullet_3.m_obj.ny, bullet_pic[1]);
				setmapvaluebullet(bullet_3.m_obj.nx, bullet_3.m_obj.ny, BULLET_ID_ENEMY3);
			}
		}
	}
	if (who == enemy4)
	{
		if (ch == '1')
		{
			if (tankmovecrash(UP, m_vecEnemy[1]))
			{
				m_vecEnemy[1].tankmove(UP);
			}
		}
		if (ch == '2')
		{
			if (tankmovecrash(DOWN, m_vecEnemy[1]))
			{
				m_vecEnemy[1].tankmove(DOWN);
			}
		}
		if (ch == '3')
		{
			if (tankmovecrash(LEFT, m_vecEnemy[1]))
			{
				m_vecEnemy[1].tankmove(LEFT);
			}
		}
		if (ch == '4')
		{
			if (tankmovecrash(RIGHT, m_vecEnemy[1]))
			{
				m_vecEnemy[1].tankmove(RIGHT);
			}
		}
		if (ch == '5')
		{
			bullet bullet_4;
			if (createbullet(m_vecEnemy[1], BULLET_ID_ENEMY4, bullet_4))
			{
				m_vecbullet.push_back(bullet_4);
				m_draw.drawbullet(bullet_4.m_obj.nx, bullet_4.m_obj.ny, bullet_pic[1]);
				setmapvaluebullet(bullet_4.m_obj.nx, bullet_4.m_obj.ny, BULLET_ID_ENEMY4);
			}
		}
	}
	if (who == enemy5)
	{
		if (ch == '1')
		{
			if (tankmovecrash(UP, m_vecEnemy[2]))
			{
				m_vecEnemy[2].tankmove(UP);
			}
		}
		if (ch == '2')
		{
			if (tankmovecrash(DOWN, m_vecEnemy[2]))
			{
				m_vecEnemy[2].tankmove(DOWN);
			}
		}
		if (ch == '3')
		{
			if (tankmovecrash(LEFT, m_vecEnemy[2]))
			{
				m_vecEnemy[2].tankmove(LEFT);
			}
		}
		if (ch == '4')
		{
			if (tankmovecrash(RIGHT, m_vecEnemy[2]))
			{
				m_vecEnemy[2].tankmove(RIGHT);
			}
		}
		if (ch == '5')
		{
			bullet bullet_5;
			if (createbullet(m_vecEnemy[2], BULLET_ID_ENEMY5, bullet_5))
			{
				m_vecbullet.push_back(bullet_5);
				m_draw.drawbullet(bullet_5.m_obj.nx, bullet_5.m_obj.ny, bullet_pic[1]);
				setmapvaluebullet(bullet_5.m_obj.nx, bullet_5.m_obj.ny, BULLET_ID_ENEMY5);
			}
		}
	}
	return true;
}
//获取开始菜单的输入信息
bool game::getstartmenuselect(_Out_ char &)
{
	while (true)
	{
		//m_vecEnemy.swap(vector<tank>());
		if (KEYDOWN('1'))
		{
			PlaySound(TEXT("res\\start.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
			issingle = true;
			system("cls");
			m_draw.drawmap();
			initsingleplayergame();
			singleplayerloop();
			return true;
		}
		if (KEYDOWN('2'))
		{
			PlaySound(TEXT("res\\start.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
			issingle = false;
			m_draw.drawmap();
			initdoubleplayergame();
			doubleplayerloop();
		}
		if (KEYDOWN('3'))
		{
			PlaySound(TEXT("res\\输.mp3"), NULL, SND_ASYNC | SND_NODEFAULT);

		}
		if (KEYDOWN('4'))
		{
			exit(0);
		}
	}
	return true;
}
//获取来自win菜单的输入
bool game::getwinmenuselect(_Out_ char &ch)
{
	while (true)
	{
		if (KEYDOWN('1'))
		{
			if (issingle == 1)
			{
				//难度提升，需要杀敌数量开始上升
				m_targets = (m_target++) * 2;
				//清除屏幕上的各种信息
				system("cls");
				m_draw.cleartank(m_tank1.m_obj.ndirection, m_tank1.m_obj.nx, m_tank1.m_obj.ny);
				setmapvaluetank(m_tank1.m_obj.nx, m_tank1.m_obj.ny, 0);
				//清除两个容器
				m_vecbullet.clear();
				m_vecEnemy.clear();
				//画地图
				m_draw.drawmap();
				//画计分板
				m_draw.drawscoringboard(2);
				//初始化坦克
				initplayer1();
				initenemytank(4);
				//进入循环
				singleplayerloop();
			}
			else
			{
				//难度提升，需要杀敌数量开始上升
				m_targets = (m_target++) * 3;
				//清除屏幕上的各种信息
				system("cls");
				m_draw.cleartank(m_tank1.m_obj.ndirection, m_tank1.m_obj.nx, m_tank1.m_obj.ny);
				setmapvaluetank(m_tank1.m_obj.nx, m_tank1.m_obj.ny, 0);
				m_draw.cleartank(m_tank2.m_obj.ndirection, m_tank2.m_obj.nx, m_tank2.m_obj.ny);
				setmapvaluetank(m_tank2.m_obj.nx, m_tank2.m_obj.ny, 0);
				//清除两个容器
				m_vecbullet.clear();
				m_vecEnemy.clear();
				//画地图
				m_draw.drawmap();
				//画积分
				m_draw.drawscoringboard(3);
				//初始化
				initplayer1();
				initplayer2();
				initenemytank(4);
				//进入循环
				doubleplayerloop();
			}
		}
		else if (KEYDOWN('0'))
		{
			exit(0);

		}

	}
	return true;
}
//获取来自暂停菜单的输入
bool game::getstopmenuselect(_Out_ char &ch)
{
	while (true)
	{
		if (KEYDOWN('1'))
		{
			if (issingle == 1)
			{
				system("cls");
				m_draw.drawmap();
				singleplayerloop();
			}
			else
			{
				system("cls");
				m_draw.drawmap();
				doubleplayerloop();
			}
		}
		else if (KEYDOWN('0'))
		{
			exit(0);

		}

	}
	return true;
	
}
//获取来自lost菜单的输入
bool game::getlostmenuselect(_Out_ char &ch)
{
	while (true)
	{
		if (KEYDOWN('1'))
		{
			if (issingle == 1)
			{

				//给玩家的生命值重新赋值
				player1life = 5;
				//清除屏幕上的各种信息
				m_draw.cleartank(m_tank1.m_obj.ndirection, m_tank1.m_obj.nx, m_tank1.m_obj.ny);
				setmapvaluetank(m_tank1.m_obj.nx, m_tank1.m_obj.ny, 0);
				//清除两个容器
				m_vecbullet.clear();
				m_vecEnemy.clear();
				system("cls");
				//画地图
				m_draw.drawmap();
				//画计分板
				m_draw.drawscoringboard(2);
				//初始化坦克
				initplayer1();
				initenemytank(4);
				//进入循环
				singleplayerloop();
			}
			else
			{
				//给玩家1的生命值重新赋值
				player1life = 5;
				player2life = 5;
				system("cls");
				m_draw.cleartank(m_tank1.m_obj.ndirection, m_tank1.m_obj.nx, m_tank1.m_obj.ny);
				setmapvaluetank(m_tank1.m_obj.nx, m_tank1.m_obj.ny, 0);
				m_draw.cleartank(m_tank2.m_obj.ndirection, m_tank2.m_obj.nx, m_tank2.m_obj.ny);
				setmapvaluetank(m_tank2.m_obj.nx, m_tank2.m_obj.ny, 0);
				//清除两个容器
				m_vecbullet.clear();
				m_vecEnemy.clear();
		
				//画地图
				m_draw.drawmap();
				//画积分
				m_draw.drawscoringboard(3);
				//初始化
				initplayer1();
				initplayer2();
				initenemytank();
				//进入循环
				doubleplayerloop();
			}
		}
		else if (KEYDOWN('0'))
		{
			exit(0);
		}
	}
	return false;
}
bool game::bullettime()
{
	for (UINT i = 0; i < m_vecbullet.size(); i++)
	{
		bullet &bullet_ = m_vecbullet[i];
		m_draw.clearbullet(bullet_.m_obj.nx, bullet_.m_obj.ny);
		setmapvaluebullet(bullet_.m_obj.nx, bullet_.m_obj.ny, 0);
		CPoint ptforward;		
		bullet_.getforwardpoint(ptforward);
		if (bulletcrashall(ptforward, bullet_))
		{
			m_vecbullet.erase(m_vecbullet.begin() + i);
			i--;
		}
		else
		{
			bullet_.bulletmove();
			m_draw.drawbullet(bullet_.m_obj.nx, bullet_.m_obj.ny, bullet_pic[1]);
			setmapvaluebullet(bullet_.m_obj.nx, bullet_.m_obj.ny, bullet_.m_obj.nid | OBJ_TYPE_BULLET);
		}
	}
	return false;
}
bool game::tankmovecrash(DWORD dwdir,tank &tank_)
{
	CPoint pt[3] = {};
	if (dwdir != tank_.m_obj.ndirection)
	{
		return true;
	}
	else
	{
		tank_.getthreepoint(pt);
	}
	for (int i= 0; i < 3;i++)
	{
		if (m_draw.m_gnmap[pt[i].y][pt[i].x])
		{
			return false;
		}
	}
	return true;
}
void game::setmapvaluetank(int x, int y, int nvalue)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			m_draw.m_gnmap[y - 1 + i][x - 1 + j] = nvalue;
		}
	}
}
void game::setmapvaluebullet(int x, int y, int nvalue)
{
	m_draw.m_gnmap[y][x] = nvalue;
}

bool game::createbullet(tank &tank_, unsigned int nid, bullet &bullet_)
{
	static int cT = GetTickCount(), ct1;
	ct1 = GetTickCount();
	if (ct1 - cT < 200)
	{
		return false;
	}
	cT = ct1;
	CPoint pt[3] = {};
	tank_.getthreepoint(pt);
	bullet_ = { tank_.m_obj.ndirection, (unsigned int)pt[0].x, (unsigned int)pt[0].y, nid };
	if (!bulletcrashall(pt[0],bullet_))
	{
		PlaySound(TEXT("res\\Fire.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
		return true;
	}
	return false;
}

bool game::bulletcrashall(CPoint &ptbullet,bullet &bullet_id)
{
	int &nvalue = m_draw.m_gnmap[ptbullet.y][ptbullet.x];
	if (!nvalue || (nvalue & OBJ_TYPE_BULLET))
	{
		return false;
	}
	if (nvalue&OBJ_TYPE_WALL)
	{
		bulletcrashwall(nvalue, ptbullet);
	}
	else if (nvalue&OBJ_TYPE_TANK)
	{
		bulletcrashtank(nvalue,ptbullet,bullet_id);
	}
	return true;
}
bool game::bulletcrashtank(int &nvalue, CPoint &ptbullet,bullet &bullet_id)
{   
	if (nvalue&TANK_ENEMY)
	{
		if (bullet_id.m_obj.nid == BULLET_ID_MINE1 || bullet_id.m_obj.nid == BULLET_ID_MINE2)
		{
			int nId = nvalue & 0x0F00;
			nId >>= 8; 
			nId -= 3;

			if (m_vecEnemy[nId].m_obj.nblood != 0)
			{
				m_vecEnemy[nId].m_obj.nblood--;
				return true;
			}
			else
			{	
				PlaySound(TEXT("res\\explode.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
				m_draw.cleartank(m_vecEnemy[nId].m_obj.ndirection, m_vecEnemy[nId].m_obj.nx, m_vecEnemy[nId].m_obj.ny);
				setmapvaluetank(m_vecEnemy[nId].m_obj.nx, m_vecEnemy[nId].m_obj.ny, 0);
				initenemytank(nId);
				if ((bullet_id.m_obj.nid == BULLET_ID_MINE1))
				{
					player1_score++;
					if (issingle==true)
					{
						m_draw.drawscoringboard(2);
					}
					else
					{
						m_draw.drawscoringboard(3);
					}
					
				}
				if ((bullet_id.m_obj.nid == BULLET_ID_MINE2))
				{
					player2_score++;
					m_draw.drawscoringboard(3);
				}
				return true;
			}
		}
		else
		{
			return true;
		}
	}
	else if (nvalue&TANK_MINE)
	{
		if (bullet_id.m_obj.nid==BULLET_ID_ENEMY3||bullet_id.m_obj.nid==BULLET_ID_ENEMY4||bullet_id.m_obj.nid==BULLET_ID_ENEMY5)
		{
			int nId = nvalue & 0x0F00;// 100 
			nId >>= 8; // 15 16
			
			if (nvalue==TANK_ID_MINE1)
			{
				if (m_tank1.m_obj.nblood!=0)
				{
					m_tank1.m_obj.nblood--;
					return true;
				}
				else
				{
					PlaySound(TEXT("res\\explode.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
					m_draw.cleartank(m_tank1.m_obj.ndirection, m_tank1.m_obj.nx, m_tank1.m_obj.ny);
					setmapvaluetank(m_tank1.m_obj.nx, m_tank1.m_obj.ny, 0);
					initplayer1();
					player1life--;
					if (issingle==true)
					{
						m_draw.drawscoringboard(2);
					}
					if (issingle==false)
					{
						m_draw.drawscoringboard(3);
					}
					
					return true;
				}
			}
			if (nvalue==TANK_ID_MINE2)
			{
				if (m_tank2.m_obj.nblood != 0)
				{
					m_tank2.m_obj.nblood--;
					return true;
				}
				else
				{
					PlaySound(TEXT("res\\explode.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
					m_draw.cleartank(m_tank2.m_obj.ndirection, m_tank2.m_obj.nx, m_tank2.m_obj.ny);
					setmapvaluetank(m_tank2.m_obj.nx, m_tank2.m_obj.ny, 0);
					initplayer2();
					m_draw.drawscoringboard(3);
					return true;
				}
			}
		}
		else
		{
			return true;
		}
	}
	return true;
}
bool game::bulletcrashwall(int &nvalue, CPoint &ptbullet)
{
	if (nvalue&WALL_ID_DIA)
	{
		return true;
	}
	else
	{
		nvalue--;
		if ((nvalue&WALL_BLOOD)==0)
		{
			nvalue = 0;
			m_draw.drawblank(ptbullet.x, ptbullet.y);
		}
	}
	return true;
}

