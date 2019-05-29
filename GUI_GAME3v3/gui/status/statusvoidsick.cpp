#include "statusvoidsick.h"

#include "combatant/combatant.h"

statusVoidsick::statusVoidsick(combatant *sourceIn, combatant *bearerIn, int damageIn, int durationIn)
    :   status(sourceIn, bearerIn, "Voidsick")
{
    damage = damageIn;
    duration = durationIn;
    wasDamaged = false;
}

statusVoidsick::~statusVoidsick()
{

}

bool statusVoidsick::round()
{
    if(!wasDamaged)
    {
        int dealt = bearer->damage(damage);
        source->damaging(dealt);
    }
    wasDamaged=false;       //was damaged applies only to this round
    if(--duration==0)
        return true;
    return false;
}

bool statusVoidsick::damaged(int amount)
{
    wasDamaged = true;
    return false;
}

void statusVoidsick::print()
{
    std::cout << "VOIDSICK.";
    std::cout << "  DAMAGE: " << damage << "  DURATION: " << duration << std::endl;
}

