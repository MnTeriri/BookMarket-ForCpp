#include "ProxyService.h"
#include <QJsonDocument>
#include <QMetaMethod>
ProxyService::ProxyService(QObject *parent) : QObject(parent) {
}

QVariant ProxyService::executeService(QJsonObject param) {
    QString className = param["class"].toString();//执行的类
    QString methodName = param["method"].toString();//执行的函数名
    QMetaType metaType = QMetaType::fromName(QByteArrayView(className.toUtf8()));//获取代理类的元类型
    QMetaObject metaObject = *metaType.metaObject();//获取代理类的元数据
    QObject *object = metaObject.newInstance();//创建对象
    QVariant result;
    QMetaObject::invokeMethod(object, methodName.toUtf8().constData(),
                              Q_RETURN_ARG(QVariant, result),
                              Q_ARG(QJsonObject, param));//执行函数
    delete object;
    return result;
}