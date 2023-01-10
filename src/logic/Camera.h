

#ifndef MEATBOY_CAMERA_H
#define MEATBOY_CAMERA_H


class Camera {
    int windowWidth;
    int windowHeight;
    int sizeWidth;
    int sizeHeight;
public:
    Camera(int _width, int _height) : windowWidth(_width), windowHeight(_height){};

    void setSizeWidth(int _sizeWidth){sizeWidth = _sizeWidth;};
    int getSizeWidth() {return windowWidth / sizeWidth;};

    void setSizeHeight(int _sizeHeight){sizeHeight = _sizeHeight;};
    //int getSizeHeight() {return windowWidth / sizeWidth;};

    int projectX(int x);
    int projectY(int y);
    int unprojectY(int y);
};


#endif //MEATBOY_CAMERA_H
