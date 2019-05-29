#ifndef CLASSSOWER_H
#define CLASSSOWER_H

#include "combatant.h"

#include "status/status.h"
#include "status/statusseed.h"
#include "status/statussowerheal.h"

const std::string SOWER_NAME = "Sower";

const int SOWER_HEALTH = 12, SOWER_SPEED = 325;

const int SHEAL_BASE = 1, SHEAL_BONUS = 1, SHEAL_INITIAL = 3;

class classSower : public combatant
{
public:
    classSower(std::string *logIn);
    ~classSower();

    int chooseAction(char choice, cptr target);

    void printActions();

private:
    int sowerHeal(cptr source, cptr target);

    int sowerSeed(cptr source, cptr target);
};

#endif // CLASSSOWER_H
