#pragma once
#include "SFML/Graphics.hpp" 
#include <iostream> 
#include "player.h" 


using namespace sf;

// обстрел пулями
class Shooting {
public:

	FloatRect rect;
	void draw();

	//Положение
	FloatRect position();
	float x, y;

	//Ускорение
	float acceleration();
	float dx, dy;

	Image image;

	int w, h;
	float speed;
	float time;
	Texture t;
	Sprite sprite;
	float CurrentFrame;
	Clock clock;
	int shoot = 0;

	//Пули
	class Bullet {
	public:

		bool life;
		Clock clock;
		float time;
		FloatRect bullet_rect;
		Image im;
		Texture t;
		Sprite sprite;

		int direction;
		float dx, dy;

		Bullet(FloatRect rect, float loc_dx);		
		~Bullet();

		void WithMap();//прототип функции проверки на попадание в стену 
		void WithPlayer(Player &p);//прототип функции проверки на попадание в игрока

		void drawing();

	};


};

//стрелок
class Shoot : public Shooting {
public:

	Shoot(int x, int y);// конструктор

};