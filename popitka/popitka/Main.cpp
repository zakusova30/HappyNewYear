#include <iostream>
#include <SFML/Graphics.hpp> /// подключаем заголовочный файл, который отвечает за работу с графикой
#include "Map.h"
#include "Globals.h"
#include "Player.h"
#include "Enemies.h"
#include "Shooting.h"
#include <list>

using namespace std;
using namespace sf;

void winner(RenderWindow & window) // если игрок победит
{
	Texture winning_screen;
	winning_screen.loadFromFile("images/win.png"); // загружаем изображение 
	Sprite winscreen(winning_screen);
	winscreen.setPosition(32, 32);

	window.draw(winscreen);
	window.display(); // выводим на экран
}

void lose(RenderWindow & window) // если игрок проишрает 
{
	Texture losee;
	losee.loadFromFile("images/lose.jpg");
	Sprite lose(losee);
	lose.setPosition(32, 32);

	window.draw(lose);
	window.display();
}

int main() // главная функция
{
	Map drawing;
	Player z("santa.png", 48, 48, 23.0, 23.0);
	Map m;
	Clock clock;

	/////////////////// Нужно добавить контейнеры

	m.drawing(); //рисуется карта (пока окно открыто)
	z.draw_p(); //рисуется игрок

	return 0;
}

