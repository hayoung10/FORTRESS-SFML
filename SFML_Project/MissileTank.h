#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include "Background.h"
#include "CanonTank.h"
using namespace sf;
using namespace std;

class MissileTank {
private:
	int Attack, Defensive; // Attack : ���ݷ�, Defensive : ����
	float Missile_HP; // Missile_HP : �̻�����ũ HP
	Texture misTank, cho_missile_1, cho_missile_2, mismissile, missile_sel, bar_gauge_hp, bar_gauge_power;
	// misTank : �̻�����ũ, cho_missile_1 : 1�� �̻���, cho_missile_2 : 2�� �̻���, canmissile : ������ �̻���
	// missile_sel : ���� ��, bar_gauge_hp : HP��, bar_gauge_power : �Ŀ���
	Time time;
	Clock clock;
	float velocity; // �ӷ�
public:
	Sprite mTank, cho_m_1, cho_m_2, missile, selector, hp, power; // Texture ��ü�� �����Ǵ� ������ Sprite ��ü
	void init(); // �ʱ� ����
	void change_Selector_Q(); // ���� �� ��ġ �̻���(1��) �Ʒ���
	void change_Selector_W(); // ���� �� ��ġ �����̻���(2��) �Ʒ���
	void change_hpbar(); // HP�� ũ�� �ٲٱ�
	void moveLeft(); // �̻�����ũ �������� �����̱�
	void moveRight(); // �̻�����ũ ���������� �����̱�
	float getx(int angle); // �Ŀ��� ����� �����̴� x�� ũ��
	float gety(float t, int angle); // �Ŀ��� ����� �����̴� y�� ũ��
	float location_x(); // �̻��� ��ũ x��ǥ
	float location_y(); // �̻��� ��ũ y��ǥ
	int getAttack(); // �̻��� ��ũ ���ݷ�
	int getDefensive(); // �̻��� ��ũ ����
	float getHP(); // �̻��� ��ũ HP
	void update_HP(float new_hp); // ���� ������ HP���� ���ֱ�
	int Power(RenderWindow &window);
	~MissileTank();
};