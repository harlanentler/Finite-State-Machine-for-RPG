#include "statusshield.h"

statusShield::statusShield(cptr sourceIn, cptr bearerIn, int durationIn, int shieldIn)
    :   status(sourceIn, bearerIn, "SHIELD")
{
    duration = durationIn;
    shield = shieldIn;
}

statusShield::~statusShield()
{
    
}

bool statusShield::damage(int &amount)
{
    if(shield>amount)
    {
        shield-=amount;
        amount=0;
        return false;
    }
    amount-=shield;
    return true;
}

bool statusShield::round()
{
    if(--duration==0)
        return true;
    return false;
}

void statusShield::print()
{
    std::cout << "SHIELD.  AMOUNT: " << shield << " DURATION: " << duration << std::endl;
}

