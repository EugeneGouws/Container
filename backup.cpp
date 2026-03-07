#include "backup.h"

Backup::Backup()
{}

void Backup::setList(QList<Container*> b)
{
    m_list = b;
}

QList<Container*> Backup::getList()
{
    return m_list;
}
