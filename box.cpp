#include "box.h"
#include <qdatetime.h>
#include <qdebug.h>

Box::Box(int l, int b, int h, int w, QString code, QObject *parent)
    : Container(w,h,parent)
{
    m_length = l;
    m_breadth = b;
    m_volume = l*b*h;
    m_code = code;

    this->setObjectName("Box");
}

int Box::getLength()
{
    return m_length;
}

int Box::getBreadth()
{
    return m_breadth;
}
