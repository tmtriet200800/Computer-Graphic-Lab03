#ifndef FloodFiller_H
#define FloodFiller_H
#include "../Filler.h"

class FloodFiller : public Filler {
public:
    FloodFiller(){};
    void fill(GLint x, GLint y, Color oldColor, Color newColor,int (&vis)[MAX_WIDTH][MAX_HEIGHT]);
};

#endif