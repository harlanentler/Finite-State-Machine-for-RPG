#ifndef STATUSHOT_H
#define STATUSHOT_H

#include "status.h"

class statusHoT : public status
{
public:
    statusHoT(cptr sourceIn, cptr bearerIn, int amountIn, int durationIn, std::string tagIn);
    ~statusHoT();

    bool round();

    bool push(status *in);

    void print();

private:
    int amount;
    int duration;
};

#endif // STATUSHOT_H
