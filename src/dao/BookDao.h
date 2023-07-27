#ifndef BOOKMARKET_BOOKDAO_H
#define BOOKMARKET_BOOKDAO_H

#include <QVector>
#include <QSqlQuery>
#include "../model/Book.h"

class BookDao {
public:
    QVector<Book*> getBookList(QString bname, int cid, int page, int count);

private:
    QVector<Book*> executeSearch(QSqlQuery query);
};


#endif //BOOKMARKET_BOOKDAO_H
