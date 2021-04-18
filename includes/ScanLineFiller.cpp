#include "ScanLineFiller.h"


ScanLineFiller::ScanLineFiller(){
    std::cout << "0 checkpoint" << std::endl;

    for(int i = 0; i < 480; ++i){
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
            printf("\nRemoved at %d",yy);
              
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
    // both used for edgetable and active edge table..
    // The edge tuple sorted in increasing max_y and x of the lower end.
    (receiver->buckets[(receiver)->count]).max_y = ym;
    (receiver->buckets[(receiver)->count]).min_x = (float)xm;
    (receiver->buckets[(receiver)->count]).slopeinverse = slopInv;
              
    // sort the buckets
    insertionSort(receiver);
          
    (receiver->count)++; 
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
      
    // horizontal lines are not stored in edge table
    if (y2==y1)
        return;
          
    minv = (float)1.0/m;
    printf("\nSlope string for %d %d & %d %d: %f",x1,y1,x2,y2,minv);
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
    // the assignment part is done..now storage..
    storeEdgeInTuple(&this->edgeTable[scanline],max_yTS,xwithyminTS,minv);     
}

void ScanLineFiller::updatexbyslopeinv(EdgeTableTuple *Tup)
{
    int i;
      
    for (i=0; i<Tup->count; i++)
    {
        (Tup->buckets[i]).min_x =(Tup->buckets[i]).min_x + (Tup->buckets[i]).slopeinverse;
    }
}

void ScanLineFiller::fill(){
        /* Follow the following rules:
    1. Horizontal edges: Do not include in edge table
    2. Horizontal edges: Drawn either on the bottom or on the top.
    3. Vertices: If local max or min, then count twice, else count
        once.
    4. Either vertices at local minima or at local maxima are drawn.*/
  
  
    int i, j, x1, max_y1, x2, max_y2, FillFlag = 0, coordCount;
      
    // we will start from scanline 0; 
    // Repeat until last scanline:
    for (i=0; i<480; i++)//4. Increment y by 1 (next scan line)
    {

        // 1. Move from ET bucket y to the
        // AET those edges whose ymin = y (entering edges)
        for (j=0; j<this->edgeTable[i].count; j++)
        {
            storeEdgeInTuple(&this->activeEdgeTable,this->edgeTable[i].buckets[j].
                     max_y,this->edgeTable[i].buckets[j].min_x,
                    this->edgeTable[i].buckets[j].slopeinverse);
        }
        // printTuple(&this->activeEdgeTable);
          
        // 2. Remove from AET those edges for 
        // which y=max_y (not involved in next scan line)
        this->removeEdgeByYmax(&this->activeEdgeTable, i);
          
        //sort AET (remember: ET is presorted)
        insertionSort(&this->activeEdgeTable);
          
        // printTuple(&this->activeEdgeTable);
          
        //3. Fill lines on scan line y by using pairs of x-coords from AET
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
                /* three cases can arrive-
                    1. lines are towards top of the intersection
                    2. lines are towards bottom
                    3. one line is towards top and other is towards bottom
                */
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
                  
                // checking for intersection...
                if (x1==x2)
                {
                /*three cases can arive-
                    1. lines are towards top of the intersection
                    2. lines are towards bottom
                    3. one line is towards top and other is towards bottom
                */
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
                //drawing actual lines...
                glColor3f(0.0f,0.7f,0.0f);
                  
                glBegin(GL_LINES);
                glVertex2i(x1,i);
                glVertex2i(x2,i);
                glEnd();
                glFlush();         
                  
                // printf("\nLine drawn from %d,%d to %d,%d",x1,i,x2,i);
            }
              
        }
              
        j++;
    } 
              
          
    // 5. For each nonvertical edge remaining in AET, update x for new y
    updatexbyslopeinv(&this->activeEdgeTable);
    }
}
