#include "statusbleed.h"

#include "combatant/combatant.h"

statusBleed::statusBleed(combatant *sourceIn, combatant *bearerIn, int amountIn, int durationIn)
    : status(sourceIn, bearerIn, "BLEED")
{
    amount = amountIn;
    duration = durationIn;
}

statusBleed::~statusBleed()
{

}

bool statusBleed::round()
{
    int dealt = bearer->damage(amount);
    source->damaging(dealt);
    if(--duration == 0)
        return true;
    return false;
}

void statusBleed::print()
{
    std::cout << "BLEED.  AMOUNT: " << amount << "   DURATION: " << duration << std::endl;
}

