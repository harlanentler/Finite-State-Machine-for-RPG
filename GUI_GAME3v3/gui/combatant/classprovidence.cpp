#include "classprovidence.h"

classProvidence::classProvidence(std::string *logIn)
    :   combatant(logIn, "Providence", PROVIDENCE_HEALTH, PROVIDENCE_HEALTH, PROVIDENCE_SPEED)
{
    log = logIn;
}

classProvidence::~classProvidence()
{

}

int classProvidence::chooseAction(char choice, combatant *target)
{
    switch(choice)
    {
    case 'q':
    case 'Q':
        if(target==0)
            return NO_TARGET;
        providenceShield(this, target);
        log->append(name);
        log->append(" Used Providence Shield.\n");
        break;
    case 'w':
    case 'W':
        if(target==0)
            return NO_TARGET;
        providenceHoT(this, target);
        log->append(name);
        log->append(" Used Providence HoT.\n");
        break;
    default:
        return NO_ACTION;
    }
    return SUCCESS;
}

void classProvidence::printActions()
{
    std::cout << "Providence Actions" << std::endl
              << "Q:  Providence Shield.  " << PSHIELD_AMOUNT << " Shield.  Duration " << PSHIELD_DURATION << "." << std::endl
              << "W:  Providence HoT.  Amount " << PHOT_HEAL << ", duration " << PHOT_DURATION <<"." << std::endl;
}

int classProvidence::providenceShield(cptr source, cptr target)
{
    status* shield = new statusShield(source, target, PSHIELD_DURATION, PSHIELD_AMOUNT);
    target->pushStatus(shield);
    return 1;
}

int classProvidence::providenceHoT(cptr source, cptr target)
{
    status *HoT = new statusHoT(source, target, PHOT_HEAL, PHOT_DURATION, "providenceHoT");
    target->pushStatus(HoT);
    return 1;
}

