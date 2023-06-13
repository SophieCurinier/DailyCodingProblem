/* Given a list of points, a central point, and an integer k, find the nearest k points from the central point.*/

#include <iostream>
#include <vector>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;

class Point
{
    private:
        float x;
        float y;

    public:
        // Constructors 
        Point(float x1, float y1) {
            x = x1;
            y = y1;
        }
        Point() {
            x = 0;
            y = 0;
        }

        // Setters
        void setX(float x1) {
            x = x1;
        }
        void setY(float y1) {
            y = y1;
        }

        // Getters
        float getX() {
            return x;
        }
        float getY() {
            return y;
        }

        // Method
        float calculEuclidianDistance(Point point) {
            float distance = pow(pow(x - point. x, 2) + pow(y - point.y, 2), 0.5);
            return distance;
        }

        void print() {
            cout << x << " " << y << endl;
        }

};

void findKNearestPoint(vector<Point>& points, int k, Point centralPoint) {
    vector<pair<float,Point>> orderPoints(points.size());
    
    // Fill vector orderPoints
    for (int i=0; i<points.size(); i++) {
        orderPoints[i].first = centralPoint.calculEuclidianDistance(points[i]);
        orderPoints[i].second = points[i];
    }

    sort(orderPoints.begin(), orderPoints.end(), [](const pair<float, Point>& p1, const pair<float, Point>& p2) {
        return p1.first < p2.first;
    });

    for (int i=0; i<k%points.size(); i++)
    {
        orderPoints[i].second.print();
    }
}

int main(int argc, char *argv[])
{
    Point point1 = Point(1,1);
    Point point2 = Point(3,8);

    vector<Point> pointList = {Point(1,2), Point(2,2), Point(3,6), Point(3,8)};

    findKNearestPoint(pointList, 3, point2);
}