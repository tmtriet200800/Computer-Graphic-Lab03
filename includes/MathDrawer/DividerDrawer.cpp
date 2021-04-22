#include "./DividerDrawer.h"
#include "../OvalDrawer/CircleDrawer.h"
#include "./MinusDrawer.h"

DividerDrawer::DividerDrawer(){

}

void DividerDrawer::draw(float xt, float yt, float scale){
    CircleDrawer cd;
    MinusDrawer md;

    cd.draw(xt, yt + 2*scale, scale);
    md.draw(xt, yt, scale);
    cd.draw(xt, yt - 2*scale, scale);
}
