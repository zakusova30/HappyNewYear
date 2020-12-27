#include "SFML/Graphics.hpp" 
#include <iostream> 
#include "Map.h" 
#include "Globals.h" 
#include "Enemies.h"
#include "Player.h"  

void Child_Enemies::checkCollisionWithMap()
{

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
}

Girl::Girl(int x, int y)
{

}

Boy::Boy(int x, int y) 
{

}