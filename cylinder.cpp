#include "cylinder.h"
#include <qdatetime.h>
#include <qdebug.h>

Cylinder::Cylinder(int d, int h, int w, QString code, QObject *parent)
    : Container{w,h,parent}
{
    m_diameter = d;
    m_volume = h*M_PI*d*d/4;
    if(m_volume<1)
        m_volume=1;
    m_code = code;

    this->setObjectName("Cylinder");
}

int Cylinder::getDiameter()
{
    return m_diameter;
}
