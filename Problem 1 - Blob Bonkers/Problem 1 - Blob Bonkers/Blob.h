#ifndef _BLOB_H_
#define _BLOB_H_

#include "Box2d.h"
using namespace std;

class Blob{
private:
	//bVec2 m_position;
	//bVec2 m_velocity;

public:
	Blob();
	~Blob();

	void Update(); //Should be passed gametime

	//Getters and setters
	bVec2 getPosition();
	bVec2 getVelocity();

	void setPosition(bVec2);
	void setVelocity(bVec2);
};
#endif // !_BLOB_H_