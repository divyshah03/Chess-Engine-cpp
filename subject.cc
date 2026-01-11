#include "subject.h"

using namespace std;

void Subject::attach(Observer *ob) {
    observers.emplace_back(ob);
}

void Subject::notifyObservers() {
    for(auto &ob : observers)
        ob->notify(*this);
}

State Subject::getState() {
    return state;
}

void Subject::setState(State newS) {
    state = newS;
}

void Subject::detachAll() {
    observers.clear();
}

