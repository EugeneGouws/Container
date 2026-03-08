#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <qfuturewatcher.h>
#include "backup.h"
#include "containerfactory.h"
#include <QTcpSocket>
#include <QLineEdit>
#include <QLabel>

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
    void reconnectToServer(); //new adition v1.1

public slots:
    void onActionBackupRestoreTriggered();
    void onActionBackupCreateTriggered();
    void onActionSendXml();
    void onActionConnectTriggered();

private:
    QSpinBox *box_breadth, *box_length, *box_height, *box_weight;
    QSpinBox *cylinder_diameter, *cylinder_height, *cylinder_weight;
    QPushButton *buttonAddBox, *buttonAddCylinder;
    QListWidget *displayUnallocated;
    QSpinBox *palletNumber;
    QPushButton *buttonMoveToPallet, *buttonBackupRestore, *buttonBackupCreate;
    QPushButton *buttonPostXML, *buttonReconnect; //reconect for v1.1
    QTextEdit *displayPalletXML;

    ContainerFactory *m_factory;
    QFutureWatcher<QByteArray>* watcher;
    QTcpSocket *socket;

    QLineEdit *ipInput;
    QPushButton *buttonConnect;
    QLabel *connectionStatus;
};

#endif // WIDGET_H
