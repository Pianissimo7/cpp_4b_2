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
    return sqrt(pow((this->x - other.getX()), 2) + pow((this->y - other.getY()), 2));
}
void Point::print() {
    cout << this->x << " " << this->y << endl;
}
Point Point::moveTowards(Point src, Point dest, double dist) {
    if (dist < 0) {
        throw std::invalid_argument("distance cannot be lower than 0");
    }
    double dx = dest.getX() - src.getX();
    double dy = dest.getY() - src.getY();

    double length = std::sqrt(dx * dx + dy * dy);

    double ratio = dist / length;

    double newX = src.getX() + ratio * dx;
    double newY = src.getY() + ratio * dy;
    if (length < dist) {
        return Point(&dest);
    } 
    return Point(newX, newY);
}
double Point::getX() {
    return this->x;
}
double Point::getY() {
    return this->y;
}