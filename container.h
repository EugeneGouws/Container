#ifndef CONTAINER_H
#define CONTAINER_H

#include <QObject>
#include <QString>



class Container : public QObject
{
    Q_OBJECT

public:
    explicit Container(int weight,int height, QObject *parent);
    QString getCode();
    int getWeight();
    int getVolume();
    int getHeight();
protected:
    QString m_code;
    int m_weight;
    int m_volume;
    int m_height;

signals:
};

Q_DECLARE_METATYPE(Container*)

#endif // CONTAINER_H
