#include "Team.hpp"

using namespace ariel;

Team::Team(Character* leader) {
    this->team.push_back(leader);
    this->leader = leader;
}
Team::~Team() {
    for (size_t i = 0 ; i < this->team.size() ; i++) {
        delete(this->team.at(i));
    }
}
void Team::add(Character* other) {
    this->team.push_back(other);
}
void Team::attack(Team* other) {
    if (!this->leader->isAlive()) {
        this->leader = this->get_closest(this->leader);
        if (!this->leader->isAlive()) {
            return;
        }
    }
    for (int i = 0; i < 2 ; i++) {
        
        Character * victim = NULL;
        
        for (size_t i = 0 ; i < this->team.size() ; i++) {
            
            Cowboy * is_cowboy = dynamic_cast<Cowboy *>(this->team.at(i));
            
            if (victim == NULL || !victim->isAlive()) {
                
                victim = other->get_closest(this->leader);

                if (!victim->isAlive()) {
                    return;
                }
            }
            if (is_cowboy && i == 0) {    
                this->team.at(i)->attack(victim);
            }
            else if (!is_cowboy && i == 1) {
                this->team.at(i)->attack(victim);
            }
        }
    }
}
Character * Team::get_closest(Character *c) {
    double min_dist = std::numeric_limits<double>::max();
    size_t closest_char_index = 0;
    for (size_t i = 0 ; i < this->team.size() ; i++) {
        if (this->team.at(i) != c) {
            double dist = this->team.at(i)->getLocation().distance(c->getLocation());
            if (dist < min_dist) {
                min_dist = dist;
                closest_char_index = i;
            }
        }
    }
    return this->team.at(closest_char_index);
}
int Team::stillAlive() {
    return 0;
}
void Team::print() {

}