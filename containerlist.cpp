#include "containerlist.h"

ContainerList* ContainerList::instance = NULL;

ContainerList::ContainerList() {}

ContainerList* ContainerList::getInstance()
{
    if (instance == NULL)
        instance = new ContainerList();
    return instance;
}

QList<Container*> ContainerList::getList()
{
    return m_list;
}

void ContainerList::add(Container *c)
{
    m_list.append(c);
}

void ContainerList::restoreBackup(Backup b)
{
    m_list = b.getList();
}

Backup ContainerList::createBackup()
{
    Backup b;
    b.setList(m_list);
    return b;
}
