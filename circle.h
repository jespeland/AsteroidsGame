#ifndef GRAPHICSEXAMPLES_CIRCLE_H
#define GRAPHICSEXAMPLES_CIRCLE_H

#include "shape.h"
#include "spaceship.h"
#include "laser.h"

class Circle : public Shape {
private:
    double radius;
public:
    /* Constructors */
    Circle();
    explicit Circle(double radius);
    explicit Circle(color fill);
    explicit Circle(point2D center);
    Circle(color fill, point2D center);
    Circle(double red, double green, double blue, double alpha);
    Circle(double x, double y);
    Circle(double red, double green, double blue, double alpha, double x, double y);
    Circle(color fill, double x, double y);
    Circle(double red, double green, double blue, double alpha, point2D center);
    Circle(color fill, double radius);
    Circle(point2D center, double radius);
    Circle(color fill, point2D center, double radius);
    Circle(double red, double green, double blue, double alpha, double radius);
    Circle(double x, double y, double radius);
    Circle(double red, double green, double blue, double alpha, double x, double y, double radius);
    Circle(color fill, double x, double y, double radius);
    Circle(double red, double green, double blue, double alpha, point2D center, double radius);

    /* Destructor */
    virtual ~Circle() = default;

    /* Getters */
    double getRadius() const;
    double getLeftX() const override;
    double getRightX() const override;
    double getTopY() const override;
    double getBottomY() const override;

    /* Setter */
    void setRadius(double r);
    void changeRadius(double delta);
//    void move(int deltaX, int deltaY);
    void draw() const override;

    /* Overlapping */
    bool isOverlapping(const Circle &c) const;
//    bool isOverlapping(const SpaceShip &s) const;
    //bool isOverlapping(const laser &l) const;

    /* Collision */
    void collide(Circle &c);



};

#endif //GRAPHICSEXAMPLES_CIRCLE_H
