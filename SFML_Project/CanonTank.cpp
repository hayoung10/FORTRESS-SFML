#include "CanonTank.h"

void CanonTank::init() { // �ʱ����
	Canon_HP = 1000;
	Attack = 300;
	Defensive = 30;
	canTank.loadFromFile("images/tank_canon.png");
	cho_missile_1.loadFromFile("images/missile_canon.png");
	cho_missile_2.loadFromFile("images/missile_canon_2.png");
	missile_sel.loadFromFile("images/missile_selector.png");
	bar_gauge_hp.loadFromFile("images/bar_gauge.png");
	bar_gauge_power.loadFromFile("images/bar_gauge.png");

	cTank.setPosition(120, 370); // �� �̹��� ��ġ ����
	cho_m_1.setPosition(650, 555);
	cho_m_2.setPosition(710, 555);
	selector.setPosition(637, 565);
	hp.setPosition(210, 522);
	power.setPosition(210, 555);

	cTank.setTexture(canTank);
	cTank.setTextureRect(IntRect(40, 0, -40, 40));
	cho_m_1.setTexture(cho_missile_1);
	cho_m_2.setTexture(cho_missile_2);
	selector.setTexture(missile_sel);
	hp.setTexture(bar_gauge_hp);
	hp.setTextureRect(IntRect(0, 0, 350 * Canon_HP / 1000, 20));
}

void CanonTank::change_Selector_Q() { // ���� �� ��ġ ���� �Ʒ���
	selector.setPosition(637, 565);
}

void CanonTank::change_Selector_W() { // ���� �� ��ġ ���� �Ʒ���
	selector.setPosition(697, 565);
}

void CanonTank::change_hpbar() { // HP�� ũ�� �ٲٱ�
	if (Canon_HP < 0)
		hp.setTextureRect(IntRect(0, 0, 0, 0));
	else
		hp.setTextureRect(IntRect(0, 0, 350 * Canon_HP / 1000, 20));
}

void CanonTank::moveLeft() { // ĳ����ũ �������� �����̱�
	cTank.setTextureRect(IntRect(0, 0, 40, 40));
	if (0 <= cTank.getPosition().x)
		cTank.move(-5, 0);
}

void CanonTank::moveRight() { // ĳ����ũ ���������� �����̱�
	cTank.setTextureRect(IntRect(40, 0, -40, 40));
	if (cTank.getPosition().x <= 760)
		cTank.move(5, 0);
}

float CanonTank::getx(int angle) { // �Ŀ��� ����� �����̴� x�� ũ��
	return velocity*cos(3.14 * angle / 180);
}

float CanonTank::gety(float t, int angle) { // �Ŀ��� ����� �����̴� y�� ũ��
	return velocity*sin(3.14 * angle / 180) - 5 * t;
}

float CanonTank::location_x() { // ĳ�� ��ũ x��ǥ
	return cTank.getPosition().x;
}

float CanonTank::location_y() { // ĳ�� ��ũ y��ǥ
	return cTank.getPosition().y;
}

int CanonTank::getAttack() { // ĳ�� ��ũ ���ݷ�
	return Attack;
}

int CanonTank::getDefensive() { // ĳ�� ��ũ ����
	return Defensive;
}

float CanonTank::getHP() { // ĳ����ũ HP
	return Canon_HP;
}

void CanonTank::update_HP(float new_hp) { // ���� ������ HP���� ���ֱ�
	Canon_HP -= new_hp;
}

int CanonTank::Power(RenderWindow &window) { // �Ŀ� �ø��� �Լ�
	Event event;
	clock.restart(); // �ð� �缳��
	velocity = 0; // velocity �ʱ�ȭ
	while (50 * time.asSeconds() <= 350) { // �Ŀ��� �þ �� �ִ� ���� ����
		time = clock.getElapsedTime();
		power.setTexture(bar_gauge_power);
		power.setTextureRect(IntRect(0, 0, 50 * time.asSeconds(), 20)); // �ð��� ���� power �þ��
		window.draw(power);
		window.display();
		while (window.pollEvent(event)) { // Space�� ������ �þ�� power�� ����
			if (event.type == Event::KeyPressed)
				if (Keyboard::isKeyPressed(Keyboard::Space)) { // Space�� �ѹ� �� ������ ����������
					if (50 * time.asSeconds() == 0) // power�� 0�� ��
						velocity = 0;
					if (0 < 50 * time.asSeconds() && 50 * time.asSeconds() <= 350)
						velocity = time.asSeconds()*1.5;
					return 0;
				}
		}
	}
	velocity = 7; // space�ٸ� ������ �ʾ� power�� �ִ��� ��
	return 0;
}

CanonTank::~CanonTank() {

}