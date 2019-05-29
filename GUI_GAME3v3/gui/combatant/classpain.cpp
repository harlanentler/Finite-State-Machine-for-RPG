#include "classpain.h"

classPain::classPain(std::string *logIn)
    :   combatant(logIn, PAIN_NAME, PAIN_HEALTH, PAIN_HEALTH, PAIN_SPEED)
{

}

classPain::~classPain()
{

}

int classPain::chooseAction(char choice, combatant *target)
{

}

void classPain::printActions()
{

}

