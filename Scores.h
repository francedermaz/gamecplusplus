#ifndef SCORES_H
#define SCORES_H
#include "Scene.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <vector>
#include <SFML/Audio/Music.hpp>
using namespace std;

class Scores : public Scene {
public:
	Scores();
	void Update (Game & g, RenderWindow & win);
	void Draw (RenderWindow & win);
	void loadscores();
private:
	Texture tex1, texbb;
	Sprite background, buttonback;
	Font f1;
	Text tx1,tx2;
	Music t_music;
	vector<Text> v;
	int i=0, posinit=110;
};

#endif

