#include "Circle.h"
using namespace std;
#include "testing/SimpleTest.h"
#include "gmath.h"
#include "strlib.h"

/**
 * TODO: write a method comment
 * constructor
 */
Circle::Circle(double r) {
    this->r = r;
}


/**
 * TODO: write a method comment
 * return the area of the certain circle
 */
double Circle::area() const {
    double ret = PI*r*r;
    return ret;
}

/**
 * TODO: write a method comment
 * returns the distance around the circle
 */
double Circle::circumference() const{
    double len = 2*PI*r;
    return len;
}

/**
 * TODO: write a method comment
 * returns the radius as a real number
 */
double Circle::getRadius() const{
    return r;
}

/**
 * TODO: write a method comment
 */
string Circle::toString() const{
    string result = "";
    result += "Circle{radius=";
    result += realToString(r);
    result += "}";
    return result;
}

/* Provided Tests Below This Line */

PROVIDED_TEST("Simple Example"){
    Circle c(2.5);
    EXPECT_EQUAL(c.getRadius(), 2.5);
    EXPECT_EQUAL(c.circumference(), 2 * PI * 2.5);
    EXPECT_EQUAL(c.area(), PI * 2.5 * 2.5);
    EXPECT_EQUAL(c.toString(), "Circle{radius=2.5}");
}
