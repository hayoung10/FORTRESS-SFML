#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
using namespace sf;

class Back {
private:
	Texture map, bar, wind; // map&bar : ���, wind : �ٶ�
	float windvalue;
public:
	Sprite smap, sbar, swind; // Texture ��ü�� �����Ǵ� ������ Sprite ��ü
	void init_state(); // �ʱ� ���
	void Random_wind(int random); // �ٶ� ���� ���̱�
	void getwind(float random); // �ٶ� ���� ����
	float getwindvalue(); // �ٶ� ��
	~Back();
};