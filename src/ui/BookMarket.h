#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_BookMarket.h"

class BookMarket : public QMainWindow{
    Q_OBJECT
public:
    BookMarket(QWidget *parent = nullptr);
    ~BookMarket();

private:
    Ui::BookMarketClass ui;
};
