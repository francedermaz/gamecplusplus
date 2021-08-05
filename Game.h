#ifndef GAME_H
#define GAME_H
#include "Scene.h"
#include <SFML/Graphics/RenderWindow.hpp>

using namespace sf;

class Game {
public:
	Game();
	void Run();
	void ProcessEvents();
	void Update(RenderWindow &win);
	void Draw();
	void SetScene(Scene *m_n_scene);
private:
	RenderWindow win;
	Scene *t_scene;
	Scene *t_n_scene=nullptr;
};

#endif

