#include "OrderDao.h"
#include "../utils/DataBaseUtils.h"

QVector<Order *> OrderDao::getOrderList(QString oid, int page, int count) {
    QString sql = "SELECT * FROM `Order` WHERE oid LIKE ? LIMIT ?,?";
    QVector<Order *> list = DataBaseUtils::search<Order>(sql, "%" + oid + "%", (page - 1) * count, count);
    for (int i = 0; i < list.size(); ++i) {
        Order *order = list[i];
        Address *address = addressDao.search(order->getAid());
        order->setAddress(address);
        QVector<OrderBook *> books = orderBookDao.search(order->getOid());
        order->setBooks(books);
    }
    return list;
}
