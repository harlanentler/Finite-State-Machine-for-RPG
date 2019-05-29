#ifndef CLASSPAIN_H
#define CLASSPAIN_H

#include "combatant.h"

#include "status/status.h"

const int PAIN_HEALTH = 12, PAIN_SPEED = 310;

const std::string PAIN_NAME = "Pain";

class classPain : public combatant
{
public:
    classPain(std::string *logIn);
    ~classPain();

    int chooseAction(char choice, combatant *target);

    void printActions();

private:
    cptr recent;
};

#endif // CLASSPAIN_H
