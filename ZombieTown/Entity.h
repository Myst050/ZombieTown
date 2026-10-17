#include "Raylib.h"

struct Entity {
	Vector2 position;
	Texture2D texture;
	bool isAlive;
	bool isZombie;
	int health;
	int speed;
	void Move(int bx, int by);
	float calculateDistance(Vector2 c_pos, Vector2 n_pos);
	Vector2 calculateDirection(Vector2 c_pos, Vector2 n_pos);
	void draw();
	void takeDamage(int damage);
};