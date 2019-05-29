#include "statusseed.h"
#include "combatant/combatant.h"

statusSeed::statusSeed(cptr sourceIn, cptr bearerIn, int baseIn, int bonusIn, int initialIn)
    :   status(sourceIn, bearerIn, "SEED", 300)
{
    refreshed = true;
    count = 1;

    base = baseIn;
    bonus = bonusIn;
    initial = initialIn;
}

statusSeed::~statusSeed()
{

}

bool statusSeed::end()
{
    if(refreshed == false)
        return true;
    refreshed = false;
    return false;
}

bool statusSeed::push(status *in)
{
    if( tag == in->getTag() )
    {
        ++count;
        refreshed = true;
        in->setPFail(true);
        std::cout << "push,   in pushfail" << in->pushFail() << std::endl;
    }
    else if( in->getTag() == "sowerHeal")
    {
        if(count > 1)
            source->healing(bearer->heal( base + bonus*(count-1) ));
        else
            source->healing( bearer->heal( initial ) );
    }
    return false;
}

void statusSeed::print()
{
    std::cout << "SEED.  COUNT: " << count << std::endl;
}

