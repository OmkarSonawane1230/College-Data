// ======================================================================
// Name        : assign_4.cpp
// Author      : Omkar Sonawane
// ======================================================================

#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <iostream>

using namespace std;

class Point {
public:
    float x, y;

    Point(float x = 0, float y = 0) : x(x), y(y) {}

    void translate(float tx, float ty) {
        x += tx;
        y += ty;
    }

    void scale(float sx, float sy) {
        x *= sx;
        y *= sy;
    }

    void rotate(float angle, Point center) {
        float radians = angle * M_PI / 180;
        float translatedX = x - center.x;
        float translatedY = y - center.y;

        x = translatedX * cos(radians) - translatedY * sin(radians) + center.x;
        y = translatedX * sin(radians) + translatedY * cos(radians) + center.y;
    }
};

class Shape {
private:
    Point* points;
    int numPoints;

public:
    Shape(Point* pts, int n) : points(pts), numPoints(n) {}

    Point getCentroid() {
        float sumX = 0, sumY = 0;
        for (int i = 0; i < numPoints; ++i) {
            sumX += points[i].x;
            sumY += points[i].y;
        }
        return Point(sumX / numPoints, sumY / numPoints);
    }

    void draw() {
        cleardevice(); // Clear the screen before drawing
        for (int i = 0; i < numPoints; ++i) {
            int nextIndex = (i + 1) % numPoints; // Wrap around to create a closed shape
            line(points[i].x, points[i].y, points[nextIndex].x, points[nextIndex].y);
        }
    }

    void transform(float tx, float ty, float scaleX, float scaleY, float angle) {
        // Get the centroid before any transformations
        Point center = getCentroid();

        // Apply scaling first
        for (int i = 0; i < numPoints; ++i) {
            points[i].scale(scaleX, scaleY);
        }

        // Then apply rotation around the centroid of the scaled shape
        for (int i = 0; i < numPoints; ++i) {
            points[i].rotate(angle, center);
        }

        // Finally apply translation
        for (int i = 0; i < numPoints; ++i) {
            points[i].translate(tx, ty);
        }
    }
};

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Translate\n";
    cout << "2. Scale\n";
    cout << "3. Rotate\n";
    cout << "4. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    // Initialize graphics
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    setbkcolor(WHITE);
    cleardevice();
    setcolor(BLACK);

    // Define a simple shape (triangle)
    Point trianglePoints[] = {
        Point(200, 100),
        Point(300, 300),
        Point(100, 300)
    };
    Shape triangle(trianglePoints, 3);

    triangle.draw(); // Draw the original triangle

    int choice;
    float tx = 0, ty = 0;
    float scaleX = 1.0, scaleY = 1.0, angle = 0.0;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: // Translate
                cout << "Enter translation (tx ty): ";
                cin >> tx >> ty;
                break;
            case 2: // Scale
                cout << "Enter scaling factors (sx sy): ";
                cin >> scaleX >> scaleY;
                break;
            case 3: // Rotate
                cout << "Enter rotation angle: ";
                cin >> angle;
                break;
            case 4: // Exit
                closegraph();
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
                continue;
        }

        // Apply transformations
        triangle.transform(tx, ty, scaleX, scaleY, angle);
        triangle.draw(); // Draw the transformed triangle

        // Reset translations for the next iteration
        tx = 0; 
        ty = 0; 
    }

    getch(); // Wait for a key press
    closegraph(); // Close the graphics window
    return 0;
}


/*


Menu:
1. Translate
2. Scale
3. Rotate
4. Exit
Choose an option: 1
Enter translation (tx ty): 100 20

Menu:
1. Translate
2. Scale
3. Rotate
4. Exit
Choose an option: 3
Enter rotation angle: 45

Menu:
1. Translate
2. Scale
3. Rotate
4. Exit
Choose an option: 2
Enter scaling factors (sx sy): .7 .9

Menu:
1. Translate
2. Scale
3. Rotate
4. Exit
Choose an option:

*/