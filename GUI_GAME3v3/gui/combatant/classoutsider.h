#ifndef CLASSOUTSIDER_H
#define CLASSOUTSIDER_H

#include "combatant.h"

#include "status/statuschanneling.h"
#include "status/statusvoidsick.h"

const std::string OUTSIDER_NAME = "Outsider";

const int OUTSIDER_HEALTH = 12, OUTSIDER_SPEED = 320;

const int METEOR_CHANNEL = 3, METEOR_DMG = 7, VOIDSICK_DMG = 2, VOIDSICK_DURATION = 3;

int outsiderMeteorCast(cptr source, cptr target);

int outsiderMeteorChannel(cptr source, cptr target);

class classOutsider : public combatant
{
public:
    classOutsider(std::string *logIn);
    ~classOutsider();

    int chooseAction(char choice, combatant *target=0);

    void printActions();

private:

    int outsiderVoidsick(cptr source, cptr target);
};

#endif // CLASSOUTSIDER_H
