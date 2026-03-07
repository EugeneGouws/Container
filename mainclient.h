#ifndef MAINCLIENT_H
#define MAINCLIENT_H

#include <QMainWindow>
class QAction;
class QMenu;
class QToolBar;

class MainClient : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainClient(QWidget *parent = nullptr);
    ~MainClient();
    void closeEvent(QCloseEvent *event);

private slots:
    void showAbout();
    void showHelp();

private:
    void setupActions();
    void setupMenus();
    void setupToolbar();

    // Add QAction items as required
    QAction *actAbout;
    QAction *actHelp;
    QAction *actExit;
    QAction *actPost;
    QAction *actBackup;
    QAction *actRestore;

    // Add QMenu items as required
    QMenu *mnuFile;
    QMenu *mnuBackup;
    QMenu *mnuPost;
    QMenu *mnuHelp;

    QToolBar *toolbar;
};

#endif // MAINCLIENT_H
