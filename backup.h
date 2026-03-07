#ifndef BACKUP_H
#define BACKUP_H

#include "container.h"

class Backup
{
    friend class ContainerList;
public:
    Backup();

private:
    void setList(QList<Container*> b);
    QList<Container*> getList();
    QList<Container*> m_list;


};

#endif // BACKUP_H
