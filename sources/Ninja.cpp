#include "Ninja.hpp"

using namespace ariel;
using namespace std;

void Ninja::move(Character* other) {
    this->loc = Point::moveTowards(this->loc, other->getLocation(), this->speed);
}
void Ninja::slash(Character* other) {
    if (other == this) {
        throw runtime_error("no self harm");
    }
    if (this->isAlive()) {
        if (this->getLocation().distance(other->getLocation()) < 1) {
            other->hit(40);
        }
    }
    else {
        throw std::runtime_error("cannot attack while DEAD");
    }
}
string Ninja::print() {
    return "N" + Character::print();
}
void Ninja::attack(Character *other) {
    if (other == nullptr) {
        throw std::invalid_argument("target cannot be a nullptr");
    }
    if (!Character::isAlive()) {
        throw runtime_error("cannot attack while dead");
    }
    else if (!other->isAlive()) {
        throw runtime_error("cannot a dead enemy");
    }
    if (this->getLocation().distance(other->getLocation()) < 1) {
        this->slash(other);
    }
    else {
        this->move(other);
    }
}