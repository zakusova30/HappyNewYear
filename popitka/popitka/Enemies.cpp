#include "SFML/Graphics.hpp" 
#include <iostream> 
#include "Map.h" 
#include "Globals.h" 
#include "Enemies.h"
#include "Player.h"  

void Child_Enemies::checkCollisionWithMap()
{
	for (int i = (rect.top) / 32; i < (rect.top + 32) / 32; i++)
		for (int j = (rect.left) / 32; j < (rect.left + 32) / 32; j++)
		{
			if (TileMap[i][j] == '0' || TileMap[i][j] == '1' || TileMap[i][j] == 'e' || TileMap[i][j] == 'y' || TileMap[i][j] == 'w' || TileMap[i][j] == 'm')
			{
				if (dx > 0) { rect.left = j * 32 - 32; }
				if (dx < 0) { rect.left = j * 32 + 32; }
				dx = dx * -1;
				if (dy > 0) { rect.top = i * 32 - 32; }
				if (dy < 0) { rect.top = i * 32 + 32; }
				dy = dy * -1;
			}
		}
}

void Child_Enemies::drawing(float pX, float pY, Player & playerhp)
{
	time = clock.getElapsedTime().asMicroseconds();
	clock.restart();

	time = time / 800;


	sprite.setPosition(rect.left, rect.top);

	rect.left = rect.left + dx * time;
	rect.top = rect.top + dy * time;
	CurrentFrame += 0.005 * time;
	if (CurrentFrame > 3) CurrentFrame -= 3;
	if (dx < 0) sprite.setTextureRect(IntRect(32 * int(CurrentFrame) + 0, 32, 32, 32));
	if (dx > 0) sprite.setTextureRect(IntRect(32 * int(CurrentFrame) + 0, 64, 32, 32));
	if (dy < 0) sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 64, 32, 32));
	if (dy > 0) sprite.setTextureRect(IntRect(32 * int(CurrentFrame) + 32, 32, -32, 32));
	window.draw(sprite);

	if ((pY >= (rect.top - 15)) && (pY <= (rect.top + 32 + 15)) && (pX >= (rect.left - 15) && (pX <= (rect.left + 32 + 15)))) {
		playerhp.Damage();
	}
}

Girl::Girl(int x, int y)
{
	t.loadFromFile("images/girl.png");
	sprite.setTexture(t);
	sprite.setTextureRect(IntRect(0, 0, 23, 23));
	rect = FloatRect(x * 32, y * 32, 0, 0);
	dx = -0.05;
}

Boy::Boy(int x, int y) 
{
	t.loadFromFile("images/boy.png");
	sprite.setTexture(t);
	sprite.setTextureRect(IntRect(0, 0, 23, 23));
	rect = FloatRect(x * 32, y * 32, 0, 0);
	dy = -0.08;
}