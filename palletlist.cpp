#include "palletlist.h"

PalletList* PalletList::instance =NULL;

PalletList::PalletList() {}

PalletList* PalletList::getInstance()
{
    if(instance == NULL)
        instance = new PalletList();
    return instance;
}

QList<Pallet*> PalletList::getList()
{
    return m_list;
}

void PalletList::add(Pallet *p)
{
    m_list.append(p);
}
