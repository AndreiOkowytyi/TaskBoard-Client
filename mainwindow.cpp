#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <style.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , p_main(new Ui::TaskBoard)
{
    p_main->setupUi(this);

    this->p_main->label_4->close();

    this->p_main->lineEdit    ->setStyleSheet(StyleLoginForm::entryField());
    this->p_main->lineEdit_2  ->setStyleSheet(StyleLoginForm::entryField());
    this->p_main->pushButton  ->setStyleSheet(StyleLoginForm::confirmationButton());
    this->p_main->pushButton_2->setStyleSheet(StyleLoginForm::confirmationButton());

    this->p_socket = new Socket;

    this->p_main->lineEdit_2->setEchoMode(QLineEdit::Password);

    this->p_main->label_6->setText(version);
    this->p_main->label_6->setStyleSheet(StyleLoginForm::version());

    QObject::connect(this->p_main->pushButton, &QPushButton::clicked, this, [this](){

        if(!this->p_socket->connectedToServer())  this->p_main->label_4->show();;
        this->p_formRegistration = new FormRegistration(this);
        this->p_main->widget->close();
        p_formRegistration->show();
    });

    QObject::connect(this->p_main->pushButton_2, &QPushButton::clicked, this, [this](){

        if(!this->p_socket->connectedToServer())  this->p_main->label_4->show();;
    });
}

MainWindow::~MainWindow()
{
    delete p_main;
    delete p_socket;
}

