//
// Created by mrfer on 11/17/2022.
//
#include "laser.h"
#include "circle.h"
#include "rect.h"
using namespace std;
laser::laser(int xDirection, int yDirection, point2D center): Rect(center, {1,3}){
    this->xDirection = xDirection;
    this->yDirection = yDirection;
}


/*
bool laser::isOverlapping(Circle c){
    return (sqrt((c.getCenterX() - center.x)*(c.getCenterX() - center.x) + (c.getCenterY() - center.y)*(c.getCenterY() - center.y)) <= c.getRadius() + 1.5);
}
*/
int laser::getXdir(){
    return xDirection;
}
int laser::getYdir(){
    return yDirection;
}

