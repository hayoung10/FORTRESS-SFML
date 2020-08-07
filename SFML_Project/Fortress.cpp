#include "Fortress.h"

Fortress::Fortress() {
	background = new Back;
	Tank1 = new CanonTank;
	Tank2 = new MissileTank;
}

void Fortress::Start() {
	background->init_state();
	Tank1->init();
	Tank2->init();
}

Back* Fortress::back() {
	return background;
}

CanonTank* Fortress::CanonT() {
	return Tank1;
}

MissileTank* Fortress::MissileT() {
	return Tank2;
}

void Fortress::Choose(int canC, int misC) {
	canChoose = canC;
	misChoose = misC;
}

int Fortress::ShootCanon_Left(RenderWindow &window, int angle) { // 캐논탱크가 왼쪽 방향 볼때 포쏘기
	if (canChoose == 0)
		can_missile.loadFromFile("images/missile_canon.png");
	if (canChoose == 1)
		can_missile.loadFromFile("images/missile_canon_2.png");
	Can.setPosition(Tank1->cTank.getPosition().x + 10, 405); //  포 위치 설정
	float y = Can.getPosition().y;
	float t = 0;
	Can.setTexture(can_missile);
	Can.setRotation(angle);
	float resistance = background->getwindvalue();
	while (0 <= y) {
		t += 0.005;
		y -= Tank1->gety(t, angle);
		Can.move((-0.5)*(Tank1->getx(angle) - resistance), (-0.5)*Tank1->gety(t, angle));
		draw(window, 0, false);
		Can.setRotation((-75)*t);
		if (y > 405) { // 포가 땅에 닿으면 함수 빠져나오기
			location_x = Can.getPosition().x;
			location_y = Can.getPosition().y;
			return 0;
		}
	}
}

int Fortress::ShootCanon_Right(RenderWindow &window, int angle) { // 캐논탱크가 오른쪽 방향 볼때 포쏘기
	if (canChoose == 0)
		can_missile.loadFromFile("images/missile_canon.png");
	if (canChoose == 1)
		can_missile.loadFromFile("images/missile_canon_2.png");
	Can.setPosition(Tank1->cTank.getPosition().x + 20, 405); //  포 위치 설정
	float y = Can.getPosition().y;
	float t = 0;
	Can.setTexture(can_missile);
	Can.setRotation((-1)*angle);
	float resistance = background->getwindvalue();
	while (0 <= y) {
		t += 0.005;
		y -= Tank1->gety(t, angle);
		Can.move(0.5*(Tank1->getx(angle) + resistance), (-0.5)*Tank1->gety(t, angle));
		draw(window, 0, false);
		Can.setRotation(75*t);
		if (y > 405) { // 포가 땅에 닿으면 함수 빠져나오기
			location_x = Can.getPosition().x;
			location_y = Can.getPosition().y;
			return 0;
		}
	}
}

int Fortress::ShootMissile_Left(RenderWindow &window, int angle) { // 미사일탱크가 왼쪽 방향 볼때 포쏘기
	if (misChoose == 0)
		mis_missile.loadFromFile("images/missile_missile_1.png");
	if (misChoose == 1)
		mis_missile.loadFromFile("images/missile_missile_2.png");
	Mis.setPosition(Tank2->mTank.getPosition().x + 10, 405); // 포 위치 설정
	float y = Mis.getPosition().y;
	float t = 0;
	Mis.setTexture(mis_missile);
	Mis.setTextureRect(IntRect(40, 0, -40, 40));
	Mis.setRotation(angle);
	float resistance = background->getwindvalue();
	while (0 <= y) {
		t += 0.005;
		y -= Tank2->gety(t, angle);
		Mis.move((-0.5)*(Tank2->getx(angle) - resistance), (-0.5)*Tank2->gety(t, angle));
		draw(window, 1, false);
		Mis.setRotation((-75)*t);
		if (y > 405) { // 포가 땅에 닿으면 함수 빠져나오기
			location_x = Mis.getPosition().x;
			location_y = Mis.getPosition().y;
			return 0;
		}
	}
}

int Fortress::ShootMissile_Right(RenderWindow &window, int angle) { // 미사일탱크가 오른쪽 방향 볼때 포쏘기
	if (misChoose == 0)
		mis_missile.loadFromFile("images/missile_missile_1.png");
	if (misChoose == 1)
		mis_missile.loadFromFile("images/missile_missile_2.png");
	Mis.setPosition(Tank2->mTank.getPosition().x + 20, 405); // 포 위치 설정
	float y = Mis.getPosition().y;
	float t = 0;
	Mis.setTexture(mis_missile);
	Mis.setTextureRect(IntRect(0, 0, 40, 40));
	Mis.setRotation((-1)*angle);
	float resistance = background->getwindvalue();
	while (0 <= y) {
		t += 0.005;
		y -= Tank2->gety(t, angle);
		Mis.move(0.5*(Tank2->getx(angle) + resistance), (-0.5)*Tank2->gety(t, angle));
		draw(window, 1, false);
		Mis.setRotation(75*t);
		if (y > 405) { // 포가 땅에 닿으면 함수 빠져나오기
			location_x = Mis.getPosition().x;
			location_y = Mis.getPosition().y;
			return 0;
		}
	}
}

