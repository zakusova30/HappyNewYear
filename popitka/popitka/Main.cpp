#include <iostream>
#include <SFML/Graphics.hpp> /// подключаем заголовочный файл, который отвечает за работу с графикой
#include "map.h"
#include "globals.h"
#include "player.h"
#include "Enemies.h"
#include <list>
#include "Shooting.h"

using namespace std;
using namespace sf;

void winner(RenderWindow & window) // пояление окна победителя
{
	Texture winning_screen;
	winning_screen.loadFromFile("images/win.png"); // загружаем изображение 
	Sprite winscreen(winning_screen);
	winscreen.setPosition(32, 32);

	window.draw(winscreen);
	window.display(); // выводим на экран
}


void lose(RenderWindow & window)  // появление окна проигравшего
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


	Font font;  // шрифт
	font.loadFromFile("Ben_Krush.ttf");
	Text text("", font, 20); // размер текста
	text.setStyle(sf::Text::Bold); // стиль текста

	while (window.isOpen()) // пока окно отрыто
	{
		if (z.win >= 1) //в случае победы появляется окно победы
		{
			window.close();
			RenderWindow window(sf::VideoMode(789, 514), "WIN");
			winner(window);
			while (!Mouse::isButtonPressed(Mouse::Right));
		}
		if (z.hp <= 0) // в случае проигрыша появляется окно  проигрыша
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


		m.drawing(); //рисуется карта (пока окно открыто)
		z.draw_p(); //рисуется игрок

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
			(*shh)->shoot++; //новые пули вылетают
		}

		for (bul = bullets.begin(); bul != bullets.end(); bul++) {
			if ((*bul)->life) {

				(*bul)->WithPlayer(z); //взаимодействие пуль с игроком
				(*bul)->drawing();
			}
			else {
				delete((*bul)); //пуля удаляется ударяясь об стену, взамен выходит новая
				bullets.remove(*bul);
				break;
			}
		}






		text.setString("ЗДОРОВЬЕ:");
		text.setPosition(5, 0);
		window.draw(text);
		window.draw(z.hpbar);


		text.setString("КЛЮЧИ:");
		text.setPosition(800, 0);
		window.draw(text);
		window.draw(z.keybar);
		window.display();


	}

	return 0;
}

