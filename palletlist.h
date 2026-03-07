#ifndef PALLETLIST_H
#define PALLETLIST_H

#include <QList>
#include "pallet.h"

class PalletList
{
public:
    static PalletList* getInstance();
    QList<Pallet*> getList();
    void add(Pallet *c);

private:
    PalletList();
    QList<Pallet*> m_list;
    static PalletList* instance;


};

#endif // PALLETLIST_H
