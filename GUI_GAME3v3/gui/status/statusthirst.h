#ifndef STATUSTHIRST_H
#define STATUSTHIRST_H

#include "status.h"

class statusThirst : public status
{
public:
    statusThirst(combatant *sourceIn, combatant *bearerIn, int durationIn, int amountIn);
    ~statusThirst();

    bool begin();

    bool round();

    bool damaging(int dealt=0);

    void print();

private:
    int duration;
    int amount;
    bool active;
};

#endif // STATUSTHIRST_H
