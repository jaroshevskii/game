#include "Engine.h"

#include <iostream>
#include <raylib.h>

struct Window {
  int width;
  int height;
  const char *title;
};

int main() {
  Window window{840, 360, "Game"};

  InitWindow(window.width, window.height, window.title);
  SetTargetFPS(60);

  Vector2 ballPosition{window.width / 2.0f, window.height / 2.0f};

  float speed = 10.0f;

  while (!WindowShouldClose()) {
    if (IsKeyDown(KEY_RIGHT))
      ballPosition.x += speed;
    if (IsKeyDown(KEY_LEFT))
      ballPosition.x -= speed;
    if (IsKeyDown(KEY_UP))
      ballPosition.y -= speed;
    if (IsKeyDown(KEY_DOWN))
      ballPosition.y += speed;

    BeginDrawing();

    ClearBackground(BLANK);
    DrawCircleV(ballPosition, 50, MAROON);
    DrawRectangleV({ballPosition.x - 40, ballPosition.y - 10}, {80, 20}, WHITE);

    DrawFPS(10, 10);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}