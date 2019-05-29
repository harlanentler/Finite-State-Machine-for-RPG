#ifndef STATUSCHANNELING_H
#define STATUSCHANNELING_H

#include "status.h"

class statusChanneling : public status
{
public:
    statusChanneling(combatant *sourceIn, combatant *targetIn, actionptr actionIn, int durationIn, bool startChannelled=true);
    ~statusChanneling();

    bool begin();

    bool end();

    bool channel(int amount=1);

    void print();

private:
    int duration;
    bool channelled;
    actionptr action;
    combatant* target;
};

#endif // STATUSCHANNELING_H
