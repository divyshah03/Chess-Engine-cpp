#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <string>

class Timer {
    int player1_time;
    int player2_time;
    bool player1Turn;
    std::atomic<bool> running;
    std::thread timer_thread;

public:
    std::atomic<bool> waitingForInput = true;
    Timer(int seconds_per_player); 
    ~Timer(); // Destructor

    void start();       // Starts the countdown and listens for input
    void stop();        // Stops the timer
    void printTime();   // Prints current time left for both players
    void switchTurn();   // Switches turn between players
};

#endif
