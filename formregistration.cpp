#include "formregistration.h"

FormRegistration::FormRegistration(QWidget *parent) : QWidget(parent) {

    this->p_formRegistration = new Ui_FormRegistration;

    this->p_formRegistration->setupUi(this);

    this->p_formRegistration->label_22->setStyleSheet("background-color:#c4c2c2};");
    this->p_formRegistration->label_23->setStyleSheet("background-color:#c4c2c2};");
    this->p_formRegistration->label_24->setStyleSheet("background-color:#c4c2c2};");
    this->p_formRegistration->label_25->setStyleSheet("background-color:#c4c2c2};");
    this->p_formRegistration->label_26->setStyleSheet("background-color:#c4c2c2};");
    this->p_formRegistration->label_27->setStyleSheet("background-color:#c4c2c2};");

}

FormRegistration::~FormRegistration() { delete p_formRegistration;}

