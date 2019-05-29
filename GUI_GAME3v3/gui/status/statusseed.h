#ifndef STATUSSEED_H
#define STATUSSEED_H

#include "status.h"

class statusSeed : public status
{
public:
    statusSeed(cptr sourceIn, cptr bearerIn, int baseIn, int bonusIn, int initialIn);
    ~statusSeed();

    bool end();

    bool push(status *in);

    void print();

private:
    bool refreshed;
    int count;

    int base, bonus;
    int initial;
};

#endif // STATUSSEED_H
