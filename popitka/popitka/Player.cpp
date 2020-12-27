#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "globals.h"
#include <iostream>
#include "Map.h"
using namespace sf;

Player::Player()
{
	File;
	w = W; h = H;
	imagee.loadFromFile("images/" + File);
	texturee.loadFromImage(imagee);

	sprite.setTexture(texturee);
	x = X; y = Y;
	sprite.setTextureRect(IntRect(0, 0, w, h));
	sprite.setOrigin(w / 2, h / 2);

	dx = 0;
	dy = 0;
	speed = 0;
	dir = 0;
	key = 0,00001;
	hp = 200;
	win = 0;
	hpbar.setFillColor(Color::Red);
	hpbar.setPosition(128, 10.f);
	hpbar.setSize(Vector2f((float)hp * 1.f, 10.f));

	keybar.setFillColor(Color::Yellow);
	keybar.setPosition(900, 10.f);
	keybar.setSize(Vector2f((float)key * 10.f, 10.f));

	CurrentFrame = 0;
	Clock clock;
}

Player::~Player()
{
}

Player::Player(String File, float X, float Y, float W, float H)
{
}

void Player::update(float time)
{
	switch (dir)
	{
	case 0: dx = speed; dy = 0;   break;
	case 1: dx = -speed; dy = 0;   break;
	case 2: dx = 0; dy = speed;   break;
	case 3: dx = 0; dy = -speed;   break;
	}

	x += dx * time;
	y += dy * time;


	speed = 0;
	sprite.setPosition(x, y);
	hpbar.setSize(Vector2f((float)hp * 1.f, 10.f));
	keybar.setSize(Vector2f((float)key * 70.f, 10.f));
}

void Player::draw_p() 
{
}

void Player::InteractionWithMap()
{
}

float Player::GetPlayerCoordinateX() 
{
	return x;
}

float Player::GetPlayerCoordinateY() {
	return y;
}

void Player::Damage() 
{
	hp--;
	return;
}

void Player::bDamage() 
{
	hp -= 20;
	return;
}

void Player::Keys() 
{
	key++;
	return;
}
