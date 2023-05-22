#pragma once

#include <string>
#include "Point.hpp"
#include <iostream>

using namespace std;

namespace ariel {
    class Character {
        public:
            Character(string name, Point location, int hit_points) : name(name), loc(location), health_points(hit_points) {};
            bool isAlive();
            double distance(Character *other);
            void hit(int damage);
            string getName();
            Point getLocation();
            string print();
            virtual void attack(Character *other);
            
        private:
            int health_points;
            string name;
        protected:
            Point loc;

    };
}