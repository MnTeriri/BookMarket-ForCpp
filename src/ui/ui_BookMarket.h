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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BookMarketClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BookMarketClass)
    {
        if (BookMarketClass->objectName().isEmpty())
            BookMarketClass->setObjectName("BookMarketClass");
        BookMarketClass->resize(600, 400);
        menuBar = new QMenuBar(BookMarketClass);
        menuBar->setObjectName("menuBar");
        BookMarketClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(BookMarketClass);
        mainToolBar->setObjectName("mainToolBar");
        BookMarketClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(BookMarketClass);
        centralWidget->setObjectName("centralWidget");
        BookMarketClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(BookMarketClass);
        statusBar->setObjectName("statusBar");
        BookMarketClass->setStatusBar(statusBar);

        retranslateUi(BookMarketClass);

        QMetaObject::connectSlotsByName(BookMarketClass);
    } // setupUi

    void retranslateUi(QMainWindow *BookMarketClass)
    {
        BookMarketClass->setWindowTitle(QCoreApplication::translate("BookMarketClass", "BookMarket", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BookMarketClass: public Ui_BookMarketClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKMARKET_H
