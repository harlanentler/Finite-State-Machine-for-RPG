#include "statussowerheal.h"

statusSowerHeal::statusSowerHeal(cptr sourceIn, cptr targetIn)
    :   status(sourceIn, targetIn, "sowerHeal")
{
    setPFail(true);
}

statusSowerHeal::~statusSowerHeal()
{

}

