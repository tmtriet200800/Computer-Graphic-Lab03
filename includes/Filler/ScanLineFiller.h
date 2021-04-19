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
    EdgeTableTuple edgeTable[480], activeEdgeTable;

    ScanLineFiller();

    // bool sortEdgeBucketMinX(EdgeBucket const& lbucket, EdgeBucket const& rbucket);
    void storeEdgeInTuple (EdgeTableTuple *receiver,int ym,int xm,float slopInv);
    void storeEdgeInTable (int x1,int y1, int x2, int y2);
    void insertionSort(EdgeTableTuple *ett);
    void removeEdgeByYmax(EdgeTableTuple *Tup,int yy);
    void updatexbyslopeinv(EdgeTableTuple *Tup);
    void fill();
};

#endif