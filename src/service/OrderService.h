#ifndef BOOKMARKET_ORDERSERVICE_H
#define BOOKMARKET_ORDERSERVICE_H

#include <QObject>
#include <QJsonArray>
#include <QMetaType>
#include "../dao/OrderDao.h"

class OrderService: public QObject{
    Q_OBJECT
public:
    Q_INVOKABLE explicit OrderService(QObject *parent = nullptr);
private:
    OrderDao orderDao;
public:
    Q_INVOKABLE QVariant getOrderList(QJsonObject param);
};

Q_DECLARE_METATYPE(OrderService)

#endif //BOOKMARKET_ORDERSERVICE_H
