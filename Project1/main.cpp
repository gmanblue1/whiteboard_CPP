#include <raylib.h>

struct Eye 
{
	float x, y;
	float speed;
	float radius;
	Color color;

	void Draw() 
	{
		DrawCircle(x, y, radius, color);
	}
};

int main()
{
	InitWindow(800, 600, "Whiteboard C++");
	SetWindowState(FLAG_VSYNC_HINT);
	SetTargetFPS(60);
	Eye leftEye;
	leftEye.speed = 1;
	leftEye.x = GetScreenWidth() / 2 - 50;
	leftEye.y = GetScreenHeight() / 2;
	leftEye.radius = 10;
	leftEye.color = BLUE;

	Eye rightEye;
	rightEye.speed = 1;
	rightEye.x = GetScreenWidth() / 2 + 50;
	rightEye.y = GetScreenHeight() / 2;
	rightEye.radius = 10;
	rightEye.color = BLUE;

	while (!WindowShouldClose())
	{
		if (IsKeyDown(KEY_W)) 
		{
			leftEye.y -= 1 * leftEye.speed;
		}
		if (IsKeyDown(KEY_A))
		{
			leftEye.x -= 1 * leftEye.speed;
		}
		if (IsKeyDown(KEY_S))
		{
			leftEye.y += 1 * leftEye.speed;
		}
		if (IsKeyDown(KEY_D))
		{
			leftEye.x += 1 * leftEye.speed;
		}
		if (IsKeyDown(KEY_I))
		{
			rightEye.y -= 1 * rightEye.speed;
		}
		if (IsKeyDown(KEY_J))
		{
			rightEye.x -= 1 * rightEye.speed;
		}
		if (IsKeyDown(KEY_K))
		{
			rightEye.y += 1 * rightEye.speed;
		}
		if (IsKeyDown(KEY_L))
		{
			rightEye.x += 1 * rightEye.speed;
		}
		
		if (IsKeyDown(KEY_LEFT_SHIFT)) 
		{
			leftEye.speed *= 1.0009;
		}
		if (IsKeyDown(KEY_RIGHT_SHIFT))
		{
			rightEye.speed *= 1.0009;
		}

		BeginDrawing();
		leftEye.Draw();
		rightEye.Draw();

		if (IsKeyDown(KEY_SPACE))
		{
			ClearBackground(BLACK);
		}

		if (IsKeyDown(KEY_ONE)) 
		{
			leftEye.color = BLUE;
		}
		if (IsKeyDown(KEY_TWO))
		{
			leftEye.color = RED;
		}
		if (IsKeyDown(KEY_THREE))
		{
			leftEye.color = GREEN;
		}
		if (IsKeyDown(KEY_FOUR))
		{
			leftEye.color = YELLOW;
		}
		if (IsKeyDown(KEY_FIVE))
		{
			leftEye.color = PURPLE;
		}
		if (IsKeyDown(KEY_SIX))
		{
			rightEye.color = BLUE;
		}
		if (IsKeyDown(KEY_SEVEN))
		{
			rightEye.color = RED;
		}
		if (IsKeyDown(KEY_EIGHT))
		{
			rightEye.color = GREEN;
		}
		if (IsKeyDown(KEY_NINE))
		{
			rightEye.color = YELLOW;
		}
		if (IsKeyDown(KEY_ZERO))
		{
			rightEye.color = PURPLE;
		}
		DrawText("WASD for left marker, IJKL for right marker", 100, 10, 25, WHITE);
		DrawText("SPACE to clear or Show FPS", 200, 35, 25, WHITE);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}