#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include "Background.h"
#include "MissileTank.h"
using namespace sf;
using namespace std;

class CanonTank {
private:
	int Attack, Defensive; // Attack : ���ݷ�, Defensive : ����
	float Canon_HP; // Canon_HP : ĳ����ũ HP
	Texture canTank, cho_missile_1, cho_missile_2, canmissile, missile_sel, bar_gauge_hp, bar_gauge_power;
	// canTank : ĳ����ũ, cho_missile_1 : ���� �̻���, cho_missile_2 : ���� �̻���, canmissile : ������ �̻���
	// missile_sel : ���� ��, bar_gauge_hp : HP��, bar_gauge_power : �Ŀ���
	Time time;
	Clock clock;
	float velocity; // �ӷ�
public:
	Sprite cTank, cho_m_1, cho_m_2, missile, selector, hp, power; // Texture ��ü�� �����Ǵ� ������ Sprite ��ü
	void init(); // �ʱ����
	void change_Selector_Q(); // ���� �� ��ġ ���� �Ʒ���
	void change_Selector_W(); // ���� �� ��ġ ���� �Ʒ���
	void change_hpbar(); // HP�� ũ�� �ٲٱ�
	void moveLeft(); // ĳ����ũ �������� �����̱�
	void moveRight(); // ĳ����ũ ���������� �����̱�
	float getx(int angle); // �Ŀ��� �������׿� ���� x�� �����̴� ũ��
	float gety(float t, int angle); // �Ŀ��� �ð��� ���� y�� �����̴� ũ��
	float location_x(); // ĳ�� ��ũ x��ǥ
	float location_y(); // ĳ�� ��ũ y��ǥ
	int getAttack(); // ĳ�� ��ũ ���ݷ�
	int getDefensive(); // ĳ�� ��ũ ����
	float getHP(); // ĳ�� ��ũ HP
	void update_HP(float new_hp); // ���� ������ HP���� ���ֱ�
	int Power(RenderWindow &window);
	//void draw(RenderWindow &window);
	~CanonTank();
};