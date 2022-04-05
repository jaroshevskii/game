#include "Engine.h"

#include <iostream>
#include <raylib.h>
#include <raymath.h>

struct Window {
  int width;
  int height;
  const char *title;
};

enum class Player { Left, Right };

int main() {
  Window window{640, 360, "Game"};

  InitWindow(window.width, window.height, window.title);

  // GetFPS();

  SetTargetFPS(60);

  Player player = Player::Right;

  Texture2D textureDefaultRight = LoadTexture("../res/SpriteDefaultRight.png");
  Texture2D textureDefaultLeft = LoadTexture("../res/SpriteDefaultLeft.png");

  Texture2D textureGray = LoadTexture("../res/SpriteGray.png");
  Texture2D textureGreen = LoadTexture("../res/SpriteGreen.png");
  Texture2D textureRed = LoadTexture("../res/SpriteRed.png");
  Texture2D textureViolet = LoadTexture("../res/SpriteViolet.png");

  SetWindowIcon(LoadImageFromTexture(textureDefaultRight));

  // const Vector2 startPosition{(window.width - texture.width) * 0.5f,
  //                           (window.height - texture.height) * 0.5f};
  Vector2 position{96, 96};

  int speed;

  // InitAudioDevice();
  // Music music = LoadMusicStream("../res/Music.mp3");
  // PlayMusicStream(music);

  while (!WindowShouldClose()) {
    // xxx = std::to_string(GetFPS());

    // SetWindowTitle(xxx.c_str());
    //  UpdateMusicStream(music);

    speed = 10;
    /*
        if (position.y != 695.0f)
          position.y += 5.0f;
        if (position.y > 800.0f)
          position.y = -100.0f;
    */
    // if (IsKeyPressed(KEY_SPACE))
    //   position.y -= 100.0f;

    // if (IsKeyPressed(KEY_R))
    // position = startPosition;

    if (IsKeyDown(KEY_LEFT_SHIFT))
      speed *= 2;

    if (IsKeyDown(KEY_RIGHT)) {
      player = Player::Right;
      position.x += speed;
    }
    if (IsKeyDown(KEY_LEFT)) {
      player = Player::Left;
      position.x -= speed;
    }

    if (IsKeyDown(KEY_UP))
      position.y -= speed;
    if (IsKeyDown(KEY_DOWN))
      position.y += speed;

    BeginDrawing();
    ClearBackground(SKYBLUE);

    // DrawCircleV(position, ballRadius, RED);
    // DrawRectangleV({position.x, position.y}, {32, 32}, MAGENTA);

    switch (player) {
    // default:
    case Player::Right:
      DrawTexture(textureDefaultRight, position.x, position.y, WHITE);
      break;
    case Player::Left:
      DrawTexture(textureDefaultLeft, position.x, position.y, WHITE);
      break;
    }

    DrawText("I`m a default!", position.x + 36, position.y - 0, 10, WHITE);

    DrawTexture(textureGray, position.x + 32, position.y + 32, WHITE);
    DrawText("I`m a gray!", position.x + 36 + 32, position.y - 0 + 32, 10,
             WHITE);

    DrawTexture(textureGreen, position.x + 64, position.y + 64, WHITE);
    DrawText("I`m a green!", position.x + 36 + 64, position.y - 0 + 64, 10,
             WHITE);

    DrawTexture(textureRed, position.x + 96, position.y + 96, WHITE);
    DrawText("I`m a red!", position.x + 36 + 96, position.y - 0 + 96, 10,
             WHITE);

    DrawTexture(textureViolet, position.x + 128, position.y + 128, WHITE);
    DrawText("I`m a violet!", position.x + 36 + 128, position.y - 0 + 128, 10,
             WHITE);

    DrawFPS(10, 10);
    EndDrawing();
  }

  // UnloadMusicStream(music);

  UnloadTexture(textureDefaultRight);
  UnloadTexture(textureDefaultLeft);

  UnloadTexture(textureGray);
  UnloadTexture(textureGreen);
  UnloadTexture(textureRed);
  UnloadTexture(textureViolet);

  CloseWindow();
  return 0;
}
