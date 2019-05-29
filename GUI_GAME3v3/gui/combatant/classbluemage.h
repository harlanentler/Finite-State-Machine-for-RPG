#ifndef CLASSBLUEMAGE_H
#define CLASSBLUEMAGE_H

#include "combatant.h"

#include "status/statusleyline.h"

const std::string BLUEMAGE_NAME = "Bluemage";

const int BLUEMAGE_HEALTH = 12, BLUEMAGE_SPEED = 850, BLUEMAGE_MANA = 2, BLUEMAGE_MANA_MAX = 6;

const int MSPIKE_DMG = 5, MSPIKE_MANA = 2, TORRENT_BASE = 2, LEYLINE_MANA = 5, LEYLINE_CD = 6, LEYLINE_CHANNEL = 3;

class classBluemage : public combatant
{
public:
    classBluemage(std::string *logIn);
    ~classBluemage();

    int chooseAction(char choice, combatant *target=0);

    void printActions();

    int getMana();

    int adjustMana(int adjustment=1);

    bool adjustCooldowns(int adjustment=1);

private:

    int mana, manaMax;
    int cdLeyline;

    int bluemageFocus(cptr source);

    int bluemageLeyline(cptr source, cptr target=0);

    int bluemageTorrent(cptr source, cptr target);

    int bluemageManaSpike(cptr source, cptr target);

};

#endif // CLASSBLUEMAGE_H
