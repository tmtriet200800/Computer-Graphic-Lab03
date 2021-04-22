#include "BoundaryFiller.h"

void BoundaryFiller::fill(GLint x, GLint y, Color fillColor, Color boundaryColor, int (&vis)[MAX_WIDTH][MAX_HEIGHT]) {
	queue<pair<int, int>> obj;

	obj.push(make_pair(x, y));

	vis[x][y] = 1;

	while(!obj.empty()){
		pair<int, int> coord = obj.front();

		obj.pop();

		x = coord.first;
		y = coord.second;
		
		Color color = getPixelColor(coord.first, coord.second);

		if((color.r != fillColor.r || color.g != fillColor.g || color.b != fillColor.b) &&
			(color.r != boundaryColor.r || color.g != boundaryColor.g || color.b != boundaryColor.b))
		{
			setPixelColor(x, y, fillColor);
			vis[x][y] = 1;

			if(vis[x+1][y]  == 0){
				obj.push(make_pair(x+1,y));
			}

			if(vis[x][y + 1] == 0){
				obj.push(make_pair(x,y + 1));
			}

			if(vis[x - 1][y] == 0){
				obj.push(make_pair(x-1,y));
			}

			if(vis[x][y - 1] == 0){
				obj.push(make_pair(x,y-1));
			}

		}
	}
}