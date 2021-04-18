#ifndef Filler_H
#define Filler_H
#include "Base.h"

struct Color{
    GLfloat r;
    GLfloat g;
    GLfloat b;
};

class Filler  {
public:
    Filler(){};
    Color getPixelColor(GLint x, GLint y);
    void setPixelColor(GLint x, GLint y, Color color);
};

#endif