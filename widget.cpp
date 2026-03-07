#include "widget.h"
#include <QSpinBox>
#include <QPushButton>
#include <QListWidget>
#include <QTextEdit>
#include <QGroupBox>
#include <QGridLayout>
#include <QLabel>
#include <QtConcurrent>
#include "containerfactory.h"
#include "container.h"
#include <QMessageBox>
#include <qstatusbar.h>
#include "containerlist.h"
#include "pallet.h"
#include "palletlist.h"
#include "xmlwriter.h"
#include <QTcpSocket>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    box_breadth(new QSpinBox()),
    box_length(new QSpinBox()),
    box_height(new QSpinBox()),
    box_weight(new QSpinBox()),
    cylinder_diameter(new QSpinBox()),
    cylinder_height(new QSpinBox()),
    cylinder_weight(new QSpinBox()),
    buttonAddBox(new QPushButton("Add box")),
    buttonAddCylinder(new QPushButton("Add cylinder")),
    displayUnallocated (new QListWidget),
    palletNumber(new QSpinBox()),
    buttonMoveToPallet(new QPushButton("Move to pallet")),
    buttonBackupRestore(new QPushButton("Restore backup")),
    buttonBackupCreate(new QPushButton("Create backup")),
    buttonPostXML(new QPushButton("Post XML to network")),
    displayPalletXML(new QTextEdit)
{
    qDebug()<<"Mainwindow Widget Constructor";

    // Tab 1 - Containers
    QGroupBox *boxGroup(new QGroupBox("Box"));
    QGridLayout *boxlayout(new QGridLayout);
    boxGroup->setLayout(boxlayout);
    QLabel *labelBBreadth(new QLabel("Breadth"));
    boxlayout->addWidget(labelBBreadth, 0, 0);
    boxlayout->addWidget(box_breadth, 0, 1);
    QLabel *labelBLength(new QLabel("Length"));
    boxlayout->addWidget(labelBLength, 1, 0);
    boxlayout->addWidget(box_length, 1, 1);
    QLabel *labelBHeight(new QLabel("Height"));
    boxlayout->addWidget(labelBHeight, 2, 0);
    boxlayout->addWidget(box_height, 2, 1);
    QLabel *labelBWeight(new QLabel("Weight"));
    boxlayout->addWidget(labelBWeight, 3, 0);
    boxlayout->addWidget(box_weight, 3, 1);
    boxlayout->addWidget(buttonAddBox, 4, 0, 1, 2);
    buttonAddBox->setObjectName("BoxButton");

    QGroupBox *cylinderGroup(new QGroupBox("Cylinder"));
    QGridLayout *cylinderlayout(new QGridLayout);
    cylinderGroup->setLayout(cylinderlayout);
    QLabel *labelCDiameter(new QLabel("Diameter"));
    cylinderlayout->addWidget(labelCDiameter, 0, 0);
    cylinderlayout->addWidget(cylinder_diameter, 0, 1);
    QLabel *labelCHeight(new QLabel("Height"));
    cylinderlayout->addWidget(labelCHeight, 1, 0);
    cylinderlayout->addWidget(cylinder_height, 1, 1);
    QLabel *labelCWeight(new QLabel("Weight"));
    cylinderlayout->addWidget(labelCWeight, 2, 0);
    cylinderlayout->addWidget(cylinder_weight, 2, 1);
    QLabel *labelBlank1(new QLabel);
    cylinderlayout->addWidget(labelBlank1, 3, 0);
    cylinderlayout->addWidget(buttonAddCylinder, 4, 0, 1, 2);
    buttonAddCylinder->setObjectName("CylinderButton");

    QWidget *bottomWidget(new QWidget);
    QGridLayout *bottomLayout(new QGridLayout);
    bottomWidget->setLayout(bottomLayout);
    QLabel *labelListOf(new QLabel("List of unallocated containers"));
    bottomLayout->addWidget(labelListOf, 0, 0);
    QLabel *labelClickOn(new QLabel("Click on item in list, choose a pallet number, and Move the container to that pallet"));
    labelClickOn->setWordWrap(true);

    bottomLayout->addWidget(displayUnallocated, 1, 0, 5, 1);
    bottomLayout->addWidget(labelClickOn, 1, 1);
    bottomLayout->addWidget(palletNumber, 2, 1);
    palletNumber->setMinimum(1);
    bottomLayout->addWidget(buttonMoveToPallet, 3, 1);
    QLabel *labelBlank2(new QLabel);
    cylinderlayout->addWidget(labelBlank2, 4, 1);
    bottomLayout->addWidget(buttonBackupRestore,5, 1);
    bottomLayout->addWidget(buttonBackupCreate, 6, 1);

    QWidget *containerWidget(new QWidget);
    QGridLayout *tabLayoutContainer(new QGridLayout);
    tabLayoutContainer->addWidget(boxGroup, 0, 0);
    tabLayoutContainer->addWidget(cylinderGroup, 0, 1);
    tabLayoutContainer->addWidget(bottomWidget, 1, 0, 1, 2);
    containerWidget->setLayout(tabLayoutContainer);

    // Tab 2 - Post XML
    QWidget *postWidget(new QWidget);
    QVBoxLayout *postLayout(new QVBoxLayout);
    postWidget->setLayout(postLayout);
    postLayout->addWidget(buttonPostXML);
    postLayout->addWidget(displayPalletXML);

    // setting main widget
    QTabWidget *tabs = new QTabWidget(this);
    tabs->addTab(containerWidget, "Containers");
    tabs->addTab(postWidget, "Post XML");
    QVBoxLayout *vertical(new QVBoxLayout);
    vertical->addWidget(tabs);
    setLayout(vertical);

    //initialise spinboxes etc
    box_breadth->setRange(1,1000);
    box_length->setRange(1,1000);
    box_height->setRange(1,1000);
    box_weight->setRange(1,1000);
    cylinder_diameter->setRange(1,1000);
    cylinder_height->setRange(1,1000);
    cylinder_weight->setRange(1,1000);
    displayUnallocated->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);

    //Concurrency
    watcher = new QFutureWatcher<QByteArray>(this);
    QThread::currentThread()->setObjectName("Main Thread");

    // setting up bottons to work
    connect(buttonAddBox, SIGNAL(clicked(bool)), this, SLOT(onActionAddBoxTriggered()));
    connect(buttonAddCylinder, SIGNAL(clicked(bool)), this, SLOT(onActionAddCylTriggered()));
    connect(buttonMoveToPallet, SIGNAL(clicked(bool)), this, SLOT(onActionAddToPalletTriggered()));
    connect(buttonBackupRestore, SIGNAL(clicked(bool)), this, SLOT(onActionBackupRestoreTriggered()));
    connect(buttonBackupCreate, SIGNAL(clicked(bool)), this, SLOT(onActionBackupCreateTriggered()));
    connect(buttonPostXML, SIGNAL(clicked(bool)), this, SLOT(onActionSendXml()));
    connect(watcher, &QFutureWatcher<QByteArray>::finished, this, &MainWindow::onActionUpdateXml);

    //initial setup for container classes
    m_factory = new ContainerFactory();

    //initial backup
    backup = ContainerList::getInstance()->createBackup();

    //Network setup
    socket = new QTcpSocket(this);
    socket->connectToHost("127.0.0.1", 6164);
    if(socket->waitForConnected(3000))
    {
        qDebug()<<"Socket connected";
    }
    else
        qDebug()<<"Socket could not connect to server.";
}

