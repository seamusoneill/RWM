#ifndef _BLOB_H_
#define _BLOB_H_

#include "Box2D/Box2D.h"
using namespace std;

class Blob{
private:
	b2Vec2 m_position;
	b2Vec2 m_velocity;

public:
	Blob();
	~Blob();

	void Initialize();
	void Update(); //Should be passed gametime
	
	//Getters and setters
	b2Vec2 getPosition();
	b2Vec2 getVelocity();

	void setPosition(b2Vec2);
	void setVelocity(b2Vec2);
};
#endif // !_BLOB_H_