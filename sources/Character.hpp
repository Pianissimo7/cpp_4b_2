#pragma once

#include <string>
#include "Point.hpp"
#include <iostream>

using namespace std;

namespace ariel {
    class Character {
        public:
            Character(string name, Point location, int hit_points) : name(name), loc(location), health_points(hit_points), is_playing(false) {};
            bool isAlive();
            double distance(Character *other);
            void hit(int damage);
            string getName();
            Point getLocation();
            string print();
            virtual void attack(Character *other);
            bool get_playing();
            void set_playing(bool is_playing);
            
        private:
            bool is_playing;
            int health_points;
            string name;
        protected:
            Point loc;

    };
}