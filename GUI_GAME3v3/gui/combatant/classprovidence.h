#ifndef CLASSPROVIDENCE_H
#define CLASSPROVIDENCE_H

#include "combatant.h"

#include "status/statusshield.h"
#include "status/statushot.h"

//std::string PROVIDENCE_NAME = "Providence";

const int PROVIDENCE_HEALTH = 12, PROVIDENCE_SPEED = 950;

const int PSHIELD_AMOUNT = 4, PSHIELD_DURATION=1, PHOT_HEAL = 1, PHOT_DURATION = 3;

class classProvidence : public combatant
{
public:
    classProvidence(std::string *logIn);
    ~classProvidence();

    int chooseAction(char choice, combatant *target=0);

    void printActions();

private:

    int providenceShield(cptr source, cptr target);

    int providenceHoT(cptr source, cptr target);

};

#endif // CLASSPROVIDENCE_H
