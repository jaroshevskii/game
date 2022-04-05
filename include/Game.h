#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <raylib.h>
#include <string>
#include <vector>

// MARK: Window

class Window {
public:
  Window(int width, int height, const std::string &title);
  ~Window();
};

// MARK: Hero

class Hero {
private:
  enum class State { StandingLeft, StandingRight, MoveLeft, MoveRight };

  Vector2 myPosition;
  State myState;
  Rectangle myCollision;
  float mySpeed;

  std::vector<Texture> myTextures;
  Texture mySptite;

public:
  Hero(const Vector2 &position, float speed);
  ~Hero();

  void input();
  void update(float frameTime);
  void draw();
};

// MARK: Game

class Game {
private:
  Window myWindow{640, 360, "Game"};
  Hero myHero{Vector2{640.0f / 2.0f, 360.0f / 2.0f}, 384.0f};

  void input();
  void update(float frameTime);
  void draw();

public:
  Game();
  ~Game();

  void loop();
};

#endif // GAME_H