#ifndef PALLET_H
#define PALLET_H

#include <QObject>
#include "container.h"

class Pallet : public QObject
{
    Q_OBJECT
public:
    explicit Pallet(int n, QObject *parent = nullptr);
    void addContainer (Container *c);
    QList<Container*> getList();
    int getNumber();
    int getWeight();
    int getVolume();
    void addWeight(Container *c);
    void addVolume(Container *c);


private:
    QList<Container*> pallet;
    int m_number;
    int m_weight;
    int m_volume;
};

#endif // PALLET_H
