#include "Hero.h"

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
    }
    break;
  case State::StandingRight:
    if (IsKeyDown(KEY_A)) {
      myState = State::StandingLeft;
    } else if (IsKeyDown(KEY_D)) {
      myState = State::MoveRight;
    }
    break;
  case State::MoveLeft:
    if (IsKeyReleased(KEY_A)) {
      myState = State::StandingLeft;
    }
    break;
  case State::MoveRight:
    if (IsKeyReleased(KEY_D)) {
      myState = State::StandingRight;
    }
    break;
  }
}

void Hero::update(float deltaTime) {
  switch (myState) {
  case State::MoveLeft:
    myPosition.x -= mySpeed * deltaTime;
    break;
  case State::MoveRight:
    myPosition.x += mySpeed * deltaTime;
    break;
  default:
    break;
  }

  mySptite = myTextures[static_cast<size_t>(myState)];

  //////////////////////////////////
  // myPosition.x += 0.10f;
}

void Hero::draw() {
  // DrawRectangleRec(getCollision(), MAGENTA);

  DrawTexture(mySptite, myPosition.x - int{myWidth / 2}, myPosition.y - myHeight,
              WHITE);

  /*DrawTexture(mySptite, static_cast<int>(myPosition.x),
              static_cast<int>(myPosition.y), WHITE);*/
  
  /* DrawTexture(mySptite, myPosition.x + 8, myPosition.y + 8, WHITE);*/

   /*DrawRectangleRec(Rectangle{myPosition.x - myWidth / 2.0f + 2.0f,
                              myPosition.y - myHeight + 2.0f, 28.0f, 16.0f},
                    BLACK);*/
}

Rectangle Hero::getCollision() const {
  return Rectangle{myPosition.x - myWidth / 2.0f, myPosition.y - myHeight,
                   static_cast<float>(myWidth), static_cast<float>(myHeight)};
}

const Vector2 &Hero::getPosition() const { return myPosition; }