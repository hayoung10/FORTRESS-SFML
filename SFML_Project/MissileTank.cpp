#include "MissileTank.h"

void MissileTank::init() { // �ʱ����
	Missile_HP = 1000;
	Attack = 200;
	Defensive = 40;
	misTank.loadFromFile("images/tank_missile.png");
	cho_missile_1.loadFromFile("images/missile_missile_1.png");
	cho_missile_2.loadFromFile("images/missile_missile_2.png");
	missile_sel.loadFromFile("images/missile_selector.png");
	bar_gauge_hp.loadFromFile("images/bar_gauge.png");
	bar_gauge_power.loadFromFile("images/bar_gauge.png");

	mTank.setPosition(650, 370); // �� �̹��� ��ġ ����
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

void MissileTank::change_Selector_Q() { // ���� �� ��ġ �̻���(1��) �Ʒ���
	selector.setPosition(640, 565);
}

void MissileTank::change_Selector_W() { // ���� �� ��ġ �����̻���(2��) �Ʒ���
	selector.setPosition(700, 565);
}

void MissileTank::change_hpbar() { // HP�� ũ�� �ٲٱ�
	if (Missile_HP < 0)
		hp.setScale(Vector2f(0, 0));
	else
		hp.setTextureRect(IntRect(0, 0, 350 * Missile_HP / 1000, 20));
}

void MissileTank::moveLeft() { // �̻�����ũ �������� �����̱�
	mTank.setTextureRect(IntRect(0, 0, 40, 40));
	if (0 <= mTank.getPosition().x)
		mTank.move(-5, 0);
}

void MissileTank::moveRight() { // �̻�����ũ ���������� �����̱�
	mTank.setTextureRect(IntRect(40, 0, -40, 40));
	if (mTank.getPosition().x <= 760)
		mTank.move(5, 0);
}

float MissileTank::getx(int angle) { // �Ŀ��� ����� �����̴� x�� ũ��
	return velocity*cos(3.14 * angle / 180);
}

float MissileTank::gety(float t, int angle) { // �Ŀ��� ����� �����̴� y�� ũ��
	return velocity*sin(3.14 * angle / 180) - 5 * t;
}

float MissileTank::location_x() { // �̻��� ��ũ x��ǥ
	return mTank.getPosition().x;
}

float MissileTank::location_y() { // �̻��� ��ũ y��ǥ
	return mTank.getPosition().y;
}

int MissileTank::getAttack() { // �̻��� ��ũ ���ݷ�
	return Attack;
}

int MissileTank::getDefensive() { // �̻��� ��ũ ����
	return Defensive;
}

float MissileTank::getHP() { // �̻�����ũ HP
	return Missile_HP;
}

void MissileTank::update_HP(float new_hp) { // ���� ������ HP���� ���ֱ�
	Missile_HP -= new_hp;
}

int MissileTank::Power(RenderWindow &window) { // �Ŀ� �ø��� �Լ�
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

MissileTank::~MissileTank() {

}