#ifndef GAME_H
#define GAME_H

#include "Hero.h"
#include "Window.h"

#include <iostream>
#include <vector>

class Game {
private:
  const Window myWindow{};
  const Texture myBackground{LoadTexture("../resources/Background.png")};

  Hero myHero{};
  Camera2D myCamera{myHero.getPosition(), myHero.getPosition(), 0.0f, 1.0f};

  void input();
  void update(float deltaTime);
  void draw();

public:
  Game();
  ~Game();

  void loop();
};

#endif // GAME_H