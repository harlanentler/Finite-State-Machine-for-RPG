#ifndef CLASSBARBMAN_H
#define CLASSBARBMAN_H

#include "combatant.h"

#include "status/statusbleed.h"
#include "status/statusthirst.h"

const int BARBMAN_HEALTH = 12, BARBMAN_SPEED = 720;

const std::string BARBMAN_NAME = "Barbman";

const int BARBMAN_STRIKE_DMG = 2, BARBMAN_BLEED_DMG = 2, BARBMAN_BLEED_DURATION = 3, BARBMAN_BLEED_CD = 6,
            BARBMAN_THIRST_HEAL = 3;

class classBarbman : public combatant
{
public:
    classBarbman(std::string *logIn);
    ~classBarbman();

    int chooseAction(char choice, combatant *target=0);

    void printActions();

    bool adjustCooldowns(int adjustment=1);

private:
    int cdBleed;

    int barbmanStrike(cptr source, cptr target);

    int barbmanBleed(cptr source, cptr target);

    int barbmanThirst(cptr source, cptr target=0);
};

#endif // CLASSBARBMAN_H
