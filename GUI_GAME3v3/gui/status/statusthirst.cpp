#include "statusthirst.h"

#include "combatant/combatant.h"

statusThirst::statusThirst(combatant *bearerIn, combatant *sourceIn, int durationIn, int amountIn)
    : status(sourceIn, bearerIn, "Thirst", 250)
{
    duration = durationIn+1;
    amount = amountIn;
    active=false;
}

statusThirst::~statusThirst()
{

}

bool statusThirst::begin()
{
    active = true;
    return false;
}

bool statusThirst::round()
{
        if(active && --duration==0)
            return true;
        return false;
}

bool statusThirst::damaging(int dealt)
{
    if(active && dealt>0)
    {
        std::cout << "THIRST IS ACTIVATING" << std::endl;
        if(amount)
            bearer->heal(amount);
        else
            bearer->heal(dealt);
    }
    std::cout << "THIRST WAS NOT ACTIVE AND DID NOT ACTIVATE" << std::endl;
    return false;
}

void statusThirst::print()
{
    std::cout << "THIRST.  AMOUNT: " << amount << "   DURATION: " << duration << std::endl;
}

