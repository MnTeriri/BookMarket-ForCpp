#ifndef BOOKMARKET_BOOKDAO_H
#define BOOKMARKET_BOOKDAO_H

#include <QVector>
#include <QSqlQuery>
#include "../model/Book.h"

class BookDao {
public:

    QVector<Book *> getBookList(QString bname, int page, int count);
    int getRecordsTotal();
    int getRecordsFiltered(QString bname);

private:
    QVector<Book *> executeSearch(QSqlQuery *query);
};


#endif //BOOKMARKET_BOOKDAO_H
