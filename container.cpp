#include "container.h"
#include <QDateTime>

Container::Container(int weight, int height, QObject *parent)
    : QObject{parent}
{
    m_weight = weight;
    m_height = height;
}

QString Container::getCode()
{
    return m_code;
}
int Container::getWeight()
{
    return m_weight;
}
int Container::getVolume()
{
    return m_volume;
}

int Container::getHeight()
{
    return m_height;
}



