#ifndef BOOKMARKET_ORDERBOOKDAO_H
#define BOOKMARKET_ORDERBOOKDAO_H

#include <QVector>
#include <QString>
#include "../model/OrderBook.h"
#include "BookDao.h"

class OrderBookDao {
public:
    QVector<OrderBook*> search(QString oid);
public:
    BookDao bookDao;
};
#endif //BOOKMARKET_ORDERBOOKDAO_H
