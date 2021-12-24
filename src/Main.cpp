#include "Engine.h"

#include <iostream>
#include <raylib.h>

struct Window {
  int width;
  int height;
  const char *title;
};

int main() {
  Window window{640, 270, "Game"};

  InitWindow(window.width, window.height, window.title);
  SetTargetFPS(60);

  Vector2 position{304.0f, 119.0f};

  float speed;

  while (!WindowShouldClose()) {
    speed = 5.0f;

    std::cout << "x: " << position.x << " y: " << position.y << '\n';

    if (IsKeyDown(KEY_LEFT_SHIFT))
      speed *= 2.0f;
    if (IsKeyDown(KEY_RIGHT))
      position.x += speed;
    if (IsKeyDown(KEY_LEFT))
      position.x -= speed;
    if (IsKeyDown(KEY_UP))
      position.y -= speed;
    if (IsKeyDown(KEY_DOWN))
      position.y += speed;

    BeginDrawing();
    ClearBackground(BLANK);

    //DrawCircleV(ballPosition, 50, MAROON);
    DrawRectangleV({position.x, position.y}, {32, 32}, MAGENTA);

    DrawFPS(10, 10);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}