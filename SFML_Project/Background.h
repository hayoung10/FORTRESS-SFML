#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
using namespace sf;

class Back {
private:
	Texture map, bar, wind; // map&bar : 배경, wind : 바람
	float windvalue;
public:
	Sprite smap, sbar, swind; // Texture 객체에 대응되는 각각의 Sprite 객체
	void init_state(); // 초기 배경
	void Random_wind(int random); // 바람 정도 보이기
	void getwind(float random); // 바람 정도 조절
	float getwindvalue(); // 바람 값
	~Back();
};