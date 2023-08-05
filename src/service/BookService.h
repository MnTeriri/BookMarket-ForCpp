#ifndef BOOKMARKET_BOOKSERVICE_H
#define BOOKMARKET_BOOKSERVICE_H

#include <QObject>
#include <QJsonArray>
#include "../model/Book.h"
#include "../dao/BookDao.h"

class BookService: public QObject{
    Q_OBJECT
public:
    explicit BookService(QObject *parent = nullptr);
private:
    BookDao bookDao;
public slots:
    QJsonObject getBookList(QString bname, int page, int count);
};


#endif //BOOKMARKET_BOOKSERVICE_H
