#include "Background.h"

void Back::init_state() { // �ʱ� ���
	map.loadFromFile("images/map_skybridge.png");
	bar.loadFromFile("images/statusbar.png");
	
	smap.setPosition(0, 0); // �� �׸��� ��ġ ����
	sbar.setPosition(0, 500);

	smap.setTexture(map); // ������ sprite ��ü�� �׸� �־��ֱ�
	sbar.setTexture(bar);
}

void Back::Random_wind(int random) { // �ٶ� ���� ���̱�
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

void Back::getwind(float random) { // �ٶ� ���� ����
	windvalue = random / 50;
}

float Back::getwindvalue() { // �ٶ� ��
	return windvalue;
}

Back::~Back() {

}