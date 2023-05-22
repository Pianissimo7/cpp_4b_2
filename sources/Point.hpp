#pragma once

#include <cmath>
#include <iostream>

namespace ariel {
    class Point {
        public:
            Point(double x, double y);
            Point(Point *p);
            double distance(Point other);
            void print();
            static Point moveTowards(Point src, Point dest, double dist);
            double getX();
            double getY();
        private:
            double x;
            double y;
        
    };    
}