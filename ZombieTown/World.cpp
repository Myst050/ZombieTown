#include "Raylib.h"
#include "World.h"

void World::init(int w, int h) {
	width = w;
	height = h;

	texture = LoadTexture("C:/Users/mahee/source/repos/ZombieTown/Assets/dry_grass.png");
}

void World::unload() const {
	UnloadTexture(texture);
}

void World::draw() const {
	Rectangle src = { 0.0f, 0.0f, (float)texture.width, (float)texture.height };
	Rectangle dest = { 0.0f, 0.0f, (float)width, (float)height };

	Vector2 origin = { 0.0f, 0.0f };
	DrawTexturePro(texture, src, dest, origin, 0.0f, WHITE);
}