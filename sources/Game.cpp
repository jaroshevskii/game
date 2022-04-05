#include "Game.h"

// MARK: Window

Window::Window(int width, int height, const std::string &title) {
  InitWindow(width, height, title.c_str());
}

Window::~Window() { CloseWindow(); }

// MARK: Hero

Hero::Hero(const Vector2 &position, float speed)
    : myPosition{position}, myState{State::StandingRight},
      myCollision{position.x - 16, position.y - 32, 32, 64}, mySpeed{speed},
      myTextures{LoadTexture("../res/HeroStandingLeft.png"),
                 LoadTexture("../res/HeroStandingRight.png"),
                 LoadTexture("../res/HeroMoveLeft.png"),
                 LoadTexture("../res/HeroMoveRight.png")},
      mySptite{myTextures[static_cast<size_t>(myState)]} {}

Hero::~Hero() {
  for (const auto &texture : myTextures) {
    UnloadTexture(texture);
  }
}

void Hero::input() {
  switch (myState) {
  case State::StandingLeft:
    if (IsKeyDown(KEY_A)) {
      myState = State::MoveLeft;
    } else if (IsKeyDown(KEY_D)) {
      myState = State::MoveRight;
    } else if (IsKeyPressed(KEY_D)) {
      myState = State::StandingRight;
    }
    break;
  case State::StandingRight:
    if (IsKeyDown(KEY_A)) {
      myState = State::StandingLeft;
    } else if (IsKeyDown(KEY_D)) {
      myState = State::MoveRight;
    } else if (IsKeyPressed(KEY_D)) {
      myState = State::StandingRight;
    }
    break;
  case State::MoveLeft:
    if (!IsKeyDown(KEY_A)) {
      myState = State::StandingLeft;
    }
    break;
  case State::MoveRight:
    if (!IsKeyDown(KEY_D)) {
      myState = State::StandingRight;
    }
    break;
  }
}

void Hero::update(float frameTime) {
  switch (myState) {
  case State::MoveLeft:
    myPosition.x -= mySpeed * frameTime;
    break;
  case State::MoveRight:
    myPosition.x += mySpeed * frameTime;
    break;
  }

  mySptite = myTextures[static_cast<size_t>(myState)];
}

void Hero::draw() {
  DrawRectangleRec(Rectangle{myPosition.x, myPosition.y, 32, 64}, MAGENTA);
  DrawTexture(mySptite, myPosition.x, myPosition.y, WHITE);
}

// MARK: Game

Game::Game() { //SetTargetFPS(60);
  SetConfigFlags(FLAG_FULLSCREEN_MODE);
}

Game::~Game() {}

void Game::input() { myHero.input(); }

void Game::update(float frameTime) { myHero.update(frameTime); }

void Game::draw() {
  BeginDrawing();

  ClearBackground(BLACK);

  myHero.draw();

  DrawFPS(16, 16);

  EndDrawing();
}

void Game::loop() {
  while (!WindowShouldClose()) {
    // std::cout << GetFrameTime() << '\n';
    input();
    update(GetFrameTime());
    draw();
  }
}