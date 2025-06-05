//
// Created by Max Ivry on 11/16/22.
//
#include <math.h>
#include "shape.h"
#include "graphics.h"
#include "rect.h"
#include "spaceship.h"
#include <iostream>
#include "circle.h"
using namespace std;

//constructors
SpaceShip::SpaceShip() : Shape() {
    height = 0;
    width = 0;
    lives = 3;
}

//constructor to be used  in another project
SpaceShip::SpaceShip(color fill, point2D center) : Shape(fill,center) {
    this->fill = fill;
    this->center = center;

    //initialize
    height = 0;
    width = 0;
    lives = 3;
}

//constructor
SpaceShip::SpaceShip(point2D top, point2D leftBottom, point2D rightBottom) : Shape() {
    this->top = top;
    this->leftBottom = leftBottom;
    this->rightBottom = rightBottom;

    //setting the center
    center.x = ((top.x + leftBottom.x + rightBottom.x)/3.0);
    center.y = ((top.y +leftBottom.y + rightBottom.y)/3.0);

    //border default red
    border = color(1,0,0);

    //set height
    height = (leftBottom.x + rightBottom.x)/2;
    width = (leftBottom.y + top.y)/2;

    //set lives
    lives = 3;
}

//getters for position of each corner
double SpaceShip::getBottomRightX() const {
    return rightBottom.x;
}
double SpaceShip::getBottomRightY() const {
    return rightBottom.y;
}
double SpaceShip::getBottomLeftX() const {
    return rightBottom.y;
}
double SpaceShip::getBottomLeftY() const {
    return rightBottom.y;
}
double SpaceShip::getTopY() const {
    return top.y;
}
double SpaceShip::getTopX() const {
    return top.x;
}
double SpaceShip::getRightX() const {
    return rightBottom.x;
}
double SpaceShip::getLeftX() const {
    return leftBottom.x;
}
double SpaceShip::getBottomY() const {
    return (rightBottom.y+leftBottom.y)/2;
}
double SpaceShip::getHeight() const {
    return height;
}
int SpaceShip::getLives() {
    return lives;
}

//setters
void SpaceShip::setBottomRightX(double x) {
    rightBottom.x = x;
}
void SpaceShip::setBottomRightY(double y) {
    rightBottom.y = y;
}
void SpaceShip::setBottomLeftX(double x) {
    leftBottom.x = x;
}
void SpaceShip::setBottomLeftY(double y) {
    leftBottom.y = y;
}
void SpaceShip::setTopY(double y) {
    top.y = y;
}
void SpaceShip::setTopX(double x) {
    top.x = x;
}
void SpaceShip::loseLife() {
    lives -1;
}



//draw method that creates spaceship
void SpaceShip::draw() const {
    // Set drawing color to fill color
    glColor3f(fill.red, fill.green, fill.blue);
    // Draw the spaceship
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(leftBottom.x, leftBottom.y);
    glVertex2i(top.x, top.y);
    glVertex2i(rightBottom.x, rightBottom.y);
    glEnd();
}

void SpaceShip::move(double deltaX, double deltaY) {
    //move each vertex of triangle
    leftBottom.x += deltaX;
    leftBottom.y += deltaY;
    top.x += deltaX;
    top.y += deltaY;
    rightBottom.x += deltaX;
    rightBottom.y += deltaY;
    //resetting center
    center.x = ((top.x + leftBottom.x + rightBottom.x)/3.0);
    center.y = ((top.y +leftBottom.y + rightBottom.y)/3.0);
}
//method that rotates ship (still working out details)
void SpaceShip::rotate(double theta) {
    //variable declarations
    double oldTopX = top.x;
    double oldTopY = top.y;
    double oldBottomLX = leftBottom.x;
    double oldBottomLY = leftBottom.y;
    double oldBottomRX = rightBottom.x;
    double oldBottomRY = rightBottom.y;

    //code from https://www.youtube.com/watch?v=uhXc5PmiYEo
    setTopX((oldTopX*cos(theta)-oldTopY*sin(theta)));
    setTopY((oldTopX*sin(theta)+oldTopY*cos(theta)));

    setBottomRightX((oldBottomRX*cos(theta)-oldBottomRY*sin(theta)));
    setBottomRightY((oldBottomRX*sin(theta)+oldBottomRY*cos(theta)));

    setBottomLeftX((oldBottomLX*cos(theta)-oldBottomLY*sin(theta)));
    setBottomLeftY((oldBottomLX*sin(theta)+oldBottomLY*cos(theta)));
}








