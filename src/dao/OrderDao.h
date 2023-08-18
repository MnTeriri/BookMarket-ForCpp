#ifndef BOOKMARKET_ORDERDAO_H
#define BOOKMARKET_ORDERDAO_H

#include <QString>
#include <QVector>
#include "../model/Order.h"
#include "AddressDao.h"
#include "OrderBookDao.h"

class OrderDao {
public:
    QVector<Order *> getOrderList(QString oid, int page, int count);
private:
    AddressDao addressDao;
    OrderBookDao orderBookDao;
};


#endif //BOOKMARKET_ORDERDAO_H
