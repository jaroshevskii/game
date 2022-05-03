#include "Window.h"

Window::Window() { InitWindow(myWidth, myHeight, myTitle.c_str()); }

Window::~Window() { CloseWindow(); }