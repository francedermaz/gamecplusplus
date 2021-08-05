#include "Object.h"
using namespace std;

Object::Object (string name) {
	tx2.loadFromFile(name);
	tx2.setSmooth(true);
	spr1.setTexture(tx2);
}

bool Object::CollideWith (const Object & obj) {
	auto o1 = this->spr1.getGlobalBounds();
	auto o2 = obj.spr1.getGlobalBounds();
	return o1.intersects(o2);
}

void Object::Draw (RenderWindow & win) {
	win.draw(spr1);
}

