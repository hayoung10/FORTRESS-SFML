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

	// 초기 배경상태 만들기
	Run.Start();
	
	int order = 0; // order가 0이면 왼쪽 탱크의 차례, 1이면 오른쪽 탱크의 차례
	int dir_c = 1; // 캐논탱크 방향 설정 // 0이면 왼쪽을, 1이면 오른쪽을 바라보는 의미
	int dir_m = 0; // 미사일탱크 방향 설정 // 0이면 왼쪽을, 1이면 오른쪽을 바라보는 의미
	int can_choose = 0; // 캐논탱크의 미사일 선택 // 0이면 검콩을, 1이면 빨콩을 선택하는 의미
	int mis_choose = 0; // 미사일탱크의 미사일 선택 // 0이면 미사일을, 1이면 유도미사일을 선택하는 의미
	int random = rand() % 70 + 1; // 1~70 에서 랜던으로 값 구하기
	int stop = 0; // 승자가 결정되면 값이 1이 되어 게임 끝내기
	int ang_c = 0, ang_m = 0;

	while (window.isOpen())
	{
		Event event;
		Run.back()->Random_wind(random);
		while (window.pollEvent(event) && (stop == 0))
		{
			if (order == 0) { // 순서가 캐논 탱크라면
				if (dir_c == 0)
					angle_bar.setRotation(225 + ang_c);
				if (dir_c == 1)
					angle_bar.setRotation(-45 - ang_c);
			}
			if (order == 1) { // 순서가 미사일 탱크라면
				if (dir_m == 0)
					angle_bar.setRotation(225 + ang_m);
				if (dir_m == 1)
					angle_bar.setRotation(-45 - ang_m);
			}
			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::KeyPressed) {
				if (order == 0) { // 캐논 탱크의 차례
					if (Keyboard::isKeyPressed(Keyboard::Left)) { // 방향키 왼쪽 눌렀을 때
						Run.CanonT()->moveLeft();
						dir_c = 0;
					}
					if (Keyboard::isKeyPressed(Keyboard::Right)) { // 방향키 오른쪽 눌렀을 때
						Run.CanonT()->moveRight();
						dir_c = 1;
					}
					if (Keyboard::isKeyPressed(Keyboard::Up)) // 방향키 위쪽 눌렀을 때
						if (ang_c < 15)
							ang_c += 1;
					if (Keyboard::isKeyPressed(Keyboard::Down)) // 방향키 아래쪽 눌렀을 때
						if (ang_c > -15)
							ang_c -= 1;
					if (Keyboard::isKeyPressed(Keyboard::Q)) { // Q를 눌렀을 때
						can_choose = 0;
						Run.CanonT()->change_Selector_Q(); // 선택 바 위치 검콩 아래로
					}
					if (Keyboard::isKeyPressed(Keyboard::W)) { // W를 눌렀을 때
						can_choose = 1;
						Run.CanonT()->change_Selector_W(); // 선택 바 위치 빨콩 아래로
					}
					if (Keyboard::isKeyPressed(Keyboard::Space)) { // space바 눌렀을 때
						Run.CanonT()->Power(window); // 파워 올리는 멤버함수 호출
						Run.Choose(can_choose, mis_choose); // 선택한 미사일 알려주기
						if (dir_c == 0) {
							Run.ShootCanon_Left(window, 45 + ang_c); // 왼쪽으로 포 쏘는 함수 호출
							Run.Bomb(window, order, dir_c); // 미사일에 따른 폭발 반경
							sleep(milliseconds(1000));
						}	
						if (dir_c == 1) {
							Run.ShootCanon_Right(window, 45 + ang_c); // 오른쪽으로 포 쏘는 함수 호출
							Run.Bomb(window, order, dir_c); // 미사일에 따른 폭발 반경
							sleep(milliseconds(1000));
						}
						Run.Print_HP(); // 각 탱크의 현재 HP 출력
						if ((Run.CanonT()->getHP() < 0) || (Run.MissileT()->getHP() < 0)) {
							Run.Win(); // 승자 가리기
							stop = 1;
						}
						order = 1; // 오른쪽 탱크의 차례로 넘어감
						random = rand() % 70 + 1;
						break;
					}
				}
				if (order == 1) { // 미사일 탱크의 차례
					if (Keyboard::isKeyPressed(Keyboard::Left)) { // 방향키 왼쪽 눌렀을 때
						Run.MissileT()->moveLeft();
						dir_m = 0;
					}
					if (Keyboard::isKeyPressed(Keyboard::Right)) { // 방향키 오른쪽 눌렀을 때
						Run.MissileT()->moveRight();
						dir_m = 1;
					}
					if (Keyboard::isKeyPressed(Keyboard::Up)) // 방향키 위쪽 눌렀을 때
						if (ang_m < 15)
							ang_m += 1;
					if (Keyboard::isKeyPressed(Keyboard::Down)) // 방향키 아래쪽 눌렀을 때
						if (ang_m > -15)
							ang_m -= 1;
					if (Keyboard::isKeyPressed(Keyboard::Q)) { // Q를 눌렀을 때
						mis_choose = 0;
						Run.MissileT()->change_Selector_Q(); // 선택 바 위치 미사일(1번) 아래로
					}	
					if (Keyboard::isKeyPressed(Keyboard::W)) { // W를 눌렀을 때
						mis_choose = 1;
						Run.MissileT()->change_Selector_W(); // 선택 바 위치 유도 미사일(2번) 아래로
					}
					if (Keyboard::isKeyPressed(Keyboard::Space)) { // space바 눌렀을 때
						Run.MissileT()->Power(window); // 파워 올리는 멤버함수 호출
						Run.Choose(can_choose, mis_choose); // 선택한 미사일 알려주기
						if (dir_m == 0) {
							Run.ShootMissile_Left(window, 45 + ang_m); // 왼쪽으로 포 쏘는 함수 호출
							Run.Bomb(window, order, dir_m); // 미사일에 따른 폭발 반경
							sleep(milliseconds(1000));
						}
						if (dir_m == 1) {
							Run.ShootMissile_Right(window, 45 + ang_m); // 오른쪽으로 포 쏘는 함수 호출
							Run.Bomb(window, order, dir_m); // 미사일에 따른 폭발 반경
							sleep(milliseconds(1000));
						}
						Run.Print_HP(); // 각 탱크의 현재 HP 출력
						if ((Run.CanonT()->getHP() < 0) || (Run.MissileT()->getHP() < 0)) {
							Run.Win(); // 승자 가리기
							stop = 1;
						}
						order = 0; // 왼쪽 탱크의 차례로 넘어감
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
		Run.CanonT()->change_hpbar(); // 캐논 탱크 HP Bar 크기 변경
		Run.MissileT()->change_hpbar(); // 미사일 탱크 HP Bar 크기 변경
	}
	return 0;
}