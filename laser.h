//
// Created by mrfer on 11/17/2022.
//

#ifndef MARIEGER_MIVRY_LASER_H
#define MARIEGER_MIVRY_LASER_H
#include "rect.h"
#include "circle.h"
class laser : public Rect {
private:

public:
    int xDirection;
    int yDirection;
    laser(int xDirection, int yDirection, point2D center);
//    bool isOverlapping(Circle c);
    int getXdir();
    int getYdir();
};
#endif //MARIEGER_MIVRY_LASER_H
