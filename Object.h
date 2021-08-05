#ifndef OBJECT_H
#define OBJECT_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;
using namespace std;

class Object {
public:
	Object(string name);
	bool CollideWith(const Object &obj);
	void Draw(RenderWindow &win);
protected:
	Texture tx2;
	Sprite spr1;
};

#endif

