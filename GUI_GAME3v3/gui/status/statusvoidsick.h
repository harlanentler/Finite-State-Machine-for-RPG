#ifndef STATUSVOIDSICK_H
#define STATUSVOIDSICK_H

#include "status.h"

class statusVoidsick : public status
{
public:
    statusVoidsick(combatant* sourceIn, combatant *bearerIn, int damageIn, int durationIn);
    ~statusVoidsick();

    bool round();

    bool damaged(int amount=0);

    void print();

private:
    int damage;
    int duration;
    bool wasDamaged;
};

#endif // STATUSVOIDSICK_H
