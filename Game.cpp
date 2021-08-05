#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Menu.h"
using namespace sf;

Game::Game():win(VideoMode(1000,750),"TRON"){
	win.setFramerateLimit(60);
	t_scene = new Menu();
}

void Game::Run(){
	while(win.isOpen()) {
		ProcessEvents();
		Update(win);
		Draw();
		if (t_n_scene) {
			delete t_scene;
			t_scene = t_n_scene;
			t_n_scene = nullptr;
		}
	}
}

void Game::Update(RenderWindow &win){
	t_scene->Update(*this,win);
}

void Game::Draw(){
	t_scene->Draw(win);
}

void Game::ProcessEvents(){
	Event e;
	while(win.pollEvent(e)){
		if(e.type==Event::Closed){
			win.close();
		}
	}
}

void Game::SetScene(Scene *m_n_scene) {
	t_n_scene = m_n_scene;
}

