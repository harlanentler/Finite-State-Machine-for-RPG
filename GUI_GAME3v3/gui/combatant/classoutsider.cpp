#include "classoutsider.h"

classOutsider::classOutsider(std::string *logIn)
    : combatant(logIn, OUTSIDER_NAME, OUTSIDER_HEALTH, OUTSIDER_HEALTH, OUTSIDER_SPEED)
{

}

classOutsider::~classOutsider()
{

}

int classOutsider::chooseAction(char choice, combatant *target)
{
    switch(choice)
    {
    case 'Q':
    case 'q':
        if(target==0)
            return NO_TARGET;
        outsiderMeteorChannel(this,target);
        log->append(name);
        log->append(":  Begins Channeling Outsider Meteor\n");
        break;
    case 'W':
    case 'w':
        if(target==0)
            return NO_TARGET;
        outsiderVoidsick(this, target);
        log->append(name);
        log->append(":  Used Outsider Voidsick.\n");
        break;
    case 'C':
    case 'c':
        channel();
        log->append(name);
        log->append(":  Continues Channeling\n");
        break;
    default:
        return NO_ACTION;
    }

    end();

    return SUCCESS;
}

void classOutsider::printActions()
{
    std::cout << "Outsider Actions:" << std::endl
              << "Q: Outsider Meteor Channel.  channel " << METEOR_CHANNEL << "." << std::endl
              << "-  Outsider Metoer Cast.  " << METEOR_DMG << " dmg." << std::endl
              << "W: Outsider Voidsick.  " << VOIDSICK_DMG << " dmg per for " << VOIDSICK_DURATION
                << " turns.  dmg fails on recently damaged target." << std::endl
              << std::endl << std::endl;
}

int outsiderMeteorCast(cptr source, cptr target)
{
    int dealt = target->damage( METEOR_DMG );
    source->damaging(dealt);
    return 1;
}

int outsiderMeteorChannel(cptr source, cptr target)
{
    actionptr cast = &outsiderMeteorCast;
    status *channel = new statusChanneling(source, target, cast, METEOR_CHANNEL);
    source->pushStatus(channel);
    return 1;
}

int classOutsider::outsiderVoidsick(cptr source, cptr target)
{
    status *sickness = new statusVoidsick(source, target, VOIDSICK_DMG, VOIDSICK_DURATION);
    target->pushStatus(sickness);
    return 1;
}
