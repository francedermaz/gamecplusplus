#ifndef DISK_H
#define DISK_H
#include "Object.h"

class Disk : public Object {
public:
	Disk();
	void Update(int x, int y, int cont, bool v1);
private:
	int prim = 1;
	float xspeed=-9.0,xspeedplus=9.0;
	Vector2f speed = {xspeed,0};
	Vector2f speedplus = {xspeedplus,0};
};

#endif

