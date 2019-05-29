#ifndef STATUSLEYLINE_H
#define STATUSLEYLINE_H

#include "status.h"

class statusLeyline : public status
{
public:
    statusLeyline(combatant *sourceIn, combatant *targetIn, bool startChannelled=true);
    ~statusLeyline();

    bool begin();

    bool end();

    bool channel(int amount=1);

    void print();

private:
    bool channelled;
    int ley, leyMax;

};

#endif // STATUSLEYLINE_H
