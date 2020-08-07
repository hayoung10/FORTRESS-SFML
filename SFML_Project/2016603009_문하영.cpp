#include <SFML/Graphics.hpp>
#include <math.h>
#include "Background.h"
#include "CanonTank.h"
#include "MissileTank.h"
#include "Fortress.h"
#include <stdlib.h>
using namespace sf;


int main()
{
	RenderWindow window(VideoMode(800, 600), "FORTRESS works!");
	Fortress Run;
	RectangleShape angle_bar(Vector2f(55, 2));
	angle_bar.setPosition(70, 567);
	angle_bar.setFillColor(Color(150, 50, 250));
	angle_bar.setRotation(-45);

	// �ʱ� ������ �����
	Run.Start();
	
	int order = 0; // order�� 0�̸� ���� ��ũ�� ����, 1�̸� ������ ��ũ�� ����
	int dir_c = 1; // ĳ����ũ ���� ���� // 0�̸� ������, 1�̸� �������� �ٶ󺸴� �ǹ�
	int dir_m = 0; // �̻�����ũ ���� ���� // 0�̸� ������, 1�̸� �������� �ٶ󺸴� �ǹ�
	int can_choose = 0; // ĳ����ũ�� �̻��� ���� // 0�̸� ������, 1�̸� ������ �����ϴ� �ǹ�
	int mis_choose = 0; // �̻�����ũ�� �̻��� ���� // 0�̸� �̻�����, 1�̸� �����̻����� �����ϴ� �ǹ�
	int random = rand() % 70 + 1; // 1~70 ���� �������� �� ���ϱ�
	int stop = 0; // ���ڰ� �����Ǹ� ���� 1�� �Ǿ� ���� ������
	int ang_c = 0, ang_m = 0;

	while (window.isOpen())
	{
		Event event;
		Run.back()->Random_wind(random);
		while (window.pollEvent(event) && (stop == 0))
		{
			if (order == 0) { // ������ ĳ�� ��ũ���
				if (dir_c == 0)
					angle_bar.setRotation(225 + ang_c);
				if (dir_c == 1)
					angle_bar.setRotation(-45 - ang_c);
			}
			if (order == 1) { // ������ �̻��� ��ũ���
				if (dir_m == 0)
					angle_bar.setRotation(225 + ang_m);
				if (dir_m == 1)
					angle_bar.setRotation(-45 - ang_m);
			}
			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::KeyPressed) {
				if (order == 0) { // ĳ�� ��ũ�� ����
					if (Keyboard::isKeyPressed(Keyboard::Left)) { // ����Ű ���� ������ ��
						Run.CanonT()->moveLeft();
						dir_c = 0;
					}
					if (Keyboard::isKeyPressed(Keyboard::Right)) { // ����Ű ������ ������ ��
						Run.CanonT()->moveRight();
						dir_c = 1;
					}
					if (Keyboard::isKeyPressed(Keyboard::Up)) // ����Ű ���� ������ ��
						if (ang_c < 15)
							ang_c += 1;
					if (Keyboard::isKeyPressed(Keyboard::Down)) // ����Ű �Ʒ��� ������ ��
						if (ang_c > -15)
							ang_c -= 1;
					if (Keyboard::isKeyPressed(Keyboard::Q)) { // Q�� ������ ��
						can_choose = 0;
						Run.CanonT()->change_Selector_Q(); // ���� �� ��ġ ���� �Ʒ���
					}
					if (Keyboard::isKeyPressed(Keyboard::W)) { // W�� ������ ��
						can_choose = 1;
						Run.CanonT()->change_Selector_W(); // ���� �� ��ġ ���� �Ʒ���
					}
					if (Keyboard::isKeyPressed(Keyboard::Space)) { // space�� ������ ��
						Run.CanonT()->Power(window); // �Ŀ� �ø��� ����Լ� ȣ��
						Run.Choose(can_choose, mis_choose); // ������ �̻��� �˷��ֱ�
						if (dir_c == 0) {
							Run.ShootCanon_Left(window, 45 + ang_c); // �������� �� ��� �Լ� ȣ��
							Run.Bomb(window, order, dir_c); // �̻��Ͽ� ���� ���� �ݰ�
							sleep(milliseconds(1000));
						}	
						if (dir_c == 1) {
							Run.ShootCanon_Right(window, 45 + ang_c); // ���������� �� ��� �Լ� ȣ��
							Run.Bomb(window, order, dir_c); // �̻��Ͽ� ���� ���� �ݰ�
							sleep(milliseconds(1000));
						}
						Run.Print_HP(); // �� ��ũ�� ���� HP ���
						if ((Run.CanonT()->getHP() < 0) || (Run.MissileT()->getHP() < 0)) {
							Run.Win(); // ���� ������
							stop = 1;
						}
						order = 1; // ������ ��ũ�� ���ʷ� �Ѿ
						random = rand() % 70 + 1;
						break;
					}
				}
				if (order == 1) { // �̻��� ��ũ�� ����
					if (Keyboard::isKeyPressed(Keyboard::Left)) { // ����Ű ���� ������ ��
						Run.MissileT()->moveLeft();
						dir_m = 0;
					}
					if (Keyboard::isKeyPressed(Keyboard::Right)) { // ����Ű ������ ������ ��
						Run.MissileT()->moveRight();
						dir_m = 1;
					}
					if (Keyboard::isKeyPressed(Keyboard::Up)) // ����Ű ���� ������ ��
						if (ang_m < 15)
							ang_m += 1;
					if (Keyboard::isKeyPressed(Keyboard::Down)) // ����Ű �Ʒ��� ������ ��
						if (ang_m > -15)
							ang_m -= 1;
					if (Keyboard::isKeyPressed(Keyboard::Q)) { // Q�� ������ ��
						mis_choose = 0;
						Run.MissileT()->change_Selector_Q(); // ���� �� ��ġ �̻���(1��) �Ʒ���
					}	
					if (Keyboard::isKeyPressed(Keyboard::W)) { // W�� ������ ��
						mis_choose = 1;
						Run.MissileT()->change_Selector_W(); // ���� �� ��ġ ���� �̻���(2��) �Ʒ���
					}
					if (Keyboard::isKeyPressed(Keyboard::Space)) { // space�� ������ ��
						Run.MissileT()->Power(window); // �Ŀ� �ø��� ����Լ� ȣ��
						Run.Choose(can_choose, mis_choose); // ������ �̻��� �˷��ֱ�
						if (dir_m == 0) {
							Run.ShootMissile_Left(window, 45 + ang_m); // �������� �� ��� �Լ� ȣ��
							Run.Bomb(window, order, dir_m); // �̻��Ͽ� ���� ���� �ݰ�
							sleep(milliseconds(1000));
						}
						if (dir_m == 1) {
							Run.ShootMissile_Right(window, 45 + ang_m); // ���������� �� ��� �Լ� ȣ��
							Run.Bomb(window, order, dir_m); // �̻��Ͽ� ���� ���� �ݰ�
							sleep(milliseconds(1000));
						}
						Run.Print_HP(); // �� ��ũ�� ���� HP ���
						if ((Run.CanonT()->getHP() < 0) || (Run.MissileT()->getHP() < 0)) {
							Run.Win(); // ���� ������
							stop = 1;
						}
						order = 0; // ���� ��ũ�� ���ʷ� �Ѿ
						random = rand() % 70 + 1;
						break;
					}
				}
			}
		}
		window.clear();
		window.draw(Run.back()->smap);
		window.draw(Run.back()->sbar);
		window.draw(Run.CanonT()->cTank);
		window.draw(Run.MissileT()->mTank);
		window.draw(Run.back()->swind);
		window.draw(angle_bar);
		if (order == 0) {
			window.draw(Run.CanonT()->cho_m_1);
			window.draw(Run.CanonT()->cho_m_2);
			window.draw(Run.CanonT()->hp);
			window.draw(Run.CanonT()->selector);
		}
		if (order == 1) {
			window.draw(Run.MissileT()->cho_m_1);
			window.draw(Run.MissileT()->cho_m_2);
			window.draw(Run.MissileT()->hp);
			window.draw(Run.MissileT()->selector);
		}
		if ((Run.CanonT()->getHP() < 0) || (Run.MissileT()->getHP() < 0))
			window.draw(Run.swin);
		window.display();
		Run.CanonT()->change_hpbar(); // ĳ�� ��ũ HP Bar ũ�� ����
		Run.MissileT()->change_hpbar(); // �̻��� ��ũ HP Bar ũ�� ����
	}
	return 0;
}