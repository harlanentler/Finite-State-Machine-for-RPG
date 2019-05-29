#include "statusleyline.h"
#include "combatant/combatant.h"

statusLeyline::statusLeyline(combatant *sourceIn, combatant *targetIn, bool startChannelled)
    :   status(sourceIn,sourceIn,"Leyline")
{
    ley=1;
    leyMax=3;
    if(startChannelled)
    {
        channelled = true;
        source->adjustMana(ley++);
    }
    else
        channelled = false;
}

statusLeyline::~statusLeyline()
{

}

bool statusLeyline::begin()
{
    channelled = false;
    return false;
}

bool statusLeyline::end()
{
    if(!channelled)
        return true;
    return false;
}

bool statusLeyline::channel(int amount)
{
    std::cout << "IN LEYCHANNEL" << std::endl;
    source->adjustMana(ley++);
    if(ley>3)
        return true;
    return false;
}

void statusLeyline::print()
{
    std::cout << "LEYLINE.  DURATION: " << ((3+1)-ley) << std::endl;
}

