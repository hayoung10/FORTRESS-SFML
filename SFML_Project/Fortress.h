#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include "Background.h"
#include "CanonTank.h"
#include "MissileTank.h"
#include <iostream>
using namespace sf;

class Fortress {
private:
	int canChoose, misChoose;
	Back *background;
	CanonTank *Tank1;
	MissileTank *Tank2;
	Texture can_missile, mis_missile, bomb, win; // can_missile : 캐논탱크 미사일, mis_missile : 미사일탱크 미사일
	// bomb : 폭발 반경, win : 승부가 났을 때
	RectangleShape *line;
public:
	Sprite Can, Mis, sbomb, swin; // Texture 객체에 대응되는 각각의 Sprite 객체
	float location_x, location_y; // 포가 땅에 떨어졌을 때의 위치
	Fortress();
	void Start(); // 배경, 캐논탱크, 미사일탱크 초기상태 시작
	Back* back();
	CanonTank* CanonT();
	MissileTank* MissileT();
	void Choose(int canC, int misC); // 캐논탱크와 미사일탱크가 선택한 미사일이 무엇인지 받는 함수
	int ShootCanon_Left(RenderWindow &window, int angle); // 캐논탱크가 왼쪽 방향 볼때 포쏘기
	int ShootCanon_Right(RenderWindow &window,int angle); // 캐논탱크가 오른쪽 방향 볼때 포쏘기
	int ShootMissile_Left(RenderWindow &window, int angle); // 미사일탱크가 왼쪽 방향 볼때 포쏘기
	int ShootMissile_Right(RenderWindow &window, int angle); // 미사일탱크가 오른쪽 방향 볼때 포쏘기
	void Bomb(RenderWindow &window, int order, int direction);  // 폭발 반경 나타내고 데미지 범위 지정
	int Check_Canon(float range_l, float range_r); // 캐논탱크가 반경내에 있는지 확인
	int Check_Missile(float range_l, float range_r); // 미사일탱크가 반경내에 있는지 확인
	void Damage(int whois, int tank_attack, float attack, float radius); // 받은 데미지
	void draw(RenderWindow &window, int order, bool finish);
	void Print_HP(); // 탱크들의 현재 HP 출력
	void Win(); // 승자 출력
	~Fortress();
};