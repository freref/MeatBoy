

#ifndef MEATBOY_STOPWATCH_H
#define MEATBOY_STOPWATCH_H


class Stopwatch {
private:
    // Private constructor to prevent instancing.
    Stopwatch() {}

    // Private copy constructor to prevent copying.
    Stopwatch(Stopwatch const&) {}

    // Private assignment operator to prevent copying.
    Stopwatch& operator=(Stopwatch const&) {}

    // Private destructor to prevent deleting.
    ~Stopwatch() {}

public:
    // Public static method to get the instance.
    static Stopwatch& getInstance();
};


#endif //MEATBOY_STOPWATCH_H
