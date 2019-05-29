#ifndef COMBATANT_H
#define COMBATANT_H

#include "string"

#include "vector"

#include <algorithm>

#include "status/status.h"

//
#include "iostream"
//

enum {SUCCESS, ON_COOLDOWN, NO_TARGET, NO_ACTION};

enum {BEGIN, END, ROUND, DAMAGE, DAMAGING, DAMAGED, CHANNEL, CHANNELING};

class combatant
{
public:
    combatant(std::string *logIn, std::string nameIn="DUMMY", int healthIn=0, int healthMaxIn=0, int speedIn=0);
    virtual ~combatant();
    
    virtual int chooseAction(char choice, combatant* target=0);

    virtual int damage(int dmgHealth, int dmgHealthMax=0);
    virtual int heal(int healing, int healMax=0);

    virtual int begin();

    virtual int end();

    virtual int round();

    virtual int channel(bool begin=false);

    virtual int damaging(int amount=0);

    virtual int healing(int amount=0);

    virtual int pushStatus(status* in);

    virtual void print();

    virtual void printActions();

    int getHealth(bool max=false);

    int getSpeed();

    int getReady();

    virtual int getMana();

    virtual int adjustMana(int adjustment=1);

    virtual bool adjustCooldowns(int adjustment=1);

protected:
    std::string *log;

    std::string name;
    
private:
    int health, healthMax;
    int speed;
    int moves;

    
    std::vector<int> actions;
    std::vector<status *> statuses;
};

#endif // COMBATANT_H
