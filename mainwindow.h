#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "socket.h"
#include "formregistration.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TaskBoard; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::TaskBoard *p_main                = nullptr;
    Socket* p_socket                     = nullptr;
    FormRegistration* p_formRegistration = nullptr;
};

#endif // MAINWINDOW_H
