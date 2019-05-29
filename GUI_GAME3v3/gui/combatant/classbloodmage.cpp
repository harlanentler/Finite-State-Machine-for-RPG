#include "classbloodmage.h"

classBloodmage::classBloodmage(std::string *logIn)
    :   combatant(logIn, BLOODMAGE_NAME, BLOODMAGE_HEALTH, BLOODMAGE_HEAMAX, BLOODMAGE_SPEED)
{

}

classBloodmage::~classBloodmage()
{

}

int classBloodmage::chooseAction(char choice, combatant *target)
{
    switch(choice)
    {
    case 'q':
    case 'Q':
        if(target==0)
            return NO_TARGET;
        log->append(name);
        log->append(" : using Siphon.");
        bloodmageSiphon(this,target);
        break;
    case 'w':
    case 'W':
        if(target==0)
            return NO_TARGET;
        log->append(name);
        log->append(" : using Flow.");
        bloodmageFlow(this,target);
        break;
    case 'e':
    case 'E':
        log->append(name);
        log->append(" : using Aegis.");
        bloodmageAegis(this, target);
        break;
    default:
        return NO_ACTION;
    }

    end();

    return SUCCESS;
}

void classBloodmage::printActions()
{
    std::cout << "Bloodmage Actions:" << std::endl
              << "Q: Bloodmage Siphon.  dmg " << SIPHON_DMG << " and dmgHMax " << SIPHON_DMG_HMAX
                << ".  Self heal " << SIPHON_HEAL << " and healMax " << SIPHON_HEAL_HMAX << "." << std::endl
              << "W: Bloodmage Flow.  Pay Bloodprice to dmg." << std::endl
              << "E: Bloodmage Aegis.  Pay Bloodprice to shield." << std::endl
              << "Current Bloodprice:  " << (getHealth(true)/BLOODPRICE_FRACTION)
              << std::endl << std::endl;
}

int classBloodmage::bloodmageSiphon(cptr source, cptr target)
{
    int dealt = target->damage(SIPHON_DMG,SIPHON_DMG_HMAX);
    damaging(dealt);
    if(dealt>0)
        heal(SIPHON_HEAL, SIPHON_HEAL_HMAX);
    return 1;
}

int classBloodmage::bloodmageFlow(cptr source, cptr target)
{
    int blood = getHealth(true)/BLOODPRICE_FRACTION;
    damage(0,blood);
    damaging(target->damage(blood));
    return 1;
}

int classBloodmage::bloodmageAegis(cptr source, cptr target)
{
    int blood = getHealth(true)/BLOODPRICE_FRACTION;
    damage(0,blood);
    status *shield = new statusShield(source, target, AEGIS_DURATION, blood);
    target->pushStatus(shield);
    return 1;
}
