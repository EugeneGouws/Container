#ifndef CONTAINERFACTORY_H
#define CONTAINERFACTORY_H

#include "container.h"

class ContainerFactory
{
public:
    ContainerFactory();
    Container* create(QString type, int l, int b, int h, int w);
    int m_counter;
};

#endif // CONTAINERFACTORY_H
