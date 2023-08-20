#include <style.h>

QString StyleLoginForm::entryField() {

    return "QLineEdit{"
           "border-radius: 6px;"
           "}";

}

QString StyleLoginForm::confirmationButton() {

    return "QPushButton {"

           "color: white;"
           "border-radius: 1px;"
           "border-left: 2px solid white;"
           "}"

           "QPushButton:hover {"

           "background-color:#323434;"
           "color: white;"
           "border-radius: 3px;"
           "border-left: 2px solid white;"
           "}";
}

QString StyleLoginForm::version() {

    return "QLabel {color: white;}";
}

QString StyleWorkingWindow::backgroundUpPanel() {

    return "QLabel {background-color:#ececec};";

}
