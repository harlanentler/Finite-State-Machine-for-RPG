#ifndef STATUSCHANNELCONTINUOUS_H
#define STATUSCHANNELCONTINUOUS_H

#include "status.h"

class statusChannelContinuous : public status
{
public:
    statusChannelContinuous(combatant *sourceIn, combatant *targetIn, actionptr actionIn, int durationIn, bool startChannelled=true);
    ~statusChannelContinuous();

    bool begin();

    bool end();

    bool channel(int amount=0);

    void print();

private:
    int duration;
    bool channelled;
    actionptr action;
    combatant* target;
};

#endif // STATUSCHANNELCONTINUOUS_H
