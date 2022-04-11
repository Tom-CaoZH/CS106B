#include "Sierpinski.h"
#include "error.h"
using namespace std;

/**
 * Draws a triangle with the specified corners in the specified window. Feel free
 * to edit this function as you see fit to change things like color, fill style,
 * etc. in whatever way you'd like!
 *
 * @param window The window in which to draw the triangle.
 * @param x0 y0 The first corner of the triangle.
 * @param x1 y1 The second corner of the triangle.
 * @param x2 y2 The third corner of the triangle.
 */
void drawTriangle(GWindow& window,
                  double x0, double y0,
                  double x1, double y1,
                  double x2, double y2) {
    window.setColor("black");
    window.fillPolygon({ x0, y0, x1, y1, x2, y2 });
}

void drawSierpinskiTriangle(GWindow& window,
                            double x0, double y0,
                            double x1, double y1,
                            double x2, double y2,
                            int order) {
    if(order < 0) {
        error("The order should be positive!");
        return;
    }
    else if(order == 0) {
        // basic case
        drawTriangle(window,x0,y0,x1,y1,x2,y2);
    }
    else {
        // Then recursive
        double x_mid1 = (x0+x1)/2;
        double y_mid1 = (y0+y1)/2;
        double x_mid2 = (x0+x2)/2;
        double y_mid2 = (y0+y2)/2;
        double x_mid3 = (x1+x2)/2;
        double y_mid3 = (y1+y2)/2;
        order -= 1;
        drawSierpinskiTriangle(window,x0,y0,x_mid1,y_mid1,x_mid2,y_mid2,order);
        drawSierpinskiTriangle(window,x1,y1,x_mid1,y_mid1,x_mid3,y_mid3,order);
        drawSierpinskiTriangle(window,x2,y2,x_mid3,y_mid3,x_mid2,y_mid2,order);
    }
}
