#include "classsower.h"

classSower::classSower(std::string *logIn)
    :   combatant(logIn, SOWER_NAME, SOWER_HEALTH, SOWER_HEALTH, SOWER_SPEED)
{

}

classSower::~classSower()
{

}

int classSower::chooseAction(char choice, cptr target)
{
    switch(choice)
    {
    case 'q':
    case 'Q':
        if(target==0)
            return NO_TARGET;
        sowerHeal(this,target);
        break;
    case 'w':
    case 'W':
        if(target==0)
            return NO_TARGET;
        sowerSeed(this,target);
    default:
        return NO_ACTION;
    }
    return SUCCESS;
}

void classSower::printActions()
{
    std::cout << "Q: Heal." << std::endl
              << "W: Seed." << std::endl;
}

int classSower::sowerHeal(cptr source, cptr target)
{
    status *seed = new statusSeed(source, target, SHEAL_BASE, SHEAL_BONUS, SHEAL_INITIAL);
    target->pushStatus(seed);
    status *heal = new statusSowerHeal(source, target);
    target->pushStatus(heal);
    return 1;
}

int classSower::sowerSeed(cptr source, cptr target)
{
    status *seed1 = new statusSeed(source, target, SHEAL_BASE, SHEAL_BONUS, SHEAL_INITIAL);
    status *seed2 = new statusSeed(source, target, SHEAL_BASE, SHEAL_BONUS, SHEAL_INITIAL);
    status *seed3 = new statusSeed(source, target, SHEAL_BASE, SHEAL_BONUS, SHEAL_INITIAL);
    target->pushStatus(seed1);
    target->pushStatus(seed2);
    target->pushStatus(seed3);
    return 1;
}

