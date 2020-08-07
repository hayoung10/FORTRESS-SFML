#include "Background.h"

void Back::init_state() { // 초기 배경
	map.loadFromFile("images/map_skybridge.png");
	bar.loadFromFile("images/statusbar.png");
	
	smap.setPosition(0, 0); // 각 그림들 위치 설정
	sbar.setPosition(0, 500);

	smap.setTexture(map); // 각각의 sprite 객체에 그림 넣어주기
	sbar.setTexture(bar);
}

void Back::Random_wind(int random) { // 바람 정도 보이기
	wind.loadFromFile("images/wind_gauge.png");
	swind.setPosition(69, 572);
	if (random % 2 == 0) {
		swind.setScale(Vector2f(random / 10, 1));
		getwind(random);
	}
	else {
		swind.setScale(Vector2f((-1)*random / 10, 1));
		getwind((-1)*random);
	}
	swind.setTexture(wind);
}

void Back::getwind(float random) { // 바람 정도 조절
	windvalue = random / 50;
}

float Back::getwindvalue() { // 바람 값
	return windvalue;
}

Back::~Back() {

}