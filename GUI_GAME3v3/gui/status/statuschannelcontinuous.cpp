#include "statuschannelcontinuous.h"

statusChannelContinuous::statusChannelContinuous(combatant *sourceIn, combatant *targetIn, actionptr actionIn, int durationIn, bool startChannelled)
    :   status(sourceIn,sourceIn, "CONT CHANNELING")
{
    target = targetIn;
    action = actionIn;
    duration = durationIn;
    if(startChannelled)
    {
        channelled = true;
        --duration;
        //-----------------
    }
    else
        channelled = false;
}

statusChannelContinuous::~statusChannelContinuous()
{

}

bool statusChannelContinuous::begin()
{
    channelled = false;
    return false;
}

bool statusChannelContinuous::end()
{
    if(!channelled)
        return true;
    return true;
}

bool statusChannelContinuous::channel(int amount)
{
    if(amount > duration)
        amount = duration;
    for(int i=amount; i>0; --i)
        action(source, target);
    duration-=amount;
    if(amount<=0)
        return true;
    channelled = true;
    return false;
}

void statusChannelContinuous::print()
{
    std::cout << "CONTINUOUS CHANNEL.  DURATION: " << duration << std::endl;
}

