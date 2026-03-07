#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <qfuturewatcher.h>
#include "backup.h"
#include "containerfactory.h"
#include <QTcpSocket>

class QSpinBox;
class QPushButton;
class QListWidget;
class QTextEdit;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //Momento
    Backup backup;

private slots:
    void onActionAddBoxTriggered();
    void onActionAddCylTriggered();
    void onActionAddToPalletTriggered();
    void onActionUpdateXml();
    void serializeXml();

public slots:
    void onActionBackupRestoreTriggered();
    void onActionBackupCreateTriggered();
    void onActionSendXml();

private:
    QSpinBox *box_breadth, *box_length, *box_height, *box_weight;
    QSpinBox *cylinder_diameter, *cylinder_height, *cylinder_weight;
    QPushButton *buttonAddBox, *buttonAddCylinder;
    QListWidget *displayUnallocated;
    QSpinBox *palletNumber;
    QPushButton *buttonMoveToPallet, *buttonBackupRestore, *buttonBackupCreate;
    QPushButton *buttonPostXML;
    QTextEdit *displayPalletXML;

    ContainerFactory *m_factory;
    QFutureWatcher<QByteArray>* watcher;
    QTcpSocket *socket;
};

#endif // WIDGET_H
