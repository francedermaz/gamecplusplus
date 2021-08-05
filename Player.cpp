#include "Player.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
using namespace std;
using namespace sf;

Player::Player() : Object("Textures/ponytron.png"){
	spr1.setScale(0.07,0.07);
	spr1.setPosition(50,300);
	lefttex.loadFromFile("Textures/ponytronback.png");
	righttex.loadFromFile("Textures/ponytron.png");
	t_up = Keyboard::Key::Up;
	t_right = Keyboard::Key::Right;
	t_left = Keyboard::Key::Left;
}

void Player::Update ( ) {
	if(Keyboard::isKeyPressed(t_up)){
		if(y<-600){
			velocityY = +10;
		}
		else{
			velocityY = -10;
		}
	}

	if(Keyboard::isKeyPressed(t_right)){
		if(x<limitrt && cont!=0){
		velocityX = 13;
		}
	}
	if(!Keyboard::isKeyPressed(t_right)){
		if(x<limitrt && cont!=0){
			velocityX = 8;
		}
	}
	if(Keyboard::isKeyPressed(t_left)){
		if(x>=25500){
			velocityX = -13;
		}
	}
	if(!Keyboard::isKeyPressed(t_left)){
		if(x>=25500){
			velocityX = -8;
		}
	}
	
	if(x>=25500){
		cont=0;
		velocityX = -8;
		spr1.setTexture(lefttex);
	}
	if(x<800){
		velocityX = +8;
		cont=1;
		spr1.setTexture(righttex);
	}
	UpdateMovement();
	spr1.setPosition(x,y);
}

void Player::UpdateMovement ( ) {
	if(y<400){
		velocityY += gravity; //gravity system
	}
	else if(y>400)
		y=400;  //ground
	velocityX += accelerationX;
	velocityY += accelerationY;
	x += velocityX;
	y += velocityY;
}

int Player::getPositionX ( ) {
	return x;
}

int Player::getPositionY ( ) {
	return y;
}

bool Player::checkpos ( ) {
	if(cont!=1) return false;  //pposition of the player + or -
	else return true;
}

