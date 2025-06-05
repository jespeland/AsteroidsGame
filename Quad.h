//
// Created by mrfer on 11/15/2022.
//

#ifndef RUNNER_QUAD_H
#define RUNNER_QUAD_H
struct colors {
    double red;
    double green;
    double blue;
};

struct point {
    int x;
    int y;
};

class Quad {
protected:
    colors fill;
    point center;
    unsigned int width;
    unsigned int height;

public:
    Quad();
    Quad(colors fill, point center, unsigned int width, unsigned int height);

    int getCenterX() const;
    int getLeftX() const;
    int getRightX() const;
    int getCenterY() const;
    int getTopY() const;
    int getBottomY() const;
    point getCenter() const;

    double getRed() const;
    double getGreen() const;
    double getBlue() const;
    colors getFill() const;

    unsigned int getWidth() const;
    unsigned int getHeight() const;

    void setColor(double red, double green, double blue);
    void setColor(colors fill);
    void move(int deltaX, int deltaY);
    void resize(unsigned int width, unsigned int height);

    virtual void draw() const;
};
#endif //RUNNER_QUAD_H
