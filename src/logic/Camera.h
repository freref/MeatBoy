

#ifndef MEATBOY_CAMERA_H
#define MEATBOY_CAMERA_H


class Camera {
public:
    int windowWidth;
    int windowHeight;
    int sizeWidth;
    int sizeHeight;
    float height;

    Camera(int _width, int _height) : windowWidth(_width), windowHeight(_height), height(0){};

    void setSizeWidth(int _sizeWidth){sizeWidth = _sizeWidth;};
    int getSizeWidth() {return windowWidth / sizeWidth;};
    void goUp(float _height){height += _height;};
    void reset(){height = 0;};

    void setSizeHeight(int _sizeHeight){sizeHeight = _sizeHeight;};
    //int getSizeHeight() {return windowWidth / sizeWidth;};

    int projectX(int x);
    int projectY(int y);
};


#endif //MEATBOY_CAMERA_H
