#ifndef MATCH_H
#define MATCH_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Disk.h"
#include "Player.h"
#include "Scene.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <vector>
using namespace std;
using namespace sf;

class Match : public Scene {
public:
	Match();
	void Update (Game &g,RenderWindow &win);
	void Draw (RenderWindow & win);
	void savescore(int score);
	bool checkscore(int score);
private:
	Music t_music2;
	Player p1;
	Disk d1;
	Font f1;
	Texture tex1;
	Sprite background;
	Text txtlost,secs,scoretxt,highscore;
	int score;
	int cont=0;
	Clock clock1;
	vector<int> v;
};

#endif

