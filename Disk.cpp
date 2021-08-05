#include "Disk.h"

Disk::Disk() : Object("Textures/disk.png"){
	spr1.setScale(0.15,0.15);
}

void Disk::Update(int x, int y, int cont, bool v1){
	if(prim==1){
		if(v1==true){
			spr1.setPosition(x+1100,y);
		}
		if(v1==false){
			spr1.setPosition(x-1100,y);
		}
	}
	if(v1==true){
		spr1.move(speed);
		xspeed=xspeed-1;
	}
	if(v1==false){
		spr1.move(speedplus);
		xspeedplus=xspeedplus+1;
	}
	prim=0;
	if(cont%90==0){  //like a timer
	   prim=1;}
}
