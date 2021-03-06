#include "MissileTank.h"

void MissileTank::init() { // 초기상태
	Missile_HP = 1000;
	Attack = 200;
	Defensive = 40;
	misTank.loadFromFile("images/tank_missile.png");
	cho_missile_1.loadFromFile("images/missile_missile_1.png");
	cho_missile_2.loadFromFile("images/missile_missile_2.png");
	missile_sel.loadFromFile("images/missile_selector.png");
	bar_gauge_hp.loadFromFile("images/bar_gauge.png");
	bar_gauge_power.loadFromFile("images/bar_gauge.png");

	mTank.setPosition(650, 370); // 각 이미지 위치 설정
	cho_m_1.setPosition(650, 550);
	cho_m_2.setPosition(710, 550);
	selector.setPosition(640, 565);
	hp.setPosition(210, 522);
	power.setPosition(210, 555);

	mTank.setTexture(misTank);
	cho_m_1.setTexture(cho_missile_1);
	cho_m_2.setTexture(cho_missile_2);
	selector.setTexture(missile_sel);
	hp.setTexture(bar_gauge_hp);
	hp.setTextureRect(IntRect(0, 0, 350 * Missile_HP / 1000, 20));
}

void MissileTank::change_Selector_Q() { // 선택 바 위치 미사일(1번) 아래로
	selector.setPosition(640, 565);
}

void MissileTank::change_Selector_W() { // 선택 바 위치 유도미사일(2번) 아래로
	selector.setPosition(700, 565);
}

void MissileTank::change_hpbar() { // HP바 크기 바꾸기
	if (Missile_HP < 0)
		hp.setScale(Vector2f(0, 0));
	else
		hp.setTextureRect(IntRect(0, 0, 350 * Missile_HP / 1000, 20));
}

void MissileTank::moveLeft() { // 미사일탱크 왼쪽으로 움직이기
	mTank.setTextureRect(IntRect(0, 0, 40, 40));
	if (0 <= mTank.getPosition().x)
		mTank.move(-5, 0);
}

void MissileTank::moveRight() { // 미사일탱크 오른쪽으로 움직이기
	mTank.setTextureRect(IntRect(40, 0, -40, 40));
	if (mTank.getPosition().x <= 760)
		mTank.move(5, 0);
}

float MissileTank::getx(int angle) { // 파워에 비례한 움직이는 x의 크기
	return velocity*cos(3.14 * angle / 180);
}

float MissileTank::gety(float t, int angle) { // 파워에 비례한 움직이는 y의 크기
	return velocity*sin(3.14 * angle / 180) - 5 * t;
}

float MissileTank::location_x() { // 미사일 탱크 x좌표
	return mTank.getPosition().x;
}

float MissileTank::location_y() { // 미사일 탱크 y좌표
	return mTank.getPosition().y;
}

int MissileTank::getAttack() { // 미사일 탱크 공격력
	return Attack;
}

int MissileTank::getDefensive() { // 미사일 탱크 방어력
	return Defensive;
}

float MissileTank::getHP() { // 미사일탱크 HP
	return Missile_HP;
}

void MissileTank::update_HP(float new_hp) { // 받은 데미지 HP에서 빼주기
	Missile_HP -= new_hp;
}

int MissileTank::Power(RenderWindow &window) { // 파워 올리는 함수
	Event event;
	clock.restart(); // 시간 재설정
	velocity = 0; // velocity 초기화
	while (50 * time.asSeconds() <= 350) { // 파워가 늘어날 수 있는 범위 설정
		time = clock.getElapsedTime();
		power.setTexture(bar_gauge_power);
		power.setTextureRect(IntRect(0, 0, 50 * time.asSeconds(), 20)); // 시간에 의해 power 늘어나기
		window.draw(power);
		window.display();
		while (window.pollEvent(event)) { // Space바 누르면 늘어나는 power가 멈춤
			if (event.type == Event::KeyPressed)
				if (Keyboard::isKeyPressed(Keyboard::Space)) { // Space바 한번 더 누르면 빠져나오기
					if (50 * time.asSeconds() == 0) // power가 0일 때
						velocity = 0;
					if (0 < 50 * time.asSeconds() && 50 * time.asSeconds() <= 350)
						velocity = time.asSeconds()*1.5;
					return 0;
				}
		}
	}
	velocity = 7; // space바를 누르지 않아 power가 최대일 때
	return 0;
}

MissileTank::~MissileTank() {

}