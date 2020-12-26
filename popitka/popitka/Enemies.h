#pragma once 
#include "SFML/Graphics.hpp" 
#include <iostream> 
#include "Player.h" 

using namespace sf;

class Child_Enemies {
public:

	FloatRect rect;
	void checkCollisionWithMap();
	void drawing(float pX, float pY, Player & playerhp);
	float dx, dy;
	float x, y;
	int w, h;
	float speed;
	Image image;
	float time;
	Texture t;
	Sprite sprite;
	Sprite* ptr_sprite;
	float CurrentFrame;

	Clock clock;




};


class Boy : public Child_Enemies {
public:

	Boy(int x, int y);

};

class Girl : public Child_Enemies {
public:

	Girl(int x, int y);

};