void MainWindow::onActionAddBoxTriggered()
{
    Container *c = m_factory->create("Box",box_length->value(),
                                     box_breadth->value(),
                                     box_height->value(),
                                     box_weight->value());
    ContainerList::getInstance()->add(c);
    QListWidgetItem *item = new QListWidgetItem(c->getCode());
    item->setData(Qt::UserRole, QVariant::fromValue(c));
    displayUnallocated->addItem(item);
    displayUnallocated->setCurrentItem(item);

};

void MainWindow::onActionAddCylTriggered()
{
    Container *c = m_factory->create("Cylinder",
                                     cylinder_diameter->value(),1,
                                     cylinder_height->value(),
                                     cylinder_weight->value());
    ContainerList::getInstance()->add(c);
    QListWidgetItem *item = new QListWidgetItem(c->getCode());
    item->setData(Qt::UserRole, QVariant::fromValue(c));
    displayUnallocated->addItem(item);
    displayUnallocated->setCurrentItem(item);
};

void MainWindow::onActionAddToPalletTriggered()
{
    //error handling for no selection
    if(displayUnallocated->currentItem()==NULL)
    {
        QMessageBox msgBox;
        msgBox.setText("No container selected.");
        msgBox.exec();
        return;
    }

    //Check if the pallet exists and either add to it or create it
    int n = palletNumber->value();
    Container *c = displayUnallocated->currentItem()->data(Qt::UserRole).value<Container*>();
    PalletList *pallets = PalletList::getInstance();
    Pallet *pallet;
    bool found = 0;
    for (Pallet *p : pallets->getList())
    {
        if(p->getNumber()==n)
        {
            found = 1;
            pallet = p;
        }
    }
    //create a pallet as it wasnt found
    if (!found)
    {
        pallet = new Pallet(n,this);
        pallets->add(pallet);
        qDebug()<<"added pallet "<<n<<" to pallets";
    }
    pallet->addContainer(c);

    // Run XML serialization in a thread
    serializeXml();

    //remove the container from the unallocated list
    delete displayUnallocated->takeItem(displayUnallocated->row(displayUnallocated->currentItem()));
    ContainerList::getInstance()->getList().removeOne(c);

};

void MainWindow::serializeXml()
{
    qDebug()<<"Start serialize xml";
    QFuture<QByteArray> future = QtConcurrent::run([this] {
        QStatusBar().showMessage("Serializing");
        qDebug()<<"in pool thread";
        XmlWriter xmlWriter;
        return xmlWriter.writeXml();
    });
    watcher->setFuture(future);
    QStatusBar().showMessage("Ready");
}

void MainWindow::onActionUpdateXml()
{
    qDebug()<<"Calling display update xml";
    displayPalletXML->setText(watcher->result());
}

void MainWindow::onActionBackupCreateTriggered()
{
    backup = ContainerList::getInstance()->createBackup();
};

void MainWindow::onActionBackupRestoreTriggered()
{
    qDebug()<<"Restore triggered";
    ContainerList *cList = ContainerList::getInstance();
    ContainerList::getInstance()->restoreBackup(backup);
    qDebug()<<"backup restored, about to redo the display";
    displayUnallocated->clear();
    for (Container *c : cList->getList())
    {
        qDebug()<<"adding "<<c->getCode();
        QListWidgetItem *item = new QListWidgetItem(c->getCode());
        item->setData(Qt::UserRole, QVariant::fromValue(c));
        displayUnallocated->addItem(item);
        displayUnallocated->setCurrentItem(item);
    }
};

void MainWindow::onActionSendXml()
{
    qDebug()<<"Send Xml triggered";
    if(watcher->result().isEmpty())
    {
        qDebug()<<"Nothing to send";
    }
    else
    {
        socket->write(watcher->result());
        socket->flush();
        emit socket->readyRead();
    }
}

MainWindow::~MainWindow()
{
    delete m_factory;
    m_factory = nullptr;
    socket->close();
};

