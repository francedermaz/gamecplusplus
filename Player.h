#ifndef PLAYER_H
#define PLAYER_H
#include "Object.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>

using namespace sf;

class Player : public Object {
public:
	Player();
	void Update();
	void UpdateMovement();
	int getPositionX();
	int getPositionY();
	bool checkpos();
private:
	Keyboard::Key t_up, t_right, t_left;
	float x, y, velocityX, velocityY = 0;
	float accelerationX, accelerationY = 0;
	const float gravity = 2;
	int cont=1;
	Texture lefttex,righttex;
	const int limitrt=25500;
	const int limitlt=800;
};

#endif

