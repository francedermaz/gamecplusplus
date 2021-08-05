#include "Match.h"
#include "Game.h"
#include "Menu.h"
#include <fstream>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Window/Event.hpp>
using namespace std;

Match::Match() {
	t_music2.openFromFile("Music/match.ogg");
	t_music2.setLoop(true);
	t_music2.play();
	tex1.loadFromFile("Textures/background.png");
	background.setTexture(tex1);
	background.setScale(3.9,3.9);
	background.setPosition(-5,-1050);
	
	f1.loadFromFile("Fonts/neuropolxrg.ttf");
	txtlost.setFont(f1);
	scoretxt.setFont(f1);
	secs.setFont(f1);
	secs.setScale(1,1);
	scoretxt.setScale(1,1);
	highscore.setFont(f1);
	highscore.setCharacterSize(40);
}

void Match::Update (Game &g,RenderWindow &win) {
	Time time1=clock1.getElapsedTime();
	int sec = time1.asSeconds();  //clock
	string secaux=to_string(sec);
	secs.setString(secaux);
	
	View player_view(FloatRect(300, 400, win.getSize().x, win.getSize().y));  //camera
	p1.Update();
	if(Keyboard::isKeyPressed(Keyboard::Key::Escape)){
		t_music2.stop();
		g.SetScene(new Menu());
	}
	if(p1.checkpos()){
		player_view.setCenter(p1.getPositionX()+500,p1.getPositionY());
		secs.setPosition(p1.getPositionX()+500,p1.getPositionY()-300);  //+ view
	}
	if(p1.checkpos()==false){
		player_view.setCenter(p1.getPositionX()-140,p1.getPositionY());
		secs.setPosition(p1.getPositionX()-160,p1.getPositionY()-300);  //- view
	}
	win.setView(player_view);
	
	d1.Update(p1.getPositionX(),p1.getPositionY(),cont,p1.checkpos());
	
	if(d1.CollideWith(p1)){
		t_music2.stop();
		t_music2.openFromFile("Music/collide.ogg");
		t_music2.play();
		txtlost.setString("You lost! Press Esc to exit");
		txtlost.setScale(1,1);
		
		Time timescore=clock1.getElapsedTime();
		score=timescore.asSeconds();
		
		if(checkscore(score)){
			highscore.setString("New Highscore!");
			savescore(score);
		}
		string aux=to_string(score);
		scoretxt.setString("Score: " + secaux);
		
		if(p1.checkpos()){
			txtlost.setPosition(p1.getPositionX()+250,p1.getPositionY()+200);
			scoretxt.setPosition(p1.getPositionX()+250,p1.getPositionY()+260);
			highscore.setPosition(p1.getPositionX()+300,p1.getPositionY()-200);
		}
		else{
			txtlost.setPosition(p1.getPositionX()-350,p1.getPositionY()+200);
			scoretxt.setPosition(p1.getPositionX()-350,p1.getPositionY()+260);
			highscore.setPosition(p1.getPositionX()-350,p1.getPositionY()+260);
		}
		Draw(win);
		
		clock1.restart();
		time1=clock1.getElapsedTime();  //timer
		int t=time1.asSeconds();
		while(t!=5){
			if(Keyboard::isKeyPressed(Keyboard::Key::Escape)){
			break;
			}
			time1=clock1.getElapsedTime();
			t=time1.asSeconds();
		}
		t_music2.stop();
		g.SetScene(new Menu());
	}
	++cont;
	}

void Match::Draw (RenderWindow & win) {
	win.clear(Color(0,0,0));
	win.draw(background);
	win.draw(txtlost);
	win.draw(secs);
	win.draw(scoretxt);
	win.draw(highscore);
	d1.Draw(win);
	p1.Draw(win);
	win.display();
}

void Match::savescore (int score) {
	for(size_t i=0;i<5;++i){
		if(score>v[i]){
			v.push_back(score);
			sort(v.begin(),v.end());
			reverse(v.begin(),v.end());
			v.pop_back();
			break;
		}
	}
	ofstream f("scoretxt.txt");
	for(size_t i=0;i<5;++i){
		f << v[i] << endl;
	}
	f.close();
}

bool Match::checkscore(int score){
	int aux;
	ifstream f("scoretxt.txt");
	while(f>>aux){
		v.push_back(aux);
	}
	f.close();
	
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	for(size_t i=0;i<5;++i){
		if(score>v[i] || score==v[i]){
			return true;
		}
	}
	return false;
}
