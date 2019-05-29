#include "classbluemage.h"

classBluemage::classBluemage(std::string *logIn)
    :   combatant(logIn, BLUEMAGE_NAME, BLUEMAGE_HEALTH, BLUEMAGE_HEALTH, BLUEMAGE_SPEED)
{
    mana = BLUEMAGE_MANA;
    manaMax = BLUEMAGE_MANA_MAX;
    cdLeyline = 0;
}

classBluemage::~classBluemage()
{

}

int classBluemage::chooseAction(char choice, combatant *target)
{
    switch(choice)
    {
    case 'Q':
    case 'q':
        if(target==0)
            return NO_TARGET;
        bluemageManaSpike(this,target);
        break;
    case 'W':
    case 'w':
        if(target==0)
            return NO_TARGET;
        bluemageTorrent(this,target);
        break;
    case 'A':
    case 'a':
        bluemageFocus(this);
        break;
    case 'S':
    case 's':
        if(cdLeyline==0)
            cdLeyline=bluemageLeyline(this);
        break;
    case 'C':
    case 'c':
        channel();
    default:
        return NO_ACTION;
    }

    end();

    return SUCCESS;
}

void classBluemage::printActions()
{
    std::cout << "Bluemage Actions:" << std::endl
              << "Q: Mana Spike.  cost " << MSPIKE_MANA << " mana.  " << MSPIKE_DMG << " dmg." << std::endl
              << "W: Torrent.  cost ALL mana.  2-42 dmg." << std::endl
              << "A: Focus.  +1 mana." << std::endl
              << "S: Leyline.  Channel " << LEYLINE_CHANNEL
                << ".  +1, +2, +3 mana.  cd " << (LEYLINE_CD-cdLeyline) << "/" << LEYLINE_CD << "." << std::endl
              << "Mana: " << mana << "/" << BLUEMAGE_MANA_MAX << std::endl
              << std::endl << std::endl;
}

int classBluemage::getMana()
{
    return mana;
}

int classBluemage::adjustMana(int adjustment)
{
    mana += adjustment;
    if(mana>manaMax)
        mana=manaMax;
    else if(mana<0)
        mana=0;
    return mana;
}

bool classBluemage::adjustCooldowns(int adjustment)
{
    if(adjustment>=0)
    {
        if(cdLeyline-adjustment<0)
        {
            cdLeyline=0;
            return true;
        }
        else
        {
            cdLeyline-=adjustment;
            return true;
        }
        return false;
    }
}

int classBluemage::bluemageFocus(cptr source)
{
    if(mana+1>manaMax)
        return 0;
    ++mana;
    return 1;
}

int classBluemage::bluemageLeyline(cptr source, cptr target)
{
    status *leyline = new statusLeyline(this,this);
    source->pushStatus(leyline);
    return LEYLINE_CD;
}

//int classBluemage::bluemageTorrent(cptr source, cptr target)
//{
//    int damage;
//    if(mana>=0)
//    {
//        --mana;
//        damage=2;
//        damaging( target->damage(damage) );
//        std::cout << "damage = " << damage << std::endl;
//        for(mana; mana>0; --mana)
//        {
//            damage += 2;
//            std::cout << "damage = " << damage << std::endl;
//            damaging( target->damage(damage) );
//        }
//    }
//    return 1;
//}

int classBluemage::bluemageTorrent(cptr source, cptr target)
{
    int damage = TORRENT_BASE;
    damage += mana;
    if(mana==manaMax)
        ++damage;
    mana = 0;
    source->damaging( target->damage( damage ) );
    return 1;
}

int classBluemage::bluemageManaSpike(cptr source, cptr target)
{
    if(mana>0)
    {
        adjustMana(-MSPIKE_MANA);
        damaging( target->damage( MSPIKE_DMG ) );
    }
    return 1;
}

