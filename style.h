#pragma once

#ifndef STYLE_H
#define STYLE_H

#include <QString>

class StyleLoginForm {
 public:
    static QString entryField();         // Стиль поля ввода
    static QString confirmationButton(); // Стиль кнопки підтверждення
    static QString version();
};

class StyleWorkingWindow {
public:

    static QString backgroundUpPanel(); // Стиль іконки повідомлення.
    static QString iconsNewTask(); // Стиль іконки створення нового завдання.
    static QString sidePanel();    // Бокова панель.
};

#endif // STYLE_H
