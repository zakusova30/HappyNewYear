#include "SFML/Graphics.hpp" 
#include <iostream> 
#include "map.h" 
#include "globals.h" 
#include "Enemys.h" 
#include "player.h" 
#include "Shooting.h"

// конструктор стрелка
Shoot::Shoot(int x, int y) { 
	t.loadFromFile("images/evil.png");
	sprite.setTexture(t); 
	sprite.setTextureRect(IntRect(0, 0, 38, 38)); 
	rect = FloatRect(x * 32, y * 32, 0, 0); 
	dx = 0;
}

void Shooting::draw()
{
	sprite.setPosition(rect.left, rect.top); 
	window.draw(sprite);
}

FloatRect Shooting::position() {
	return rect;
}
float Shooting::acceleration() { 
	return dx;
}

//конструктор пули
Shooting::Bullet::Bullet(FloatRect polozh, float uskor) { 
	bullet_rect = polozh;
	life = true;
	im.loadFromFile("images/pula.png");
	sprite.setTextureRect(IntRect(0, 0, 23, 23));
	t.loadFromImage(im);
	sprite.setTexture(t);
	dx = -0.1;
}

//движение пули
void Shooting::Bullet::drawing() {

	time = clock.getElapsedTime().asMicroseconds();
	clock.restart();

	time = time / 400;

	sprite.setPosition(bullet_rect.left, bullet_rect.top);
	bullet_rect.left = bullet_rect.left + dx * time;

	WithMap();

	window.draw(sprite);
}

//пуля попала в стену
void Shooting::Bullet::WithMap() {

	for (int i = (bullet_rect.top) / 32; i < (bullet_rect.top + 32) / 32; i++)
		for (int j = (bullet_rect.left) / 32; j < (bullet_rect.left + 32) / 32; j++)
		{
			if (TileMap[i][j] == '0' || TileMap[i][j] == 'e' || TileMap[i][j] == '1')
			{
				life = false;
			}
		}

}


Shooting::Bullet::~Bullet() {

}