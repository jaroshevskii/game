#include "Engine.h"

#include <iostream>
#include <raylib.h>

struct Window {
  int width;
  int height;
  const char *title;
};

int main() {
  Window window{0 /*640*/, 0 /*360*/, "Game"};
  
  SetConfigFlags(FLAG_WINDOW_UNDECORATED | FLAG_WINDOW_TRANSPARENT | FLAG_FULLSCREEN_MODE);
  InitWindow(window.width, window.height, window.title);

  SetTargetFPS(60);

  Texture2D texture = LoadTexture("../res/Andersay.png");

  const Vector2 startPosition{0.0f /*(window.width - texture.width) * 0.5f*/,
                              0.0f /*(window.height - texture.height) * 0.5f*/};
  Vector2 position{startPosition};

  float speed;
  
  InitAudioDevice();
  Music music = LoadMusicStream("../res/Music.mp3");
  PlayMusicStream(music);

  while (!WindowShouldClose()) {
    UpdateMusicStream(music);

    speed = 5.0f;
    
    if (position.y != 695.0f)
      position.y += 5.0f;
    
    if (position.y > 800.0f)
      position.y = -100.0f;

    // std::cout << "x: " << position.x << " y: " << position.y << '\n';
    if (IsKeyPressed(KEY_SPACE))
      position.y -= 100.0f;
    if (IsKeyPressed(KEY_R))
      position = startPosition;
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

    // DrawCircleV(position, ballRadius, RED);

    // DrawRectangleV({position.x, position.y}, {32, 32}, MAGENTA);

    DrawTexture(texture, position.x, position.y, RAYWHITE);
    DrawText("I`m a Andersay!", position.x + 36, position.y - 0, 10, RAYWHITE);

    DrawFPS(10, 10);
    EndDrawing();
  }
  UnloadMusicStream(music);
  UnloadTexture(texture);
  CloseWindow();
  return 0;
}
