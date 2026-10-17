// ZombieTown.cpp : Defines the entry point for the application.
//
#include "ZombieTown.h"
#include "Raylib.h"
#include "Entity.h"

using namespace std;

int main()
{
	
	InitWindow(800, 600, "ZombieTown");
	Entity human = { { 100, 100 }, LoadTexture("C:/Users/mahee/source/repos/ZombieTown/Assets/Human.png"), true, false, 100, 150 };
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(GREEN);
		human.Move(800, 600);
		human.draw();
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
	