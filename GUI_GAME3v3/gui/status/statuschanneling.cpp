#include "statuschanneling.h"

#include "combatant/combatant.h"

statusChanneling::statusChanneling(combatant *sourceIn, combatant *targetIn, actionptr actionIn, int durationIn, bool startChannelled)
    :   status(sourceIn, sourceIn, "CHANNELING")
{
    target = targetIn;
    action = actionIn;
    duration = durationIn;
    if(startChannelled)
    {
        channelled = true;
        --duration;
    }
    else
        channelled = false;
}

statusChanneling::~statusChanneling()
{

}

bool statusChanneling::begin()
{
    //set actions to 'channel' and 'cancel'
    channelled = false;
    return false;
}

bool statusChanneling::end()

{
    if(!channelled)
        return true;
    return false;
}

bool statusChanneling::channel(int amount)
{
    duration-=amount;
    if(duration<=0)
    {
        action(source, target);
        return true;
    }
    channelled = true;
    return false;
}

void statusChanneling::print()
{
    std::cout << "CHANNELING.  DURATION: " << duration << std::endl;
}

