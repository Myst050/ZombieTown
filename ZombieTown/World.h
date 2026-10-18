#include "Raylib.h"

struct World {
	int width;
	int height;
	Texture2D texture;
	void init(int w, int h);
	void unload() const;
	void draw() const;
};