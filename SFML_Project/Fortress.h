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
	Texture can_missile, mis_missile, bomb, win; // can_missile : ĳ����ũ �̻���, mis_missile : �̻�����ũ �̻���
	// bomb : ���� �ݰ�, win : �ºΰ� ���� ��
	RectangleShape *line;
public:
	Sprite Can, Mis, sbomb, swin; // Texture ��ü�� �����Ǵ� ������ Sprite ��ü
	float location_x, location_y; // ���� ���� �������� ���� ��ġ
	Fortress();
	void Start(); // ���, ĳ����ũ, �̻�����ũ �ʱ���� ����
	Back* back();
	CanonTank* CanonT();
	MissileTank* MissileT();
	void Choose(int canC, int misC); // ĳ����ũ�� �̻�����ũ�� ������ �̻����� �������� �޴� �Լ�
	int ShootCanon_Left(RenderWindow &window, int angle); // ĳ����ũ�� ���� ���� ���� �����
	int ShootCanon_Right(RenderWindow &window,int angle); // ĳ����ũ�� ������ ���� ���� �����
	int ShootMissile_Left(RenderWindow &window, int angle); // �̻�����ũ�� ���� ���� ���� �����
	int ShootMissile_Right(RenderWindow &window, int angle); // �̻�����ũ�� ������ ���� ���� �����
	void Bomb(RenderWindow &window, int order, int direction);  // ���� �ݰ� ��Ÿ���� ������ ���� ����
	int Check_Canon(float range_l, float range_r); // ĳ����ũ�� �ݰ泻�� �ִ��� Ȯ��
	int Check_Missile(float range_l, float range_r); // �̻�����ũ�� �ݰ泻�� �ִ��� Ȯ��
	void Damage(int whois, int tank_attack, float attack, float radius); // ���� ������
	void draw(RenderWindow &window, int order, bool finish);
	void Print_HP(); // ��ũ���� ���� HP ���
	void Win(); // ���� ���
	~Fortress();
};