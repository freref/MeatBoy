

#ifndef MEATBOY_STOPWATCH_H
#define MEATBOY_STOPWATCH_H

#include <chrono>

using namespace std::chrono;

class Stopwatch {
public:
    // Get the instance of the Stopwatch class
    static Stopwatch& getInstance() {
        // The instance is created the first time this function is called
        static Stopwatch instance;
        return instance;
    }

    // Start the stopwatch
    void newFrame() {
        startTime = high_resolution_clock::now();
    }

    // Get the elapsed time in milliseconds since the stopwatch was started
    int elapsed() {
        high_resolution_clock::time_point currentTime = high_resolution_clock::now();
        auto elapsedTime = duration_cast<microseconds>(currentTime - startTime).count();
        return elapsedTime;
    }

private:
    // Private constructor to prevent creating multiple instances of the class
    Stopwatch() {}

    // Private copy constructor and assignment operator to prevent copy and assignment
    Stopwatch(Stopwatch const&) = delete;
    void operator=(Stopwatch const&) = delete;

    // The time when the stopwatch was started
    high_resolution_clock::time_point startTime;
};



#endif //MEATBOY_STOPWATCH_H
