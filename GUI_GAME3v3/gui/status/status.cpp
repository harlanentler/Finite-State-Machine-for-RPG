#include "status.h"

#include "combatant/combatant.h"
//IMPORTANT INCLUDE IN ALL CHILDREN .cpp FILES

enum {ULT_LOW=100, SUP_LOW = 200, LOW = 300, MED_LOW = 400, NORMAL = 500, MED_HIGH = 600, HIGH = 700, SUP_HIGH = 800, ULT_HIGH = 900};

status::status(combatant *sourceIn, combatant *bearerIn, std::string tagIn, int priorityIn)
{
    source = sourceIn;
    bearer = bearerIn;

    tag = tagIn;

    priority = priorityIn;

    pFail = false;
}

status::~status()
{

}

bool status::begin()
{
    return false;
}

bool status::end()
{
    return false;
}

bool status::round()
{
    return false;
}

bool status::damage(int &amount)
{
    return false;
}

bool status::damaging(int dealt)
{
    return false;
}

bool status::damaged(int amount)
{
    return false;
}

bool status::channel(int amount)
{
    return false;
}

bool status::channeling()
{
    return false;
}

bool status::push(status *in)
{
    return false;
}

bool status::pushFail()
{
    std::cout << "pFail final: " << pFail << std::endl;
    return pFail;
}

void status::print()
{

}

int status::getPriority()
{
    return priority;
}

std::string status::getTag()
{
    return tag;
}

void status::setPFail(bool set)
{
    std::cout << "SET: " << set <<std::endl;
    pFail = set;
    std::cout << "pFail: " << pFail << std::endl;
}

bool status::operator >(status *other)
{
    return getPriority() > other->getPriority();
}

bool status::operator <(status *other)
{
    return getPriority() < other->getPriority();
}

bool status::operator >=(status *other)
{
    return getPriority() >= other->getPriority();
}

bool status::operator <=(status *other)
{
    return getPriority() <= other->getPriority();
}

bool status::operator ==(status *other)
{
    if( tag == other->getTag() )
        return true;
    return false;
}
