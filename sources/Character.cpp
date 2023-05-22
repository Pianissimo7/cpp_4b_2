#include "Character.hpp"

using namespace ariel;

bool Character::isAlive() {
    return this->health_points <= 0;
}
double Character::distance(Character *other) {
    return this->loc.distance(other->getLocation());
}
void Character::hit(int damage) {
    this->health_points -= damage;
}
string Character::getName() {
    return this->name;
}
Point Character::getLocation() {
    return this->loc;
}
string Character::print() {
    if (this->isAlive()) {
        return "" + this->name + " " + to_string(this->health_points) + " " + to_string(this->loc.getX()) + " " + to_string(this->loc.getY());
    }
    else {
        return "(" + this->name + ") " + to_string(this->health_points) + " " + to_string(this->loc.getX()) + " " + to_string(this->loc.getY());
    }
}
void Character::attack(Character *other) {

}
