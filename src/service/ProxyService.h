#ifndef BOOKMARKET_PROXYSERVICE_H
#define BOOKMARKET_PROXYSERVICE_H

#include <QObject>
#include <QVariant>
#include <QJsonObject>
#include <QHash>

class ProxyService : public QObject {
Q_OBJECT
public:
    explicit ProxyService(QObject *parent = nullptr);
public slots:
    QVariant executeService(QJsonObject param);
};

#endif //BOOKMARKET_PROXYSERVICE_H
