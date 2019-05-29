#include "statushot.h"

#include "combatant/combatant.h"

statusHoT::statusHoT(cptr sourceIn, cptr bearerIn, int amountIn, int durationIn, std::string tagIn)
    :   status(sourceIn, bearerIn, tagIn)
{
    amount = amountIn;
    duration = durationIn;
}

statusHoT::~statusHoT()
{

}

bool statusHoT::round()
{
    int healt = bearer->heal(amount);
    source->healing(amount);
    if(--duration == 0)
        return true;
    return false;
}

bool statusHoT::push(status *in)
{
    if( tag == in->getTag() )
        return true;
    return false;
}

void statusHoT::print()
{
    std::cout << "HOT.  AMOUNT: " << amount << "  DURATION: " << duration << std::endl;
}
