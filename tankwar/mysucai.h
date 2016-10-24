#pragma once
#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code)&0x8000)?1:0)//定义按键
//最高位代表不同物体
#define OBJ_TYPE_WALL	0x10000000		//墙
#define OBJ_TYPE_TANK	0x20000000		//坦克
#define OBJ_TYPE_BULLET	0x40000000		//子弹
//第一位表示障碍为墙，第二个为墙的ID,第三个表示墙血值
#define WALL_COB        0x10010001		//土墙、hp=1
#define WALL_STO        0x10020002		//石墙、hp=2
#define WALL_IRO        0x10040003		//铁墙、hp=3
#define WALL_DIA        0x10080000		//不可摧毁的墙
#define WALL_BLOOD		0x0F			//墙的hp
//定义第四位表示墙的类型
#define WALL_ID_COB		0x00010000		//土墙
#define WALL_ID_STO		0x00020000		//石墙
#define WALL_ID_IRO		0x00040000		//铁墙
#define WALL_ID_DIA		0x00080000		//不可摧毁
//定义子弹包含两个属性，第一位代表子弹，第二位代表子弹所属
#define BULLET_MINE		0x40010000		// 玩家子弹 
#define BULLET_ENEMY	0x40020000		// 敌方子弹
#define BULLET_ID_MINE	0x00010000		// 1：我方子弹
#define BULLET_ID_ENEMY	0x00020000		// 2：敌方子弹
// 字体颜色
#define F_BLUE     FOREGROUND_BLUE      // 深蓝
#define F_H_BLUE   0x0001|0x0008        // 亮蓝
#define F_GREEN    0x0002               // 深绿
#define F_H_GREEN  0x0002|0x0008        // 亮绿
#define F_RED      0x0004               // 深红
#define F_H_RED    0x0004|0x0008        // 亮红
#define F_YELLOW   0x0002|0x0004        // 深黄
#define F_H_YELLOW 0x0002|0x0004|0x0008 // 亮黄
#define F_PURPLE   0x0001|0x0004        // 深紫
#define F_H_PURPLE 0x0001|0x0004|0x0008 // 亮紫
#define F_CYAN     0x0002|0x0004        // 深青
#define F_H_CYAN   0x0002|0x0004|0x0008 // 亮青
#define F_WHITE    0x0004|0x0002|0x0001
#define F_H_WHITE  0x0004|0x0002|0x0001|0x0008
#define F_TEST     0x0007|0x000b|0x0003
// 背景颜色
#define B_BLUE     BACKGROUND_BLUE      // 深蓝
#define B_H_BLUE   0x0010|0x0080        // 亮蓝
#define B_GREEN    0x0020               // 深绿
#define B_H_GREEN  0x0020|0x0080        // 亮绿
#define B_RED      0x0040               // 深红
#define B_H_RED    0x0040|0x0080        // 亮红
#define B_YELLOW   0x0020|0x0040        // 深黄
#define B_H_YELLOW 0x0020|0x0040|0x0080 // 亮黄
#define B_PURPLE   0x0010|0x0040        // 深紫
#define B_H_PURPLE 0x0010|0x0040|0x0080 // 亮紫
#define B_CYAN     0x0020|0x0040        // 深青
#define B_H_CYAN   0x0020|0x0040|0x0080 // 亮青
#define B_WHITE    0x0010|0x0020|0x0040
#define B_H_WHITE  0x0002|0x0002
//方向
#define  UP			0
#define  DOWN		1
#define  LEFT		2
#define  RIGHT		3



