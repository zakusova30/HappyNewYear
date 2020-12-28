#include <iostream>
#include <SFML/Graphics.hpp> /// ���������� ������������ ����, ������� �������� �� ������ � ��������
#include "map.h"
#include "globals.h"
#include "player.h"
#include "Enemies.h"
#include <list>
#include "Shooting.h"

using namespace std;
using namespace sf;

void winner(RenderWindow & window) // �������� ���� ����������
{
	Texture winning_screen;
	winning_screen.loadFromFile("images/win.png"); // ��������� ����������� 
	Sprite winscreen(winning_screen);
	winscreen.setPosition(32, 32);

	window.draw(winscreen);
	window.display(); // ������� �� �����
}


void lose(RenderWindow & window)  // ��������� ���� ������������
{
	Texture losee;
	losee.loadFromFile("images/lose.jpg");
	Sprite lose(losee);
	lose.setPosition(32, 32);

	window.draw(lose);
	window.display();
}



int main()
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


	Font font;  // �����
	font.loadFromFile("Ben_Krush.ttf");
	Text text("", font, 20); // ������ ������
	text.setStyle(sf::Text::Bold); // ����� ������

	while (window.isOpen()) // ���� ���� ������
	{
		if (z.win >= 1) //� ������ ������ ���������� ���� ������
		{
			window.close();
			RenderWindow window(sf::VideoMode(789, 514), "WIN");
			winner(window);
			while (!Mouse::isButtonPressed(Mouse::Right));
		}
		if (z.hp <= 0) // � ������ ��������� ���������� ����  ���������
		{
			window.close();
			RenderWindow window(sf::VideoMode(1000, 667), "LOSE");
			lose(window);
			while (!Mouse::isButtonPressed(Mouse::Right));
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

		for (cc = child.begin(); cc != child.end(); cc++) {
			(*cc)->drawing(z.GetPlayerCoordinateX(), z.GetPlayerCoordinateY(), z);
		}

		for (shh = shoott.begin(); shh != shoott.end(); shh++) {
			(*shh)->draw();


			if ((*shh)->shoot > 300) {
				(*shh)->shoot = 0;
				FloatRect polozh = (*shh)->position();
				float uskor = (*shh)->acceleration();
				bullets.push_back(new Shooting::Bullet(polozh, uskor));
			}
			(*shh)->shoot++; //����� ���� ��������
		}

		for (bul = bullets.begin(); bul != bullets.end(); bul++) {
			if ((*bul)->life) {

				(*bul)->WithPlayer(z); //�������������� ���� � �������
				(*bul)->drawing();
			}
			else {
				delete((*bul)); //���� ��������� �������� �� �����, ������ ������� �����
				bullets.remove(*bul);
				break;
			}
		}






		text.setString("��������:");
		text.setPosition(5, 0);
		window.draw(text);
		window.draw(z.hpbar);


		text.setString("�����:");
		text.setPosition(800, 0);
		window.draw(text);
		window.draw(z.keybar);
		window.display();


	}

	return 0;
}

