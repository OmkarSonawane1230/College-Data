// ======================================================================
// Name        : assign_5.cpp
// Author      : Omkar Sonawane
// ======================================================================

#include <iostream>
#include <graphics.h>
#include <cmath>

class Fractal {
private:
    int iterations;

public:
    void drawKochCurve(int it, int x1, int y1, int x5, int y5);
    void draw();
};

void Fractal::drawKochCurve(int it, int x1, int y1, int x5, int y5) {
    if (it == 0) {
        line(x1, y1, x5, y5);
    } else {
        int deltaX = x5 - x1;
        int deltaY = y5 - y1;

        int x2 = x1 + deltaX / 3;
        int y2 = y1 + deltaY / 3;

        int x3 = (int)(0.5 * (x1 + x5) + sqrt(3) * (y1 - y5) / 6);
        int y3 = (int)(0.5 * (y1 + y5) + sqrt(3) * (x5 - x1) / 6);

        int x4 = x1 + 2 * deltaX / 3;
        int y4 = y1 + 2 * deltaY / 3;

        drawKochCurve(it - 1, x1, y1, x2, y2);
        drawKochCurve(it - 1, x2, y2, x3, y3);
        drawKochCurve(it - 1, x3, y3, x4, y4);
        drawKochCurve(it - 1, x4, y4, x5, y5);
    }
}

void Fractal::draw() {
    std::cout << "\n\tEnter the number of iterations: ";
    std::cin >> iterations;

    // Define the points for the Koch curve
    drawKochCurve(iterations, 280, 280, 150, 20); // Side 1
    drawKochCurve(iterations, 20, 280, 280, 280); // Side 2
    drawKochCurve(iterations, 150, 20, 20, 280); // Side 3
}

int main() {
    Fractal fractal;
    int gm, gd = DETECT;
    initgraph(&gd, &gm, NULL);

    setbkcolor(WHITE);
    cleardevice();
    setcolor(BLACK);

    fractal.draw();
    
    getch();
    closegraph();
    return 0;
}


//         Enter the number of iterations: 3