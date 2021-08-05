#include "Scores.h"
#include <SFML/Window/Mouse.hpp>
#include "Menu.h"
#include "Game.h"
#include <fstream>
#include <SFML/Window/Keyboard.hpp>
using namespace std;

Scores::Scores() {
	t_music.openFromFile("Music/score.ogg");
	t_music.setLoop(true);
	t_music.play();
	
	tex1.loadFromFile("Textures/backgroundscores.jpeg");
	background.setTexture(tex1);
	background.setScale(0.8,0.8);
	background.setPosition(-250,1);
	
	texbb.loadFromFile("Textures/buttonback.png");
	buttonback.setTexture(texbb);
	buttonback.setPosition(20,20);
	buttonback.setScale(0.1,0.1);
	
	f1.loadFromFile("Fonts/neuropolxrg.ttf");
	tx1.setFont(f1);
	tx1.setFillColor({255,255,255});
	tx1.setCharacterSize(30);
	
	tx2.setFont(f1);
	tx2.setFillColor({255,255,255});
	tx2.setCharacterSize(40);
	tx2.setPosition(100,50);
	tx2.setString("High scores");
	loadscores();
	
}

void Scores::Update (Game & g, RenderWindow & win) {
	Vector2f mouse = win.mapPixelToCoords(Mouse::getPosition(win));
	FloatRect boundsback = buttonback.getGlobalBounds();
	if(boundsback.contains(mouse)){
		if(Mouse::isButtonPressed(Mouse::Left)){
			t_music.stop();
			g.SetScene(new Menu());
		}
	}
}

void Scores::Draw (RenderWindow & win) {
	win.clear({0,0,0});
	win.draw(background);
	win.draw(tx2);
	for(size_t i=0; i<v.size(); ++i){
	win.draw(v[i]);}
	win.draw(buttonback);
	win.display();
}

void Scores::loadscores ( ) {
	ifstream f("scoretxt.txt");
	int aux;
	vector<int> auxvect;
	while(f>>aux){
		auxvect.push_back(aux);
	}
	sort(auxvect.begin(),auxvect.end());
	reverse(auxvect.begin(),auxvect.end());
	for(size_t i=0;i<5;++i){
		string auxs=to_string(auxvect[i]);
		tx1.setString(auxs);
		v.push_back(tx1);
		v[i].setPosition(100,posinit);
		posinit=posinit+30;
	}
}

