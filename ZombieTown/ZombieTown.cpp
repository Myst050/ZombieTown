// ZombieTown.cpp : Defines the entry point for the application.
//
#include "ZombieTown.h"
#include "Raylib.h"
#include "Entity.h"
#include "World.h"
#include "EntityManager.h"

#include <vector>

using namespace std;

int main()
{

	InitWindow(800, 600, "ZombieTown");

	EntityManager entityManager;

	int screenWidth = GetScreenWidth();
	int screenHeight = GetScreenHeight();

	World world = { screenWidth, screenHeight };
	world.init(screenWidth, screenHeight);

	for (int i = 0; i < 10000; i++) {
		Texture2D texture = LoadTexture("C:/Users/mahee/source/repos/ZombieTown/Assets/Human.png");
		Entity entity = {{(float)screenWidth / 2, (float)screenHeight / 2}, texture, true, false, 100, 150, {0, 0}};

		entityManager.addEntity(entity);
	}

	size_t c_pop = entityManager.getCurrentPopulationInformation();
	cout << "Current population: " << c_pop << endl;


	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		world.draw();
		entityManager.update(screenWidth, screenHeight);
		entityManager.draw();
		EndDrawing();
	}
	world.unload();
	CloseWindow();
	return 0;
}
	