void Fortress::Bomb(RenderWindow &window, int order, int direction) { // 폭발 반경 나타내고 데미지 범위 지정
	float tank_attack = 0, attack = 0, range_l = 0, range_r = 0;
	float position_x = 0; // 탱크 위치의 x좌표
	bomb.loadFromFile("images/bomb.png");
	if (order == 0) {
		if (canChoose == 0) {
			sbomb.setScale(Vector2f(1, 1));
			sbomb.setPosition(location_x - 100, location_y - 40);
			range_l = location_x - 100;
			range_r = location_x + 100;
			attack = 0.6;
		}
		if (canChoose == 1) {
			sbomb.setScale(Vector2f(0.2, 0.2));
			if (direction == 0) {
				sbomb.setPosition(location_x - 10, location_y - 15);
				range_l = location_x - 10;
				range_r = location_x + 30;
			}
			if (direction == 1) {
				sbomb.setPosition(location_x - 23, location_y - 15);
				range_l = location_x - 23;
				range_r = location_x + 17;
			}
			attack = 2;
		}
		tank_attack = Tank1->getAttack();
	}
	if (order == 1) {
		if (misChoose == 0) {
			sbomb.setScale(Vector2f(0.4, 0.4));
			if (direction == 0) {
				sbomb.setPosition(location_x - 17, location_y - 20);
				range_l = location_x - 17;
				range_r = location_x + 63;
			}
			if (direction == 1) {
				sbomb.setPosition(location_x - 40, location_y - 20);
				range_l = location_x - 40;
				range_r = location_x + 40;
			}
			attack = 1.2;
		}
		if (misChoose == 1) {
			sbomb.setScale(Vector2f(0.2, 0.2));
			if (direction == 0) {
				sbomb.setPosition(location_x, location_y - 15);
				range_l = location_x - 20;
				range_r = location_x + 20;
			}
			if (direction == 1) {
				sbomb.setPosition(location_x - 30, location_y - 15);
				range_l = location_x - 30;
				range_r = location_x + 10;
			}
			attack = 0.3;
		}
		tank_attack = Tank2->getAttack();
	}
	sbomb.setTexture(bomb);

	if (Check_Canon(range_l, range_r) == true) {
		position_x = Tank1->cTank.getPosition().x + 20;
		float radius = abs((range_l + range_r) / 2 - position_x) / ((range_r - range_l + 80) / 2);
		Damage(0, tank_attack, attack, radius);
	}
	if (Check_Missile(range_l, range_r) == true) {
		position_x = Tank2->mTank.getPosition().x + 20;
		float radius = abs((range_l + range_r) / 2 - position_x) / ((range_r - range_l + 80) / 2);
		Damage(1, tank_attack, attack, radius);
	}
	draw(window, order, true);
}

int Fortress::Check_Canon(float range_l, float range_r) { // 캐논탱크가 반경내에 있는지 확인
	if (((range_l - 40) < Tank1->cTank.getPosition().x) && (Tank1->cTank.getPosition().x < range_r))
		return true;
	else
		return false;
}

int Fortress::Check_Missile(float range_l, float range_r) { // 미사일탱크가 반경내에 있는지 확인
	if (((range_l - 40) < Tank2->mTank.getPosition().x) && (Tank2->mTank.getPosition().x < range_r))
		return true;
	else
		return false;
}

void Fortress::Damage(int whois, int tank_attack, float attack, float radius) { // 받은 데미지
	if (whois == 0) {
		Tank1->update_HP((tank_attack*attack*(1 - Tank1->getDefensive() / 100))*(1 - radius));
	}
	if (whois == 1) {
		Tank2->update_HP((tank_attack*attack*(1 - Tank2->getDefensive() / 100))*(1 - radius));
	}
}

void Fortress::draw(RenderWindow &window, int order, bool finish) { // 포 쏠때 전체 배경을 계속 그려주기
	window.clear();
	window.draw(background->smap);
	window.draw(background->sbar);
	window.draw(background->swind);
	window.draw(Tank1->cTank);
	window.draw(Tank2->mTank);
	if (order == 0) {
		window.draw(Tank1->cho_m_1);
		window.draw(Tank1->cho_m_2);
		window.draw(Tank1->selector);
		window.draw(Tank1->hp);
		if (finish == true)
			window.draw(sbomb);
		if (finish == false)
			window.draw(Can);
	}
	if (order == 1) {
		window.draw(Tank2->cho_m_1);
		window.draw(Tank2->cho_m_2);
		window.draw(Tank2->selector);
		window.draw(Tank2->hp);
		if (finish == true)
			window.draw(sbomb);
		if (finish == false)
			window.draw(Mis);
	}
	window.display();
}

void Fortress::Print_HP() { // 탱크들의 현재 HP 출력
	cout << "1P : " << Tank1->getHP() << endl;
	cout << "2P : " << Tank2->getHP() << endl;
}

void Fortress::Win() { // 승자 출력
	if (CanonT()->getHP() < 0) {
		win.loadFromFile("images/2pwin.png");
		swin.setPosition(250, 200);
		swin.setTexture(win);
	}
	if (MissileT()->getHP() < 0) {
		win.loadFromFile("images/1pwin.png");
		swin.setPosition(250, 200);
		swin.setTexture(win);
	}
}

Fortress::~Fortress() {
	delete background;
	delete Tank1;
	delete Tank2;
}