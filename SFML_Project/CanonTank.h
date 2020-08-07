#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include "Background.h"
#include "MissileTank.h"
using namespace sf;
using namespace std;

class CanonTank {
private:
	int Attack, Defensive; // Attack : 공격력, Defensive : 방어력
	float Canon_HP; // Canon_HP : 캐논탱크 HP
	Texture canTank, cho_missile_1, cho_missile_2, canmissile, missile_sel, bar_gauge_hp, bar_gauge_power;
	// canTank : 캐논탱크, cho_missile_1 : 검콩 미사일, cho_missile_2 : 빨콩 미사일, canmissile : 선택한 미사일
	// missile_sel : 선택 바, bar_gauge_hp : HP바, bar_gauge_power : 파워바
	Time time;
	Clock clock;
	float velocity; // 속력
public:
	Sprite cTank, cho_m_1, cho_m_2, missile, selector, hp, power; // Texture 객체에 대응되는 각각의 Sprite 객체
	void init(); // 초기상태
	void change_Selector_Q(); // 선택 바 위치 검콩 아래로
	void change_Selector_W(); // 선택 바 위치 빨콩 아래로
	void change_hpbar(); // HP바 크기 바꾸기
	void moveLeft(); // 캐논탱크 왼쪽으로 움직이기
	void moveRight(); // 캐논탱크 오른쪽으로 움직이기
	float getx(int angle); // 파워와 공기저항에 따른 x가 움직이는 크기
	float gety(float t, int angle); // 파워와 시간에 따른 y가 움직이는 크기
	float location_x(); // 캐논 탱크 x좌표
	float location_y(); // 캐논 탱크 y좌표
	int getAttack(); // 캐논 탱크 공격력
	int getDefensive(); // 캐논 탱크 방어력
	float getHP(); // 캐논 탱크 HP
	void update_HP(float new_hp); // 받은 데미지 HP에서 빼주기
	int Power(RenderWindow &window);
	//void draw(RenderWindow &window);
	~CanonTank();
};