#include "combatant.h"

#include "status/status.h"

combatant::combatant(std::string *logIn, std::string nameIn, int healthIn, int healthMaxIn, int speedIn)
{
    log = logIn;

    name = nameIn;

    health = healthIn;

    healthMax = healthMaxIn;

    speed = speedIn;

    moves = 1;
}

combatant::~combatant()
{
    for(int i=0; i<statuses.size(); ++i)
        delete statuses[i];
}

int combatant::chooseAction(char choice, combatant *target)
{
    begin();
    end();
    return false;
}

int combatant::damage(int dmgHealth, int dmgHealthMax)
{
    std::stable_sort(statuses.begin(), statuses.end());
    for(int i=0; i<statuses.size(); ++i)
        if(statuses[i]->damage(dmgHealth))
        {
            delete statuses[i];
            statuses.erase(statuses.begin()+i);
        }

    int healthInitial = health;
    health -= dmgHealth;
    healthMax -= dmgHealthMax;
    if(health>healthMax)
        health=healthMax;

    std::stable_sort(statuses.begin(), statuses.end());
    for(int i=0; i<statuses.size(); ++i)
        if(statuses[i]->damaged(healthInitial-health))
        {
            delete statuses[i];
            statuses.erase(statuses.begin()+i);
        }
    log->append(name);
    log->append(":  Recieved ");
    log->append("(some damage)");
    log->append(" damage.\n");
    return healthInitial-health;
}

int combatant::heal(int healing, int healMax)
{
    healthMax += healMax;

    int healthInitial = health;
    health+=healing;
    if(health>healthMax)
        health=healthMax;
    return health-healthInitial;
}

int combatant::begin()
{
    --moves;

    std::stable_sort(statuses.begin(), statuses.end());
    for(int i=0; i<statuses.size(); ++i)
        if(statuses[i]->begin())
        {
            delete statuses[i];
            statuses.erase(statuses.begin()+i);
        }
    adjustCooldowns(1);
}

int combatant::end()
{
    std::stable_sort(statuses.begin(), statuses.end());
    for(int i=0; i<statuses.size(); ++i)
        if(statuses[i]->end())
        {
            delete statuses[i];
            statuses.erase(statuses.begin()+i);
        }
}

int combatant::round()
{
    std::stable_sort(statuses.begin(), statuses.end());
    for(int i=0; i<statuses.size(); ++i)
        if(statuses[i]->round())
        {
            delete statuses[i];
            statuses.erase(statuses.begin()+i);
        }

    moves = 1;

    return 1;
}

int combatant::channel(bool begin)
{
    if(begin)
    {
        std::stable_sort(statuses.begin(), statuses.end());
        for(int i=0; i<statuses.size(); ++i)
        {
            if(statuses[i]->channeling())
            {
                delete(statuses[i]);
                statuses.erase(statuses.begin()+i);
            }
        }
    }
    else
    {
        std::stable_sort(statuses.begin(), statuses.end());
        for(int i=0; i<statuses.size(); ++i)
        {
            if(statuses[i]->channel(1))
            {
                delete(statuses[i]);
                statuses.erase(statuses.begin()+i);
            }
        }
    }
    return 1;
}

int combatant::damaging(int amount)
{
    std::stable_sort(statuses.begin(), statuses.end());
    for(int i=0; i<statuses.size(); ++i)
        if(statuses[i]->damaging(amount))
        {
            delete(statuses[i]);
            statuses.erase(statuses.begin()+i);
        }
    log->append(name);
    log->append(":  Dealt ");
    log->append("(some damage)");
    log->append(" damage.\n");
    return 1;
}

int combatant::healing(int amount)
{
    log->append(name);
    log->append(":  Healt ");
    log->append("(some health)");
    log->append(" health.\n");
}

int combatant::pushStatus(status *in)
{
    std::stable_sort(statuses.begin(), statuses.end());
    for(int i=0; i<statuses.size(); ++i)
        if(statuses[i]->push(in))
        {
            delete(statuses[i]);
            statuses.erase(statuses.begin()+i);
        }
    if(!(in->pushFail()))
        statuses.push_back(in);
    else
        delete in;
    return 1;
}

void combatant::print()
{
    std::cout << name << std::endl;
    for(int i=0; i<(health/3); ++i)
        std::cout << "X";
    if(health%3 == 2)
        std::cout << "x";
    else if(health%3 == 1)
        std::cout << ".";
    for(int i=0; i<((healthMax-health)/3); ++i)
        std::cout << "_";
    std::cout << std::endl;

    if(statuses.size())
        std::cout << "Statuses:" <<std::endl;
    std::stable_sort(statuses.begin(), statuses.end());
    for(int i=0; i<statuses.size(); ++i)
    {
        std::cout << "   ";
        statuses[i]->print();
    }
    std::cout << std::endl;
}

void combatant::printActions()
{

}

int combatant::getHealth(bool max)
{
    if(max)
        return healthMax;
    else
        return health;
}

int combatant::getSpeed()
{
    return speed;
}

int combatant::getReady()
{
    return moves;
}

int combatant::getMana()
{
    return false;
}

int combatant::adjustMana(int adjustment)
{
    return false;
}

bool combatant::adjustCooldowns(int adjustment)
{
   return false;
}
