#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

#include <Box2D\Box2D.h>

class Projectile{
private:
	b2Vec2 m_position;
	b2Vec2 m_velocity;

public:
	Projectile();
	~Projectile();

	void Initialize();
	void Update();

	//Getters and Setters
	b2Vec2 getPosition();
	b2Vec2 getVelocity();

	void setPosition(b2Vec2);
	void setVelocity(b2Vec2);
};
#endif