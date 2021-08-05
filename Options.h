#ifndef OPTIONS_H
#define OPTIONS_H
#include "Scene.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Audio/Music.hpp>

class Options : public Scene {
public:
	Options();
	void Update (Game &g, RenderWindow & win);
	void Draw (RenderWindow & win);
private:
	Texture tex1,texbb,teximagef;
	Text tx1, tx2, tx3;
	Font f1;
	Sprite background,buttonback,imagef;
	Music t_music;
};

#endif

