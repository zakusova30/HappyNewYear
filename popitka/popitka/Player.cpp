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

}

Player::~Player()
{
}

Player::Player(String File, float X, float Y, float W, float H)
{
}

void Player::update(float time)
{
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
}

void Player::bDamage() 
{
}

void Player::Keys() 
{
}
