#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include "Background.h"
#include "CanonTank.h"
using namespace sf;
using namespace std;

class MissileTank {
private:
	int Attack, Defensive; // Attack : 공격력, Defensive : 방어력
	float Missile_HP; // Missile_HP : 미사일탱크 HP
	Texture misTank, cho_missile_1, cho_missile_2, mismissile, missile_sel, bar_gauge_hp, bar_gauge_power;
	// misTank : 미사일탱크, cho_missile_1 : 1번 미사일, cho_missile_2 : 2번 미사일, canmissile : 선택한 미사일
	// missile_sel : 선택 바, bar_gauge_hp : HP바, bar_gauge_power : 파워바
	Time time;
	Clock clock;
	float velocity; // 속력
public:
	Sprite mTank, cho_m_1, cho_m_2, missile, selector, hp, power; // Texture 객체에 대응되는 각각의 Sprite 객체
	void init(); // 초기 상태
	void change_Selector_Q(); // 선택 바 위치 미사일(1번) 아래로
	void change_Selector_W(); // 선택 바 위치 유도미사일(2번) 아래로
	void change_hpbar(); // HP바 크기 바꾸기
	void moveLeft(); // 미사일탱크 왼쪽으로 움직이기
	void moveRight(); // 미사일탱크 오른쪽으로 움직이기
	float getx(int angle); // 파워에 비례한 움직이는 x의 크기
	float gety(float t, int angle); // 파워에 비례한 움직이는 y의 크기
	float location_x(); // 미사일 탱크 x좌표
	float location_y(); // 미사일 탱크 y좌표
	int getAttack(); // 미사일 탱크 공격력
	int getDefensive(); // 미사일 탱크 방어력
	float getHP(); // 미사일 탱크 HP
	void update_HP(float new_hp); // 받은 데미지 HP에서 빼주기
	int Power(RenderWindow &window);
	~MissileTank();
};