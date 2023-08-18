#include "OrderBookDao.h"
#include "../utils/DataBaseUtils.h"

QVector<OrderBook *> OrderBookDao::search(QString oid) {
    QString sql = "SELECT * FROM Order_Book WHERE oid=?";
    QVector<OrderBook *> list = DataBaseUtils::search<OrderBook>(sql, oid);
    for (int i = 0; i < list.size(); ++i) {
        OrderBook *orderBook = list[i];
        Book *book = bookDao.search(orderBook->getBid());
        orderBook->setBook(book);
    }
    return list;
}
