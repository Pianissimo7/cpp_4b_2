#pragma once

#include <vector>
#include <limits.h>
#include <stdexcept>
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"

using namespace std;

namespace ariel {
    class Team {
        public:
            Team(Character* leader);
            ~Team();
            void add(Character* other);
            virtual void attack(Team* other);
            int stillAlive();
            void print();
            Character * get_closest(Character *c);
        protected:
            vector<Character *> team;
            Character * leader;
    };
}