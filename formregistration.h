#pragma once
#ifndef FORMREGISTRATION_H
#define FORMREGISTRATION_H

#include <ui_formregistration.h>
#include <QWidget>

#include "style.h"

class FormRegistration : public QWidget {
    Q_OBJECT
 public:
    FormRegistration(QWidget *parent = nullptr);
     ~FormRegistration();

 private:
     Ui_FormRegistration* p_formRegistration = nullptr;

};

#endif // FORMREGISTRATION_H
