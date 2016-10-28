#include "mysucai.h"
char* wall_pic[] = { "  ", "¨ˆ", "…d", "¡þ", "¡Ö", "¡Ô", "¡î", "¡ì" };
char* tank_pic[] = { "  ", "¡ö", "¡õ", "¡ó", "¨ˆ", "¡ð" };
char* bullet_pic[] = { "  ", "¡ð", "¡ñ", "¡è", "¡ó", "¡ò", "¡ü", "¡ý", "¡û", "¡ú"};//Ì¹¿ËÐÎ×´
int singlegame[] = { play1, 0, enemy3, enemy4, enemy5 };
int doublegame[] = { play1, play2, enemy3, enemy4, enemy5 };
int m_targets;
int m_target=5;
int m_boardtype;
int player1_score=0;
int player2_score=0;
int player1life;
int player2life;
