#include <iostream>
#include <SFML/Graphics.hpp> /// ���������� ������������ ����, ������� �������� �� ������ � ��������
#include "Map.h"
#include "Globals.h"
#include "Player.h"
#include "Enemies.h"
#include "Shooting.h"
#include <list>

using namespace std;
using namespace sf;

void winner(RenderWindow & window) // ���� ����� �������
{
	Texture winning_screen;
	winning_screen.loadFromFile("images/win.png"); // ��������� ����������� 
	Sprite winscreen(winning_screen);
	winscreen.setPosition(32, 32);

	window.draw(winscreen);
	window.display(); // ������� �� �����
}

void lose(RenderWindow & window) // ���� ����� ��������� 
{
	Texture losee;
	losee.loadFromFile("images/lose.jpg");
	Sprite lose(losee);
	lose.setPosition(32, 32);

	window.draw(lose);
	window.display();
}

int main() // ������� �������
{
	Map drawing;
	Player z("santa.png", 48, 48, 23.0, 23.0);
	Map m;
	Clock clock;

	//��������� � �������������� ������ LIST ( ����, ������� ����� ��� ��������)
	std::list<Child_Enemies*> child; //����� ������ ��� �� ��������� �����, �� ��� ���� �������� � ����������, � �� ����� ������� ������ ���
	std::list<Child_Enemies*>::iterator cc;

	//��������� � �������������� ������ LIST ( �������, ������� ����� � ��� ����������)
	std::list<Shooting*> shoott;
	std::list<Shooting*>::iterator shh;

	//��������� � �������������� ������ LIST (������� ���������� ������)
	std::list<Shooting::Bullet*> bullets;
	std::list<Shooting::Bullet*>::iterator bul;


	//�� ����� ����������� ����� "������"
	for (int i = 0; i < HEIGHT_MAP; i++) {
		for (int j = 0; j < WIDTH_MAP; j++) {

			//��������
			if (TileMap[i][j] == 'L') {   //���� �� ����� � Maps ���������� "L", �� ���������� ����� ���� (�������)

				child.push_back(new Boy(j, i)); // ���������� �� ���������� ������� - ��������
			}

			//�������
			if (TileMap[i][j] == 'S') {

				child.push_back(new Girl(j, i));// ���������� �� ���������� ������� - �������
			}

			//�������
			if (TileMap[i][j] == 'P') {

				shoott.push_back(new Shoot(j, i)); // ���������� �� ���������� ����
			}
		}
	}

	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();

	}
	window.clear(Color(33, 30, 30));

	m.drawing(); //�������� ����� (���� ���� �������)
	z.draw_p(); //�������� �����

	return 0;
}

