#ifndef CLASSBLOODMAGE_H
#define CLASSBLOODMAGE_H

#include "combatant.h"

#include "status/statusshield.h"

const std::string BLOODMAGE_NAME = "Bloodmage";

const int BLOODMAGE_HEALTH=12, BLOODMAGE_HEAMAX=12, BLOODMAGE_SPEED=715;

const int SIPHON_DMG=1, SIPHON_DMG_HMAX=1, SIPHON_HEAL=2, SIPHON_HEAL_HMAX=2, AEGIS_DURATION = 3, BLOODPRICE_FRACTION = 4;

class classBloodmage : public combatant
{
public:
    classBloodmage(std::string *logIn);
    ~classBloodmage();

    int chooseAction(char choice, combatant *target=0);

    void printActions();

private:

    int bloodmageSiphon(cptr source, cptr target);

    int bloodmageFlow(cptr source, cptr target);

    int bloodmageAegis(cptr source, cptr target);
};

#endif // CLASSBLOODMAGE_H
