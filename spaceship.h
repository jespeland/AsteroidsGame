//
// Created by Max Ivry on 11/16/22.
//

#ifndef MARIEGER_MIVRY_SPACESHIP_H
#define MARIEGER_MIVRY_SPACESHIP_H

#include "rect.h"
#include "shape.h"
#include "circle.h"

class SpaceShip : public Shape {
protected:

    point2D top;
    point2D leftBottom;
    point2D rightBottom;
    Rect laser;
    double height;
    double width;
    int lives;

public:
    SpaceShip();
    SpaceShip(color fill, point2D center);
    SpaceShip(point2D top, point2D leftBottom, point2D rightBottom);

    double getBottomRightX() const;
    double getBottomRightY() const;
    double getTopX() const;
    double getTopY() const override;
    double getBottomLeftX() const;
    double getBottomLeftY() const;
    double getHeight() const;
    int getLives();

    void setBottomRightX(double x);
    void setBottomRightY(double y);
    void setTopX(double x);
    void setTopY(double y);
    void setBottomLeftX(double x);
    void setBottomLeftY(double y);
    void loseLife();

    //virtual methods being overriden to avoid abstract class classification
    double getLeftX() const override;
    double getRightX() const override;
    double getBottomY() const override;

    Rect fire();
    void draw() const override;
    void move(double deltaX, double deltaY) override;

    void rotate(double theta);
};

#endif //MARIEGER_MIVRY_SPACESHIP_H
