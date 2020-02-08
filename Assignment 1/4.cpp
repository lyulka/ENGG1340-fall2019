#include <iostream>
#include <vector>
#include <unistd.h>
using namespace std;

// Task 4 - Bounding Boxes

struct point {
    double x;
    double y;
};

void printPoint(point p) {
    cout << p.x << " " << p.y;
}

void printPoints(vector<point> points) {
    for (int i = 0; i < points.size(); i++)
        cout << points[i].x << " " << points[i].y << endl;
}

int main() {
    
    const string allModes = "RCP#";
    vector<point> points;
    char mode;

    do {
        cin >> mode;
        if (mode == '#') break;

        point xy;
        double w, h;
        switch (mode) {
            case ('R'):
                cin >> xy.x >> xy.y
                    >> w >> h;

                // adding all four corner-points of the rectangle to points vector
                xy.x -= w / 2; xy.y -= h / 2;
                points.push_back(xy);
                xy.x += w;
                points.push_back(xy);
                xy.y += h;
                points.push_back(xy);
                xy.x -= w;
                points.push_back(xy);   
                break;
            case ('C'):
                double radius;
                cin >> xy.x >> xy.y
                    >> radius;
                
                // adding all four corner-points of the minimum size square that
                // encompasses the circle fully to points vector
                xy.x += radius; xy.y += radius;
                points.push_back(xy);
                xy.x -= radius * 2;
                points.push_back(xy);
                xy.y -= radius * 2;
                points.push_back(xy);
                xy.x += radius * 2;
                points.push_back(xy);
                break;
            case ('P'): 
                int n; // number of points
                cin >> n;

                double pX, pY;
                double minX, maxX;
                double minY, maxY;

                cin >> pX >> pY;

                minX = pX; // leftmost X coord
                maxX = pX; // rightmost X coord
                minY = pY; // bottommost Y coord
                maxY = pY; // topmost Y coord

                // finding min and max x and y respectively
                // by comparison.
                for (int c = 0; c < n - 1; c++) {
                    cin >> pX >> pY;

                    if (pX < minX)
                        minX = pX;
                    else if (pX > maxX)
                        maxX = pX;
                    
                    if (pY < minY) 
                        minY = pY;
                    else if (pY > maxY)
                        maxY = pY;
                }

                // using min and max x and y to form a minimum size
                // rectangle that encompasses all of the points.
                xy.x = minX; xy.y = minY;
                points.push_back(xy);
                xy.x = minX; xy.y = maxY;
                points.push_back(xy);
                xy.x = maxX; xy.y = maxY;
                points.push_back(xy);
                xy.x = maxX; xy.y = minY;
                points.push_back(xy);
                break;
        }

    } while (allModes.find(mode) != string::npos);

    // printPoints(points); DEBUG purposes.

    // These store the extreme left, bottom, right, and top coordinate respectively
    double coordLeft = points[0].x;
    double coordRight = points[0].x;
    double coordBottom = points[0].y;
    double coordTop = points[0].y;

    for (int c = 0; c < points.size(); c++) {
        points[c].x < coordLeft ? coordLeft = points[c].x : coordLeft;
        points[c].x > coordRight ? coordRight = points[c].x : coordRight;
        points[c].y < coordBottom ? coordBottom = points[c].y : coordBottom;
        points[c].y > coordTop ? coordTop = points[c].y : coordTop;
    }

    // These store the bottom left and top right corner of the AABB respectively
    point pointBottom;
    pointBottom.x = coordLeft;
    pointBottom.y = coordBottom;
    point pointTop;
    pointTop.x = coordRight;
    pointTop.y = coordTop;

    // printPoint(pointBottom); DEBUG purposes only.
    // cout << endl;
    // printPoint(pointTop);
    // cout << endl;

    double maxWidth, maxHeight;

    maxWidth = pointTop.x - pointBottom.x;
    maxHeight = pointTop.y - pointBottom.y;

    // getting the point at the center of the AABB
    point maxCenter;
    maxCenter.x = coordLeft + (maxWidth / 2.0);
    maxCenter.y = coordBottom + (maxHeight / 2.0);

    printPoint(maxCenter);
    cout << " " << maxWidth << " " << maxHeight;
}  