#ifndef BOOKMARKET_PROXYSERVICE_H
#define BOOKMARKET_PROXYSERVICE_H

#include <QObject>
#include <QString>
#include <QVariant>
#include <QJsonObject>

class ProxyService : public QObject {
Q_OBJECT
public:
    explicit ProxyService(QObject *parent = nullptr);
public slots:
    QVariant executeService(QJsonObject param);
    QVariant executeService(QString className, QString methodName, QJsonObject param);
};

#endif //BOOKMARKET_PROXYSERVICE_H
