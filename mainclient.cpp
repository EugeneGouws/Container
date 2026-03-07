#include "mainclient.h"
#include "widget.h"
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QLayout>
#include <QStatusBar>
#include <QMessageBox>
#include <QCloseEvent>

MainClient::MainClient(QWidget *parent)
    : QMainWindow(parent)
{
    qDebug()<<"MainClien constructor";
    // Setup actions
    setupActions();

    // Setup menu
    setupMenus();

    // Setup tool bar
    setupToolbar();

    // Initialize window
    MainWindow *w = new MainWindow(this);
    setCentralWidget(w);
    setWindowTitle("Containers and pallets");
    //setMaximumSize();
    //setWindowState(Qt::WindowMaximized);
    statusBar()->showMessage("Ready");
    setWindowIcon(QIcon(":/images/box_icon.ico"));

    // Connect Signals and Slots as required
    connect(actAbout, &QAction::triggered, this, &MainClient::showAbout);
    connect(actHelp, &QAction::triggered, this, &MainClient::showHelp);
    connect(actExit, &QAction::triggered, this, &QWidget::close);
    connect(actBackup, &QAction::triggered, w, &MainWindow::onActionBackupCreateTriggered);
    connect(actRestore, &QAction::triggered, w, &MainWindow::onActionBackupRestoreTriggered);
    connect(actPost, &QAction::triggered, w, &MainWindow::onActionSendXml);

}

MainClient::~MainClient()
{
    // Tidy up pointers, if required
}

void MainClient::showAbout()
{
    // Display 'About' information here
    QMessageBox::aboutQt(this,"About");
}

void MainClient::showHelp()
{
    QMessageBox::information(
        this,
        "Help",
        "This application manages containers and pallets.\n\n"
        "- Launch *Container Client* first to set up the server, "
        "otherwise this program won’t connect.\n\n"
        "- Add Boxes or Cylinders by first selecting the dimensions "
        "and then creating them.\n\n"
        "- Click the code of the Box or Cylinder, select a pallet number, "
        "and click 'Add to Pallet' to move the selected container.\n\n"
        "- A list of pallets can be seen under the 'Post XML' tab.\n\n"
        "- Use 'Backup' to save your data.\n"
        "- Use 'Restore' to load a backup.\n"
        "- Use 'Post XML' to send pallet/container data.\n"
        "- Use 'File → Exit' to quit."
        );
}

void MainClient::setupActions()
{
    qDebug()<<"MainClien setupActions";

    // Set up QActions as required
    // Create resource file for images in sub-directory 'images'.

    actAbout = new QAction(QIcon(":/images/info.png"), "About");
    actHelp = new QAction(QIcon(":/images/help.png"), "Help");
    actExit = new QAction(QIcon(":/images/exit.png"), "Exit");
    actBackup = new QAction(QIcon(":images/backup.png"), "Backup");
    actRestore = new QAction(QIcon(":images/restore.png"), "Restore");
    actPost = new QAction(QIcon(":/images/xml.png"), "Post XML");

}

void MainClient::setupMenus()
{
    qDebug()<<"MainClien setupMenus";

    // Set up QMenus as required

    mnuFile = menuBar()->addMenu("File");
    mnuFile->addSeparator();
    mnuFile->addAction(actExit);

    mnuBackup = menuBar()->addMenu("Backup");
    mnuBackup->addAction(actBackup);
    mnuBackup->addAction(actRestore);
    // Add items to Save and Restore containers

    mnuPost = menuBar()->addMenu("Post XML");
    mnuPost->addAction(actPost);

    mnuHelp = menuBar()->addMenu("Help");
    mnuHelp->addAction(actAbout);
    mnuHelp->addAction(actHelp);
}

void MainClient::setupToolbar()
{
    qDebug()<<"MainClien setupToolbar";

    toolbar = addToolBar("Main toolbar");
    toolbar->layout()->setSpacing(20);
    toolbar->addAction(actBackup);
    toolbar->addAction(actRestore);
    toolbar->addAction(actPost);


}

void MainClient::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm Exit",
                                  "Are you sure you want to quit?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        event->accept();
    } else {
        event->ignore();
    }
}
