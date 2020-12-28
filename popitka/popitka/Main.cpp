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

	/////////////////// ����� �������� ����������

	m.drawing(); //�������� ����� (���� ���� �������)
	z.draw_p(); //�������� �����

	return 0;
}

