

#include "Camera.h"
#include <iostream>

int Camera::projectX(int x) {
    return x * getSizeWidth();
}

int Camera::projectY(int y) {

    return  windowHeight - (sizeHeight * getSizeWidth() - y * getSizeWidth() );
}

int Camera::unprojectY(int y) {
    return (windowHeight - y) / getSizeWidth() + sizeHeight;
}