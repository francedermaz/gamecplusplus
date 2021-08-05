#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include "Scene.h"
#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics/Sprite.hpp>
using namespace sf;

class Menu : public Scene {
public:
	Menu();
	void Update (Game & g,RenderWindow &win);
	void Draw (RenderWindow & win);
private:
	Texture tex1,texb;
	Font ft1;
	Text tx1,tx2,tx3;
	Music t_music;
	Sprite background,button1,button2,button3;
};

#endif

