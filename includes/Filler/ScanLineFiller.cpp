#include "ScanLineFiller.h"
ScanLineFiller::ScanLineFiller(){
    for(int i = 0; i < MAX_HEIGHT; ++i){
        this->edgeTable[i].count = 0;
    }    

    this->activeEdgeTable.count = 0;
}

bool sortEdgeBucketMinX(EdgeBucket const& lbucket, EdgeBucket const& rbucket){
    return lbucket.min_x < rbucket.min_x;
}

void ScanLineFiller::insertionSort(EdgeTableTuple *ett)
{
    int i,j;
    EdgeBucket temp; 
  
    for (i = 1; i < ett->count; i++) 
    {
        temp.max_y = ett->buckets[i].max_y;
        temp.min_x = ett->buckets[i].min_x;
        temp.slopeinverse = ett->buckets[i].slopeinverse;
        j = i - 1;
  
    while ((temp.min_x < ett->buckets[j].min_x) && (j >= 0)) 
    {
        ett->buckets[j + 1].max_y = ett->buckets[j].max_y;
        ett->buckets[j + 1].min_x = ett->buckets[j].min_x;
        ett->buckets[j + 1].slopeinverse = ett->buckets[j].slopeinverse;
        j = j - 1;
    }
    ett->buckets[j + 1].max_y = temp.max_y;
    ett->buckets[j + 1].min_x = temp.min_x;
    ett->buckets[j + 1].slopeinverse = temp.slopeinverse;
    }
}

void ScanLineFiller::removeEdgeByYmax(EdgeTableTuple *Tup,int yy)
{
    int i,j;
    for (i=0; i< Tup->count; i++)
    {
        if (Tup->buckets[i].max_y == yy)
        {
            for ( j = i ; j < Tup->count -1 ; j++ )
                {
                Tup->buckets[j].max_y =Tup->buckets[j+1].max_y;
                Tup->buckets[j].min_x =Tup->buckets[j+1].min_x;
                Tup->buckets[j].slopeinverse = Tup->buckets[j+1].slopeinverse;
                }
                Tup->count--;
            i--;
        }
    }
}   

void ScanLineFiller::storeEdgeInTuple (EdgeTableTuple *receiver,int ym,int xm,float slopInv)
{
    receiver->buckets[receiver->count].max_y = ym;
    receiver->buckets[receiver->count].min_x = (float)xm;
    receiver->buckets[receiver->count].slopeinverse = slopInv;
              
    insertionSort(receiver);
          
    receiver->count++; 
}
  
void ScanLineFiller::storeEdgeInTable (int x1,int y1, int x2, int y2)
{
    float m,minv;
    int max_yTS,xwithyminTS, scanline; //ts stands for to store
      
    if (x2==x1)
    {
        minv=0.000000;
    }
    else
    {
    m = ((float)(y2-y1))/((float)(x2-x1));
      
    if (y2==y1)
        return;
          
    minv = (float)1.0/m;
    }
      
    if (y1>y2)
    {
        scanline=y2;
        max_yTS=y1;
        xwithyminTS=x2;
    }
    else
    {
        scanline=y1;
        max_yTS=y2;
        xwithyminTS=x1;     
    }
    storeEdgeInTuple(&this->edgeTable[scanline],max_yTS,xwithyminTS,minv);     
}

void ScanLineFiller::updateWithSlope(EdgeTableTuple *Tup)
{
    int i;
      
    for (i=0; i<Tup->count; i++)
    {
        (Tup->buckets[i]).min_x =(Tup->buckets[i]).min_x + (Tup->buckets[i]).slopeinverse;
    }
}

void ScanLineFiller::fillSinglePixel(float red, float green, float blue){
    int i, j, x1, max_y1, x2, max_y2, FillFlag = 0, coordCount;
      
    for (i=0; i < MAX_HEIGHT; i++)//4. Increment y by 1 (next scan line)
    {
        for (j=0; j<this->edgeTable[i].count; j++)
        {
            storeEdgeInTuple(&this->activeEdgeTable,this->edgeTable[i].buckets[j].
                     max_y,this->edgeTable[i].buckets[j].min_x,
                    this->edgeTable[i].buckets[j].slopeinverse);
        }
          
        this->removeEdgeByYmax(&this->activeEdgeTable, i);
          
        insertionSort(&this->activeEdgeTable);
          
        j = 0; 
        FillFlag = 0;
        coordCount = 0;
        x1 = 0;
        x2 = 0;
        max_y1 = 0;
        max_y2 = 0;
        while (j<this->activeEdgeTable.count)
        {
            if (coordCount%2==0)
            {
                x1 = (int)(this->activeEdgeTable.buckets[j].min_x);
                max_y1 = this->activeEdgeTable.buckets[j].max_y;
                if (x1==x2)
                {
                    if (((x1==max_y1)&&(x2!=max_y2))||((x1!=max_y1)&&(x2==max_y2)))
                    {
                        x2 = x1;
                        max_y2 = max_y1;
                    }
                  
                    else
                    {
                        coordCount++;
                    }
                }
                  
                else
                {
                        coordCount++;
                }
            }
            else
            {
                x2 = (int)this->activeEdgeTable.buckets[j].min_x;
                max_y2 = this->activeEdgeTable.buckets[j].max_y; 
              
                FillFlag = 0;
                  
                if (x1==x2)
                {
                    if (((x1==max_y1)&&(x2!=max_y2))||((x1!=max_y1)&&(x2==max_y2)))
                    {
                        x1 = x2;
                        max_y1 = max_y2;
                    }
                    else
                    {
                        coordCount++;
                        FillFlag = 1;
                    }
                }
                else
                {
                        coordCount++;
                        FillFlag = 1;
                } 
              
              
            if(FillFlag)
            {
                glColor3f(red,green,blue);
                glBegin(GL_LINES);
                glVertex2i(x1,i);
                glVertex2i(x2,i);
                glEnd();
                glFlush();         
            }
              
        }
              
        j++;
    } 
              
    this->updateWithSlope(&this->activeEdgeTable);
    }
}

void ScanLineFiller::fill(float red,float green,float blue, vector<pair<double,double>> points){
    for(int i = 0; i < points.size() - 1; i++){
        this->storeEdgeInTable(points[i].first, points[i].second, points[i + 1].first, points[i + 1].second);
    }

    this->storeEdgeInTable(points[points.size() - 1].first, points[points.size() - 1].second, points[0].first, points[0].second);

    this->fillSinglePixel(red, green, blue);
}