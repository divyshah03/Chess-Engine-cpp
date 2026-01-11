#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H

#include "observer.h"
#include "info.h"
#include "window.h"
#include "subject.h"
#include <vector>

class GraphicsDisplay: public Observer{
    const int GRID_SIZE = 8;

    Xwindow xw;
    int cellSize;

    void drawCell(const Info &info);
  
  public:
    GraphicsDisplay(size_t n);
    void notify(Subject &whoNotified) override;
};

#endif
