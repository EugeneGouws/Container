#ifndef CYLINDER_H
#define CYLINDER_H

#include <QObject>
#include "container.h"

class Cylinder : public Container
{
    Q_OBJECT
    Q_PROPERTY(QString code READ getCode)
    Q_PROPERTY(int weight READ getWeight)
    Q_PROPERTY(int diameter READ getDiameter)
    Q_PROPERTY(int height READ getHeight)

public:
    explicit Cylinder(int d, int h, int w, QString code, QObject *parent = nullptr);
    int getDiameter();

private:
    int m_diameter;
};

#endif // CYLINDER_H
