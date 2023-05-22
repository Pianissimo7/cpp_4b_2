#include "Team2.hpp"

using namespace ariel;

void Team2::attack(Team *other) {
    if (!Team::leader->isAlive()) {
        Team::leader = Team::get_closest(Team::leader);
        if (!Team::leader->isAlive()) {
            return;
        }
    }
        
    Character * victim = NULL;
    
    for (size_t i = 0 ; i < Team::team.size() ; i++) {
        
        if (victim == NULL || !victim->isAlive()) {
            
            victim = other->get_closest(Team::leader);

            if (!victim->isAlive()) {
                return;
            }
        }
        Team::team.at(i)->attack(victim);
    }
}