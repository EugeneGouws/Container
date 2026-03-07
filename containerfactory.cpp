#include "containerfactory.h"
#include "box.h"
#include "cylinder.h"
#include <QDate>

ContainerFactory::ContainerFactory()
{
    m_counter=0;
}

Container* ContainerFactory::create(QString type, int l, int b, int h, int w)
{
    QDate *date = new QDate();
    QString year = QString::number(date->currentDate().year());
    QString month = QString::number(date->currentDate().month());
    QString n;
    n.setNum(m_counter);
    delete date;
    date = nullptr;

    if (type == "Box")
    {
        QString code = year + "/" + month + "/B" + n;
        Box *box = new Box(l,b,h,w,code);
        m_counter++;
        return box;
    }

    else if (type == "Cylinder")
    {
        QString code = year + "/" + month + "/C" + n;
        Cylinder *cylinder = new Cylinder(l,h,w,code);
        m_counter++;
        return cylinder;
    }
    else
        return nullptr;
}
