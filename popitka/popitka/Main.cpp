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

	//КОНТЕЙНЕР С ИСПОЛЬЗОВАНИЕМ СПИСКА LIST ( ДЕТИ, которые могут нас заметить)
	std::list<Child_Enemies*> child; //чтобы каждый раз не создавать врага, то они типа хранятся в контейнере, и их можно сколько угодно раз
	std::list<Child_Enemies*>::iterator cc;

	//КОНТЕЙНЕР С ИСПОЛЬЗОВАНИЕМ СПИСКА LIST ( СТРЕЛКИ, которые могут в нас выстрелить)
	std::list<Shooting*> shoott;
	std::list<Shooting*>::iterator shh;

	//КОНТЕЙНЕР С ИСПОЛЬЗОВАНИЕМ СПИСКА LIST (снаряды стреляющих врагов)
	std::list<Shooting::Bullet*> bullets;
	std::list<Shooting::Bullet*>::iterator bul;


	//НА КАРТЕ РАССТАВЛЯЕМ НАШИХ "ВРАГОВ"
	for (int i = 0; i < HEIGHT_MAP; i++) {
		for (int j = 0; j < WIDTH_MAP; j++) {

			//МАЛЬЧИКИ
			if (TileMap[i][j] == 'L') {   //Если на карте в Maps поставлена "L", то появляется новый враг (мальчик)

				child.push_back(new Boy(j, i)); // возвращаем из контейнера ребенка - мальчика
			}

			//ДЕВОЧКИ
			if (TileMap[i][j] == 'S') {

				child.push_back(new Girl(j, i));// возвращаем из контейнера ребенка - девочка
			}

			//СТРЕЛКИ
			if (TileMap[i][j] == 'P') {

				shoott.push_back(new Shoot(j, i)); // возвращаем из контейнера пулю
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

	m.drawing(); //рисуется карта (пока окно открыто)
	z.draw_p(); //рисуется игрок

	return 0;
}

