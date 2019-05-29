#ifndef STATUS_H
#define STATUS_H

//
#include "iostream"
//

class combatant;

typedef combatant* cptr;

typedef int (*actionptr)(cptr,cptr);

class status
{
public:
    status(combatant* sourceIn, combatant *bearerIn, std::string tagIn, int priorityIn=500);
    virtual ~status();
    
    virtual bool begin();
    
    virtual bool end();
    
    virtual bool round();

    virtual bool damage(int &amount);

    virtual bool damaging(int dealt=0);

    virtual bool damaged(int amount=0);

    virtual bool channel(int amount=0);

    virtual bool channeling();

    virtual bool push(status *in);

    virtual bool pushFail();

    virtual void print();

    int getPriority();

    std::string getTag();

    void setPFail(bool set = true);

    bool operator >(status *other);
    bool operator <(status* other);
    bool operator >=(status* other);
    bool operator <=(status* other);

    bool operator ==(status* other);

protected:
    combatant *source, *bearer;

    int priority;

    std::string tag;

private:

    bool pFail;
    
};

#endif // STATUS_H
