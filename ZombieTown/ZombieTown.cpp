// ZombieTown.cpp : Defines the entry point for the application.
//

#include "ZombieTown.h"
#include "Raylib.h"

using namespace std;

int main()
{
	InitWindow(800, 600, "ZombieTown");
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
	