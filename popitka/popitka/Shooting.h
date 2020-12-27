#pragma once
#include "SFML/Graphics.hpp" 
#include <iostream> 
#include "player.h" 


using namespace sf;

// ������� ������
class Shooting {
public:

	FloatRect rect;
	void draw();

	//���������
	FloatRect position();
	float x, y;

	//���������
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

	//����
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

		void WithMap();//�������� ������� �������� �� ��������� � ����� 
		void WithPlayer(Player &p);//�������� ������� �������� �� ��������� � ������

		void drawing();

	};


};

//�������
class Shoot : public Shooting {
public:

	Shoot(int x, int y);// �����������

};