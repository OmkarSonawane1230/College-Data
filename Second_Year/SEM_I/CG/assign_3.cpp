// ======================================================================
// Name        : assign_3.cpp
// Author      : Omkar Sonawane
// ======================================================================

#include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;

class PatternDrawing {
    int x1, y1, x2, y2, x3, y3;
    float side_length;

public:
    PatternDrawing(float length) {
        side_length = length;
        x1 = 200; 
        y1 = 200;
        x2 = x1 + side_length;
        y2 = y1;
        x3 = x1 + side_length / 2;
        y3 = y1 - (sqrt(3) / 2) * side_length;
    }

    void draw() {
        dda(x1, y1, x2, y2);
        dda(x2, y2, x3, y3);
        dda(x3, y3, x1, y1);
    }

    // Method to get the center of the triangle
    void getCenter(int &centerX, int &centerY) {
        centerX = (x1 + x2 + x3) / 3;
        centerY = (y1 + y2 + y3) / 3;
    }

    // Method to calculate the outer radius (circumradius)
    float getOuterRadius() {
        return side_length / sqrt(3);
    }

    // Method to calculate the inner radius (inradius)
    float getInnerRadius() {
        return (side_length * sqrt(3)) / 6;
    }

    // DDA Line Drawing Algorithm
    void dda(int x0, int y0, int x1, int y1) {
        int dx = x1 - x0;
        int dy = y1 - y0;
        int steps = max(abs(dx), abs(dy));

        float xIncrement = dx / (float)steps;
        float yIncrement = dy / (float)steps;

        float x = x0;
        float y = y0;

        for (int i = 0; i <= steps; i++) {
            putpixel(round(x), round(y), BLACK);
            x += xIncrement;
            y += yIncrement;
        }
        delay(500);
    }

    // Drawing Circle using Bresenham's algorithm
    void drawCircle(int centerX, int centerY, float radius, int COLOR) {
        int x = radius, y = 0;
        int decision = 1 - radius;  // Decision variable

        while (x >= y) {
            // Draw all eight octants
            putpixel(centerX + x, centerY + y, COLOR);
            putpixel(centerX + y, centerY + x, COLOR);
            putpixel(centerX - y, centerY + x, COLOR);
            putpixel(centerX - x, centerY + y, COLOR);
            putpixel(centerX - x, centerY - y, COLOR);
            putpixel(centerX - y, centerY - x, COLOR);
            putpixel(centerX + y, centerY - x, COLOR);
            putpixel(centerX + x, centerY - y, COLOR);

            y++;
            
            if (decision <= 0) {
                decision += 2 * y + 1;
            } else {
                x--;
                decision += 2 * (y - x) + 1;
            }
        }
        delay(500);
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    setbkcolor(WHITE);
    cleardevice();

    float side_length;
    cout << "Enter the length of the triangle sides: ";
    cin >> side_length;

    // Create triangle object
    PatternDrawing triangle(side_length);
 
    // Draw the triangle
    triangle.draw();

    // Get center of the triangle
    int centerX, centerY;
    triangle.getCenter(centerX, centerY);

    
    // Draw inner and outer circles
    triangle.drawCircle(centerX, centerY, triangle.getInnerRadius(), 5);
    triangle.drawCircle(centerX, centerY, triangle.getOuterRadius(), 3);

    getch();
    closegraph();
    return 0;
}


//Enter the length of the triangle sides: 200