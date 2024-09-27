// ======================================================================
// Name        : assign_1.cpp
// Author      : Omkar Sonawane
// ======================================================================

#include <graphics.h>
#include <iostream>
using namespace std;

class Polygons {
    int x[10]; // Array to store x coordinates (up to 10 edges)
    int y[10]; // Array to store y coordinates (up to 10 edges)
    int edges; // Number of edges

public:
    Polygons(int* xCoords, int* yCoords, int edgeCount) {
		edges = edgeCount;

        for (int i = 0; i < edges; i++) {
            x[i] = xCoords[i];
            y[i] = yCoords[i];
        }
    }

    void scanFill() {
		setcolor(BLACK);
        for (int i = 0; i < edges; i++) {
            int next = (i + 1) % edges;
            line(x[i], y[i], x[next], y[next]);
        }

        int i, j, temp;
        int xmin = getmaxx(), xmax = 0;

        // Find the minimum and maximum x-coordinates of the polygon
        for (i = 0; i < edges; i++) {
            if (x[i] < xmin)
                xmin = x[i];
            if (x[i] > xmax)
                xmax = x[i];
        }

        // Scan each scan-line within the polygon's vertical extent
		// Scan through the height of the screen
        for (i = 0; i <= getmaxy(); i++) { 
            int interPoints[20]; // Increased for more intersections
            int count = 0;

            for (j = 0; j < edges; j++) {
                int next = (j + 1) % edges;

                // Check if the current edge intersects with the scan line
                if ((y[j] > i && y[next] <= i) || (y[next] > i && y[j] <= i)) {
                    // Calculate x intersection point
                    int xIntersection = x[j] + (i - y[j]) * (x[next] - x[j]) / (y[next] - y[j]);
                    interPoints[count++] = xIntersection;
                }
            }

            // Insertion Sort for sorting the intersection points
            for (int k = 1; k < count; k++) {
                int key = interPoints[k];
                int m = k - 1;

                while (m >= 0 && interPoints[m] > key) {
                    interPoints[m + 1] = interPoints[m];
                    m--;
                }
                interPoints[m + 1] = key;
            }

			setcolor(MAGENTA);

            // Fill the pixels between pairs of intersection points
            for (j = 0; j < count; j += 2) {
                if (j + 1 < count) {
                    // Draw the filling line
                    line(interPoints[j], i, interPoints[j + 1], i);
                    delay(10);
                }
            }
        }
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    setbkcolor(WHITE);
	cleardevice();

    int x[] = {200, 350, 300, 350, 200};
    int y[] = {100, 150, 200, 350, 200};
    int edges = sizeof(x) / sizeof(x[0]);

    Polygons polygon(x, y, edges);
    polygon.scanFill();

    getch();
    closegraph();
    return 0;
}


// Commands to Execute the Program Properly

// g++ file_name.cpp -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
// .\a.out