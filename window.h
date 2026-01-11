#ifndef WINDOW_H
#define WINDOW_H
#include "enumerated.h"
#include <X11/Xlib.h>
#include <iostream>
#include <string>

class Xwindow {
    Display *d;
    Window w;
    int s, width, height;
    GC gc;
    unsigned long colours[11];
    XFontStruct *font = nullptr;

  public:
    Xwindow(int width=500, int height=500);  // Constructor; displays the window.
    ~Xwindow();                              // Destructor; destroys the window.

    int getWidth() const;
    int getHeight() const;

    // Draws a rectangle
    void fillRectangle(int x, int y, int width, int height, Colour colour = Colour::BLACK);

    // Draws a string
    void drawString(int x, int y, std::string msg, Colour colour);

    XFontStruct *getFontStruct() const;

};

#endif
