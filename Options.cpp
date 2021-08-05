#include "Options.h"
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Game.h"
#include "Menu.h"
#include <SFML/Window/Event.hpp>

Options::Options() {
	t_music.openFromFile("Music/options.ogg");
	t_music.setLoop(true);
	t_music.play();
	
	tex1.loadFromFile("Textures/backgroundoptions.jpeg");
	background.setTexture(tex1);
	background.setScale(0.85,0.85);
	
	f1.loadFromFile("Fonts/neuropolxrg.ttf");
	tx1.setFont(f1);
	tx2.setFont(f1);
	tx3.setFont(f1);
	
	tx1.setString("How to play:");
	tx1.setPosition(100,150);
	tx1.setCharacterSize(40);
	
	tx2.setString("Avoid the disks to win!");
	tx2.setPosition(150,230);
	
	tx3.setString("Game developed by Cedermaz Francisco Agustin");
	tx3.setPosition(110,650);
	tx3.setCharacterSize(22);
	
	
	teximagef.loadFromFile("Textures/imagescore.png");
	imagef.setTexture(teximagef);
	imagef.setScale(1,1);
	imagef.setPosition(530,30);
	
	texbb.loadFromFile("Textures/buttonback.png");
	buttonback.setTexture(texbb);
	buttonback.setPosition(20,20);
	buttonback.setScale(0.1,0.1);
}

void Options::Update (Game &g, RenderWindow & win) {
	Vector2f mouse = win.mapPixelToCoords(Mouse::getPosition(win));
	FloatRect boundsback = buttonback.getGlobalBounds();
	if(boundsback.contains(mouse)){
		if(Mouse::isButtonPressed(Mouse::Left)){
			t_music.stop();
			g.SetScene(new Menu());
		}
	}
}

void Options::Draw (RenderWindow & win) {
	win.clear({0,0,0});
	win.draw(background);
	win.draw(tx1);
	win.draw(tx2);
	win.draw(tx3);
	win.draw(imagef);
	win.draw(buttonback);
	win.display();
}

