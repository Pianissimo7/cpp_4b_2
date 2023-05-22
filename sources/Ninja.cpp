#include "Ninja.hpp"

using namespace ariel;
using namespace std;

void Ninja::move(Character* other) {
    
}
void Ninja::slash(Character* other) {
    if (this->isAlive()) {
        if (this->getLocation().distance(other->getLocation()) <= 1) {
            other->hit(40);
        }
    }
}
void Ninja::print() {
    cout << "N" << Character::print() << endl;
}
void Ninja::attack(Character *other) {
    if (Character::loc.distance(other->getLocation()) <= 1) {
        this->slash(other);
    }
    else {
        Character::loc = loc.moveTowards(Character::loc, other->getLocation(), this->speed);
    }
}