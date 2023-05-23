#include "Team.hpp"

using namespace ariel;

Team::Team(Character* leader) : team() {
    this->leader = leader;
    this->add(leader);
}
Team::~Team() {
    for (size_t i = 0 ; i < this->team.size() ; i++) {
        delete(this->team.at(i));
    }
}
void Team::add(Character* other) {
    if (other->get_playing()) {
        throw runtime_error("player is already playing");
    }
    if (this->team.size() < 10) {
        this->team.push_back(other);
        other->set_playing(true);
    }
    else {
        throw std::runtime_error("max sized team reached");
    }
}
void Team::attack(Team* other) {
    if (other == nullptr) {
        throw std::invalid_argument("team cannot be nullptr");
    }
    if (other->stillAlive() == 0) {
        throw std::runtime_error("cannot attack a dead team");
    }
    if (!this->leader->isAlive()) {
        this->leader = this->get_closest(this->leader);
        if (!this->leader->isAlive()) {
            return;
        }
    }
    for (int i = 0; i < 2 ; i++) {
        
        Character * victim = NULL;
        
        for (size_t j = 0 ; j < this->team.size() ; j++) {
            
            Cowboy * is_cowboy = dynamic_cast<Cowboy *>(this->team.at(j));
            
            if (victim == NULL || !victim->isAlive()) {
                
                victim = other->get_closest(this->leader);

                if (!victim->isAlive()) {
                    return;
                }
            }
            if (is_cowboy && i == 0 && this->team.at(j)->isAlive()) {    
                this->team.at(j)->attack(victim);
            }
            else if (!is_cowboy && i == 1 && this->team.at(j)->isAlive()) {
                this->team.at(j)->attack(victim);
            }
        }
    }
}
Character * Team::get_closest(Character *c) {
    double min_dist = std::numeric_limits<double>::max();
    size_t closest_char_index = 0;
    for (size_t i = 0 ; i < this->team.size() ; i++) {
        if (this->team.at(i) != c && this->team.at(i)->isAlive()) {
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
    int count = 0;
    for (size_t i = 0 ; i < this->team.size() ; i++) {
        if (this->team.at(i)->isAlive()) {
            count++;
        }
    }
    return count;
}
void Team::print() {
    this->leader->getLocation().print();

}