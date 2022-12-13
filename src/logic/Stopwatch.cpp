

#include "Stopwatch.h"

Stopwatch& Stopwatch::getInstance(){
    // Static instance of the class.
    static Stopwatch instance;

    // Return the instance.
    return instance;
}