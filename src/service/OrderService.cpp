#include "OrderService.h"
#include "../utils/JSON.h"

OrderService::OrderService(QObject *parent) : QObject(parent) {
}

QVariant OrderService::getOrderList(QJsonObject param) {
    QJsonObject jsonObject;
    QVector<Order *> list = orderDao.getOrderList("", param["page"].toInt(), param["count"].toInt());
    jsonObject["orderList"] = JSON::toJSONArray(list);
    qDeleteAll(list);
    return jsonObject;
}