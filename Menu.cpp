#include "Menu.h"
#include "Game.h"
#include "Match.h"
#include <SFML/Window/Mouse.hpp>
#include "Options.h"
#include "Scores.h"
using namespace sf;

Menu::Menu() {
	tex1.loadFromFile("Textures/background2.jpg");
	background.setTexture(tex1);
	
	texb.loadFromFile("Textures/button.png");
	button1.setTexture(texb);
	button1.setScale(0.3,0.25);
	button2.setTexture(texb);
	button2.setScale(0.3,0.25);
	button3.setTexture(texb);
	button3.setScale(0.3,0.25);
	
	button1.setPosition(370,590);
	button2.setPosition(370,520);
	button3.setPosition(370,450);
	
	ft1.loadFromFile("Fonts/neuropolxrg.ttf");
	tx1.setFont(ft1);
	tx2.setFont(ft1);
	tx3.setFont(ft1);
	
	tx1.setString("Start");
	tx1.setFillColor({0,0,0});
	tx1.setPosition(465,460);
	tx1.setCharacterSize(30);
	
	tx2.setString("Scores");
	tx2.setFillColor({0,0,0});
	tx2.setPosition(440,530);
	tx2.setCharacterSize(30);
	
	tx3.setString("About");
	tx3.setFillColor({0,0,0});
	tx3.setPosition(445,600);
	tx3.setCharacterSize(30);
	

	t_music.openFromFile("Music/menufinal.ogg");
	t_music.setLoop(true);
	t_music.play();
}

void Menu::Update (Game & g,RenderWindow &win) {
	win.setView(win.getDefaultView());
	Vector2f mouse = win.mapPixelToCoords(Mouse::getPosition(win));
	FloatRect bounds3 = button3.getGlobalBounds();
	FloatRect bounds2 = button2.getGlobalBounds();
	FloatRect bounds1 = button1.getGlobalBounds();
	if(bounds3.contains(mouse)){
		tx1.setStyle(Text::Bold);
		if(Mouse::isButtonPressed(Mouse::Left)){
		t_music.stop();
		g.SetScene(new Match());}}
	if(!bounds3.contains(mouse)) tx1.setStyle(Text::Regular);
	if(bounds2.contains(mouse)){
		tx2.setStyle(Text::Bold);
		if(Mouse::isButtonPressed(Mouse::Left)) {
			t_music.stop();
			g.SetScene(new Scores());
		}
	}
	if(!bounds2.contains(mouse)) tx2.setStyle(Text::Regular);
	if(bounds1.contains(mouse)){
		tx3.setStyle(Text::Bold);
		if(Mouse::isButtonPressed(Mouse::Left)){ 
			t_music.stop();
			g.SetScene(new Options());
		}
	}
	if(!bounds1.contains(mouse)) tx3.setStyle(Text::Regular);
}

void Menu::Draw (RenderWindow & win) {
	win.clear({0,0,0});
	win.draw(background);
	win.draw(button1);
	win.draw(button2);
	win.draw(button3);
	win.draw(tx1);
	win.draw(tx2);
	win.draw(tx3);
	win.display();
}

