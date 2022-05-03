#ifndef HERO_H
#define HERO_H

#include <cstddef>
#include <raylib.h>
#include <vector>

class Hero {
private:
  enum class State { StandingLeft, StandingRight, MoveLeft, MoveRight };

  Vector2 myPosition{320.0f, 270.0f};
  const int myWidth{32};
  const int myHeight{64};

  float mySpeed{750.0f};

  State myState{State::StandingRight};
  const std::vector<Texture> myTextures{
      LoadTexture("../resources/HeroStandingLeft.png"),
      LoadTexture("../resources/HeroStandingRight.png"),
      LoadTexture("../resources/HeroMoveLeft.png"),
      LoadTexture("../resources/HeroMoveRight.png")};
  Texture mySptite{myTextures.at(static_cast<size_t>(myState))};

  Rectangle getCollision() const;

public:
  Hero() = default;
  ~Hero();

  void input();
  void update(float deltaTime);
  void draw();

  const Vector2 &getPosition() const;
};

#endif // HERO_H