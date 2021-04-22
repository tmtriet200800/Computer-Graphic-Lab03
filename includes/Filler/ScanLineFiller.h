#ifndef ScanLineFiller_H
#define ScanLineFiller_H
#include "../Filler.h"
#define maxBucket 1000

struct EdgeBucket{
    int max_y;   
    float min_x;  //x-coordinate of lowest edge point updated only in aet
    float slopeinverse;
};

struct EdgeTableTuple{
    int count;
    EdgeBucket buckets[maxBucket];
};

class ScanLineFiller : public Filler {
public:
    EdgeTableTuple edgeTable[MAX_HEIGHT], activeEdgeTable;

    ScanLineFiller();

    // bool sortEdgeBucketMinX(EdgeBucket const& lbucket, EdgeBucket const& rbucket);
    void storeEdgeInTuple (EdgeTableTuple *receiver,int ym,int xm,float slopInv);
    void storeEdgeInTable (int x1,int y1, int x2, int y2);
    void insertionSort(EdgeTableTuple *ett);
    void removeEdgeByYmax(EdgeTableTuple *Tup,int yy);
    void updateWithSlope(EdgeTableTuple *Tup);
    void fillSinglePixel(float red, float green, float blue);
    void fill(float red, float green, float blue, vector<pair<double, double>> points);
};

#endif