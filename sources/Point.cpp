#include "Point.hpp"

using namespace ariel;
using namespace std;

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}
Point::Point(Point *p) {
    this->x = p->getX();
    this->y = p->getY();
}
double Point::distance(Point other) {
    return sqrt(pow(this->x - other.getX(), 2) + pow(this->y - other.getY(), 2));
}
void Point::print() {
    cout << this->x << " " << this->y << endl;
}
Point Point::moveTowards(Point src, Point dest, double dist) {
    double deltax = (dest.getX() - src.getX());
    double deltay = (dest.getY() - src.getY());
    double size = sqrt(pow(deltax, 2) + pow(deltay, 2));
    
    if (size == 0) {
        return  Point(&dest);
    }
    
    deltax /= size;
    deltay /= size;
    deltax *= dist;
    deltay *= dist;

    if (size < dist) {
        return Point(&dest);
    } 

    return Point(src.getX() + deltax, src.getY() + deltay);
}
double Point::getX() {
    return this->x;
}
double Point::getY() {
    return this->y;
}