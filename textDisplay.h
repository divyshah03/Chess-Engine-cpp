#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include <vector>
#include "observer.h"
#include "info.h"

class TextDisplay: public Observer {
    std::vector<std::vector<char>> theDisplay;
    const std::size_t gridSize;
    
  public:
    TextDisplay(std::size_t n);
    void notify(Subject &whoNotified) override;

    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

std::ostream &operator<<(std::ostream &out, const TextDisplay &td);

#endif
