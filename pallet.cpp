#include "pallet.h"

Pallet::Pallet(int n, QObject *parent)
    : QObject{parent}
{
    m_number = n;
    m_weight =0;
    m_volume =0;
}

void Pallet::addContainer(Container *c)
{
    pallet.append(c);
    this->addVolume(c);
    this->addWeight(c);
}

QList<Container*> Pallet::getList()
{
    return pallet;
}

int Pallet::getNumber()
{
    return m_number;
}

int Pallet::getWeight()
{
    return m_weight;
}

int Pallet::getVolume()
{
    return m_volume;
}

void Pallet::addWeight(Container *c)
{
    m_weight+= c->getWeight();
}

void Pallet::addVolume(Container *c)
{
    m_volume+= c->getVolume();
}
