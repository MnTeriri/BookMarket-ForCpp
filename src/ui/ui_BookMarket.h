/********************************************************************************
** Form generated from reading UI file 'BookMarket.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKMARKET_H
#define UI_BOOKMARKET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BookMarket
{
public:

    void setupUi(QWidget *BookMarket)
    {
        if (BookMarket->objectName().isEmpty())
            BookMarket->setObjectName("BookMarket");
        BookMarket->resize(1600, 850);
        BookMarket->setMinimumSize(QSize(1600, 850));
        BookMarket->setLayoutDirection(Qt::LeftToRight);
        BookMarket->setAutoFillBackground(false);

        retranslateUi(BookMarket);

        QMetaObject::connectSlotsByName(BookMarket);
    } // setupUi

    void retranslateUi(QWidget *BookMarket)
    {
        BookMarket->setWindowTitle(QCoreApplication::translate("BookMarket", "BookMarket", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BookMarket: public Ui_BookMarket {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKMARKET_H
