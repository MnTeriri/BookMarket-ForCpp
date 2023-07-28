#ifndef BOOKMARKET_BOOKMARKET_H
#define BOOKMARKET_BOOKMARKET_H

#include <QWidget>
#include <QWebEngineView>
#include "ui_BookMarket.h"

class BookMarket : public QWidget {
    Q_OBJECT
public:
    explicit BookMarket(QWidget *parent = nullptr);
    ~BookMarket() override;

private:
    Ui::BookMarket ui;
};


#endif //BOOKMARKET_BOOKMARKET_H
