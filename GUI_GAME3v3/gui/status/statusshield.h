#ifndef STATUSSHIELD_H
#define STATUSSHIELD_H

#include "status.h"

class statusShield : public status
{
public:
    statusShield(cptr sourceIn, cptr bearerIn, int durationIn, int shieldIn);
    ~statusShield();

    bool damage(int &amount);

    bool round();

    void print();

private:
    int duration;
    int shield;
};

#endif // STATUSSHIELD_H
