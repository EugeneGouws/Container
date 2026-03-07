#ifndef CONTAINERLIST_H
#define CONTAINERLIST_H

#include <QList>
#include "container.h"
#include "backup.h"

class ContainerList
{
public:
    static ContainerList* getInstance();
    QList<Container*> getList();
    void add(Container *c);
    void restoreBackup(Backup b);
    Backup createBackup() ;


private:
    ContainerList();
    QList<Container*> m_list;
    static ContainerList* instance;


};

#endif // CONTAINERLIST_H
