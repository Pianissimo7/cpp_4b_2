#include "Cowboy.hpp"

using namespace ariel;
using namespace std;

void Cowboy::shoot(Character* target) {
    if (target == this) {
        throw runtime_error("no self harm");
    }
    if (!this->isAlive()) {
        throw std::runtime_error("cannot shoot while dead");
    }
    if (this->hasboolets()) {
        target->hit(10);
    }
    this->bullets -= 1;
}
bool Cowboy::hasboolets() {
    return this->bullets > 0;
}
void Cowboy::reload() {
    if (!this->isAlive()) {
        throw std::runtime_error("cannot reload while dead");
    }
    this->bullets = 6;
}
void Cowboy::print() {
    cout << "C" << Character::print() << endl;
}
void Cowboy::attack(Character * other) {
    if (other == nullptr) {
        throw std::invalid_argument("target cannot be nullptr");
    }
    if (!Character::isAlive()) {
        throw runtime_error("cannot attack while dead");
    }
    else if (!other->isAlive()) {
        throw runtime_error("cannot attack a dead enemy");
    }
    if (!this->hasboolets()) {
        this->reload();
    }
    else {
        this->shoot(other);
    }
}