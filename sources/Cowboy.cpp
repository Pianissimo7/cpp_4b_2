#include "Cowboy.hpp"

using namespace ariel;
using namespace std;

void Cowboy::shoot(Character* target) {
    if (this->isAlive() && this->hasboolets()) {
        target->hit(10);
    }
}
bool Cowboy::hasboolets() {
    return this->bullets > 0;
}
void Cowboy::reload() {
    this->bullets = 6;
}
void Cowboy::print() {
    cout << "C" << Character::print() << endl;
}
void Cowboy::attack(Character * other) {
    if (!this->hasboolets()) {
        this->reload();
    }
    else {
        this->shoot(other);
    }
}