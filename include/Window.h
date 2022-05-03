#ifndef WINDOW_H
#define WINDOW_H

#include <raylib.h>
#include <string>

class Window {
private:
  const int myWidth{640};
  const int myHeight{360};
  const std::string myTitle{"Game"};

public:
  Window();
  ~Window();
};

#endif // WINDOW_H