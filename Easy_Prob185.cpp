/* Given two rectangles on a 2D graph, return the area of their intersection. If the rectangles don't intersect, return 0. */
#include <iostream>
#include <utility>

using namespace std;

struct Rectangle {
    int top_left_x;
    int top_left_y;
    int width;
    int height;

    Rectangle(int top_left_x, int top_left_y, int width, int height) : top_left_x(top_left_x), top_left_y(top_left_y), width(width), height(height) {}
    
    Rectangle() {
        top_left_x = 0;
        top_left_y = 0;
        width = 0;
        height = 0;
    }

    int getTopLeftX() const { return top_left_x; }
    void setTopLeftX(int top_left_x) { this->top_left_x = top_left_x; }

    int getTopLeftY() const { return top_left_y; }
    void setTopLeftY(int top_left_y) { this->top_left_y = top_left_y; }

    int getWidth() const { return width; }
    void setWidth(int width) { this->width = width; }

    int getHeight() const { return height; }
    void setHeight(int height) { this->height = height; }
};

int intersectRectangles(Rectangle rectangle1, Rectangle rectangle2) {
    int area = 0;

    Rectangle rectangleLeft;
    Rectangle rectangleRight;

    // Initialize left rectangle and right rectangle
    if (rectangle1.getTopLeftX() <= rectangle2.getTopLeftX()) {
        rectangleLeft.setTopLeftX(rectangle1.getTopLeftX());
        rectangleLeft.setTopLeftY(rectangle1.getTopLeftY());
        rectangleLeft.setWidth(rectangle1.getWidth());
        rectangleLeft.setHeight(rectangle1.getHeight());

        rectangleRight.setTopLeftX(rectangle2.getTopLeftX());
        rectangleRight.setTopLeftY(rectangle2.getTopLeftY());
        rectangleRight.setWidth(rectangle2.getWidth());
        rectangleRight.setHeight(rectangle2.getHeight());
    } else {
        rectangleLeft.setTopLeftX(rectangle2.getTopLeftX());
        rectangleLeft.setTopLeftY(rectangle2.getTopLeftY());
        rectangleLeft.setWidth(rectangle2.getWidth());
        rectangleLeft.setHeight(rectangle2.getHeight());

        rectangleRight.setTopLeftX(rectangle1.getTopLeftX());
        rectangleRight.setTopLeftY(rectangle1.getTopLeftY());
        rectangleRight.setWidth(rectangle1.getWidth());
        rectangleRight.setHeight(rectangle1.getHeight());
    }

    // Check for intersection along x
    if (rectangleLeft.getTopLeftX() + rectangleLeft.getWidth() <= rectangleRight.getTopLeftY()) {
        // Verify if rectangle left is under rectangle richt
        if (rectangleLeft.getTopLeftY() >= rectangleRight.getTopLeftY()) {
            // Check for intersection along y
            if (rectangleRight.getTopLeftY() >= (rectangleLeft.getTopLeftY() - rectangleLeft.getHeight())) {
                area = (rectangleLeft.getTopLeftX() + rectangleLeft.getWidth() - rectangleRight.getTopLeftX()) * (rectangleRight.getTopLeftY() - rectangleLeft.getTopLeftY() + rectangleLeft.getHeight());
            }
        }
        else {
            // Check for intersection along y
            if (rectangleLeft.getTopLeftY() >= (rectangleRight.getTopLeftY() - rectangleRight.getHeight())) {
                area = (rectangleLeft.getTopLeftX() + rectangleLeft.getWidth() - rectangleRight.getTopLeftX() + 1) * (rectangleLeft.getTopLeftY() - rectangleRight.getHeight() + rectangleRight.getTopLeftY());
            }
        }
    }

    return area;
};

int main(int argc, char *argv[])
{
    Rectangle rectangle1(1, 4, 3, 3);
    Rectangle rectangle2(0, 5, 4, 3);

    cout << intersectRectangles(rectangle1, rectangle2) << endl;
};