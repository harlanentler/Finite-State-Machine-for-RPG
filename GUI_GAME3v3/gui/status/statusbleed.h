#ifndef STATUSBLEED_H
#define STATUSBLEED_H

#include "status.h"

class statusBleed : public status
{
public:
    statusBleed(combatant* sourceIn, combatant* bearerIn, int amountIn, int durationIn);
    ~statusBleed();

    bool round();

    void print();

private:
    int amount;
    int duration;
};

#endif // STATUSBLEED_H
