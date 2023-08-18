#ifndef BOOKMARKET_BOOKSERVICE_H
#define BOOKMARKET_BOOKSERVICE_H

#include <QObject>
#include <QJsonArray>
#include <QMetaType>
#include "../model/Book.h"
#include "../dao/BookDao.h"

class BookService: public QObject{
    Q_OBJECT
public:
    Q_INVOKABLE explicit BookService(QObject *parent = nullptr);
private:
    BookDao bookDao;
public:
    Q_INVOKABLE QJsonObject getBookList(QString bname, int page, int count);
    Q_INVOKABLE QVariant getBookList(QJsonObject param);
};

Q_DECLARE_METATYPE(BookService)

#endif //BOOKMARKET_BOOKSERVICE_H
