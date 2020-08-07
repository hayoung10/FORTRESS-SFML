# FORTRESS-SFML
2018.06.21
SFML을 활용한 FORTRESS 게임 구현 과제

## 기본 설정
- 두 탱크는 번갈아가며 동작하며 초기 HP는 모두 1000으로 설정되어 있음
- Canon Tank ![이미지1](/SFML_Project/images/tank_canon.png) 의 공격력 : 300, 방어력 : 30
- Missile Tank ![이미지2](/SFML_Project/images/tank_missile.png) 의 공격력 : 200, 방어력 : 40
  - 공격력은 포탄의 종류에 따라 기본 공격력에서 추가 혹은 감소
  - 방어력은 받는 공격으로부터 방어력 수치%만큼 데미지를 감소
    - ex. 공격력 200의 공격을 받는데 방어력이 40일 경우 200*0.4=80만큼 데미지를 받음
- 각 미사일은 폭발 반경과 데미지 값을 가지고 있음
  - 가까이서 미사일이 터질수록 데미지가 커짐
- Canon Tank의 미사일
  - ![이미지3](/SFML_Project/images/missile_canon.png) 검콩 : 넓은 반경의 폭발범위를 가지지만 데미지가 낮다
    - Range : 100
    - Attack : 0.6
  - ![이미지4](/SFML_Project/images/missile_canon_2.png) 빨콩 : 좁은 반경의 폭발범위를 가지지만 데미지가 높다
    - Range : 20
    - Attack : 2
- Missile Tank의 미사일
  - ![이미지5](/SFML_Project/images/missile_missile_1.png) 미사일 : 평범한 범위와 평범한 데미지를 낸다
    - Range : 40
    - Attack : 1.2
  - ![이미지6](/SFML_Project/images/missile_missile_2.png)유도미사일 : 좁은 반경의 폭발범위와 낮은 데미지를 가지지만 적에게 적중시킨다
    - Range : 20
    - Attack : 0.3
- 바람, 각도 : 왼쪽 하단에 표기되어 있음
  - 바람 : 랜덤한 값으로 설정됨
  - 각도 : 좌우 각 30~60도 이내의 값 중 랜덤한 값으로 설정됨

## 작동법
- 좌우 방향키를 통해 탱크를 움직임
- Q,W 버튼으로 미사일 선택
- space바를 한번 누르면 파워 게이지가 올라가고, 한번 더 누르면 오른 게이지만큼 보고 있는 방향으로 미사일 발사

## Screenshots
![스크린샷](https://github.com/hayoung10/FORTRESS-SFML/issues/1#issue-674991031)
