#include "classbarbman.h"

classBarbman::classBarbman(std::string *logIn)
    : combatant(logIn, BARBMAN_NAME, BARBMAN_HEALTH, BARBMAN_HEALTH, BARBMAN_SPEED)
{
    cdBleed = 0;
}

classBarbman::~classBarbman()
{

}

int classBarbman::chooseAction(char choice, combatant *target)
{
    switch(choice)
    {
    case 'Q':
    case 'q':
        if(target==0)
            return NO_TARGET;
        log->append(name);
        log->append(":  Using Barbman Strike\n");
        barbmanStrike(this,target);
        break;
    case 'W':
    case 'w':
        if(target==0)
            return NO_TARGET;
        if(cdBleed==0)
        {
            log->append(name);
            log->append(":  Using Barbman Bleed\n");
            cdBleed = barbmanBleed(this,target);
        }
        else
            return ON_COOLDOWN;
        break;
    case 'E':
    case 'e':
        log->append(name);
        log->append(":  Using Barbman Thirst\n");
        barbmanThirst(this);
        break;
    case 'C':
    case 'c':
        channel();
        break;
    default:
        return NO_ACTION;
    }

    end();

    return SUCCESS;
}

void classBarbman::printActions()
{
    std::cout << "Barbman Actions:" << std::endl
              << "Q: Barbman Strike.  " << BARBMAN_STRIKE_DMG << " dmg." << std::endl
              << "W: Barbman Bleed.  " << BARBMAN_BLEED_DMG << " dmg per " << BARBMAN_BLEED_DURATION
                << " turns.  cd " << (BARBMAN_BLEED_CD-cdBleed) << "/" << BARBMAN_BLEED_CD << "." << std::endl
              << "E: Barbman Thirst.  " << BARBMAN_THIRST_HEAL << " heal on dmging" << std::endl
              << std::endl << std::endl;
}

bool classBarbman::adjustCooldowns(int adjustment)
{
    if(adjustment>=0)
    {
        if(cdBleed-adjustment<0)
        {
            cdBleed=0;
            return true;
        }
        else
        {
            cdBleed-=adjustment;
            return true;
        }
        return false;
    }
}

int classBarbman::barbmanStrike(cptr source, cptr target)
{
    int dealt = target->damage( BARBMAN_STRIKE_DMG );
    source->damaging(dealt);
    return 1;
}

int classBarbman::barbmanBleed(cptr source, cptr target)
{
    status *bleed = new statusBleed(source, target, BARBMAN_BLEED_DMG, BARBMAN_BLEED_DURATION);
    target->pushStatus(bleed);
    return BARBMAN_BLEED_CD;
}

int classBarbman::barbmanThirst(cptr source, cptr target)
{
    status *thirst = new statusThirst(source, target, 1, BARBMAN_THIRST_HEAL);
    source->pushStatus(thirst);
    return 1;
}
