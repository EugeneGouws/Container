#ifndef BOX_H
#define BOX_H

#include "container.h"
#include <QObject>

class Box : public Container
{
    Q_OBJECT
    Q_PROPERTY(QString code READ getCode)
    Q_PROPERTY(int weight READ getWeight)
    Q_PROPERTY(int length READ getLength)
    Q_PROPERTY(int breadth READ getBreadth)
    Q_PROPERTY(int height READ getHeight)

public:
    explicit Box(int l, int b, int h, int w, QString code, QObject *parent = nullptr);
    int getLength();
    int getBreadth();

private:
    int m_length;
    int m_breadth;
};



#endif // BOX_H
