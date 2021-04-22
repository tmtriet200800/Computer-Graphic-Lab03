#ifndef BoundaryFiller_H
#define BoundaryFiller_H
#include "../Filler.h"

class BoundaryFiller : public Filler {
public:
    BoundaryFiller(){};
    void fill(GLint x, GLint y, Color oldColor, Color newColor, int (&vis)[MAX_WIDTH][MAX_HEIGHT]);
};

#endif