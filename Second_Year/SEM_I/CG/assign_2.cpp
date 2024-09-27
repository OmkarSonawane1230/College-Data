// ======================================================================
// Name        : assign_2.cpp
// Author      : Omkar Sonawane
// ======================================================================

#include <graphics.h>
#include <iostream>
using namespace std;

const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

class CohenSutherland {
    int x_max, y_max, x_min, y_min;

    int computeCode(double x, double y) {
        int code = INSIDE;

        if (x < x_min) code |= LEFT;
        else if (x > x_max) code |= RIGHT;
        if (y < y_min) code |= BOTTOM;
        else if (y > y_max) code |= TOP;

        return code;
    }

public:
    CohenSutherland(int x_mn, int y_mn, int x_mx, int y_mx) {
        x_max = x_mx;        
        y_max = y_mx;        
        x_min = x_mn;        
        y_min = y_mn;            
    }

    void drawClipRectangle() {
        setcolor(BLACK);
        rectangle(x_min, y_min, x_max, y_max); // Draw clipping rectangle
    }

    void displayUnclippedLine(double x1, double y1, double x2, double y2) {
        setcolor(BLUE);
        line(x1, y1, x2, y2); // Draw the unclipped line
    }

    void clipLine(double x1, double y1, double x2, double y2) {
        int code1 = computeCode(x1, y1);
        int code2 = computeCode(x2, y2);
        bool accept = false;

        while (true) {
            if ((code1 == 0) && (code2 == 0)) {
                accept = true;
                break;
            } else if (code1 & code2) {
                break; // Both endpoints outside in the same region
            } else {
                int code_out;
                double x, y;

                if (code1 != 0) code_out = code1;
                else code_out = code2;

                if (code_out & TOP) {
                    x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                    y = y_max;
                } else if (code_out & BOTTOM) {
                    x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                    y = y_min;
                } else if (code_out & RIGHT) {
                    y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                    x = x_max;
                } else if (code_out & LEFT) {
                    y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                    x = x_min;
                }

                if (code_out == code1) {
                    x1 = x;
                    y1 = y;
                    code1 = computeCode(x1, y1);
                } else {
                    x2 = x;
                    y2 = y;
                    code2 = computeCode(x2, y2);
                }
            }
        }

        if (accept) {
            setcolor(RED);
            line(x1, y1, x2, y2);
        } else {
            cout << "Line rejected" << endl;
        }
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    setbkcolor(WHITE);
    cleardevice();

    CohenSutherland clippingWindow(100, 50, 300, 200);
    clippingWindow.drawClipRectangle();

     double lines[][4] = {
        {150, 60, 350, 180}, // Partially inside
        {90, 90, 200, 150},  // Fully inside
        {200, 30, 350, 70},  // Partially outside
        {50, 200, 400, 250}, // Fully outside
        {100, 100, 300, 50}, // Partially inside
        {75, 40, 350, 40},   // Fully outside, but horizontally intersecting the rectangle
        {110, 70, 290, 170}, // Fully inside
        {120, 250, 280, 150},// Partially outside
        {400, 100, 200, 90}, // Fully outside, but intersects the rectangle
        {150, 250, 150, 10}  // Fully outside vertically
    };

    // Draw unclipped lines
    for (auto& line : lines) {
        clippingWindow.displayUnclippedLine(line[0], line[1], line[2], line[3]);
    }

    delay(2000); // Wait for 2 seconds
    cleardevice();

    // Redraw the clipping rectangle after clearing
    clippingWindow.drawClipRectangle();

    // Clip lines and only draw clipped lines
    for (auto& line : lines) {
        clippingWindow.clipLine(line[0], line[1], line[2], line[3]);
    }

    getch(); 
    closegraph();
    return 0;
}
