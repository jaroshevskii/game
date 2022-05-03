#include "Game.h"

Game::Game() {
  //---
  SetTargetFPS(60);
}

Game::~Game() { UnloadTexture(myBackground); }

void Game::input() {
  myHero.input();

  if (IsKeyPressed(KEY_I)) {
    std::cout << "X: " << myCamera.target.x << '\n'
              << "Y: " << myCamera.target.y << "\n\n";
  }

  if (IsKeyPressed(KEY_P)) {
    BeginDrawing();
    DrawRectangle(0, 0, 640, 360, Color{0, 0, 0, 150});
    // DrawRectangle(0, 0, 90, 30, MAGENTA);
    DrawText("Pause", (640 / 2 - 90 / 2), (360 / 2 - 30 / 2), 30,
             Color{255, 255, 255, 200});
    EndDrawing();
    while (!WindowShouldClose()) {
      if (IsKeyPressed(KEY_P)) {
        break;
      }
      BeginDrawing();
      EndDrawing();
    }
  }
}

void Game::update(float deltaTime) {
  myHero.update(deltaTime);
  myCamera.target = myHero.getPosition();
}

void Game::draw() {
  BeginDrawing();

  ClearBackground(BLACK);

  BeginMode2D(myCamera);
  DrawTexture(myBackground, 0, 0, WHITE);
  myHero.draw();
  EndMode2D();

  DrawFPS(16, 16);

  EndDrawing();
}

void Game::loop() {
  while (!WindowShouldClose()) {
    input();
    update(GetFrameTime());
    draw();
  }
}