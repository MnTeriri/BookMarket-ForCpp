#ifndef BOOKMARKET_JSON_H
#define BOOKMARKET_JSON_H

#include <QJsonArray>
#include <QJsonObject>
#include <QMetaProperty>
#include <QMetaTypeId>

class JSON {
public:
    template<class T>
    static QJsonArray toJSONArray(QVector<T *> list) {
        QJsonArray jsonArray;
        for (int i = 0; i < list.size(); i++) {
            jsonArray.append(toJSONObject((QObject*)list[i]));//调用的QJsonObject toJSONObject(QObject *object)
        }
        return jsonArray;
    }

    static QJsonArray toJSONArray(QVariant list) {
        QJsonArray jsonArray;
        QList<QVariant> listData = list.toList();
        for (int i = 0; i < listData.size(); i++) {
            jsonArray.append(toJSONObject(listData[i]));//QJsonObject toJSONObject(QVariant object)
        }
        return jsonArray;
    }

    static QJsonObject toJSONObject(QVariant object) {
        QJsonObject qJsonObject;
        QMetaType metaType = object.metaType();//获取QVariant存储数据的QMetaType
        QMetaObject metaObject = *metaType.metaObject();//根据QMetaType对象就能获取自定义类的QMetaObject对象了
        qDebug() << metaObject.className();
        for (int i = metaObject.propertyOffset(); i < metaObject.propertyCount(); i++) {
            QMetaProperty property = metaObject.property(i);//获取属性名称
            QVariant propertyValue = property.read(object.value<QObject *>());//获取属性值
            if (QString(property.typeName()).startsWith("QList")) {//如果是QList/QVector
                //qDebug() << property.name() << "是" << property.typeName() << "是QList";
                qJsonObject[property.name()] = toJSONArray(propertyValue);
            } else if (QMetaType::typeFlags(property.typeId()) & QMetaType::TypeFlag::IsPointer) {//如果是指针类型
                //qDebug() << property.name() << "是" << property.typeName() << "是指针";
                qJsonObject[property.name()] = toJSONObject(propertyValue);
            } else if (property.typeId() == QMetaType::Type::QDateTime) {//QDateTime转换为QString
                qJsonObject[property.name()] = propertyValue.toString();
            } else if (property.typeId() == QMetaType::Type::QByteArray) {//QByteArray进行Base64加密，转QString
                qJsonObject[property.name()] = QString::fromUtf8(propertyValue.toByteArray().toBase64());
            } else {
                qJsonObject[property.name()] = propertyValue.toJsonValue();
            }
        }
        return qJsonObject;
    }

    static QJsonObject toJSONObject(QObject *object) {
        QJsonObject qJsonObject;
        QMetaObject metaObject = *object->metaObject();
        qDebug() << metaObject.className();
        for (int i = metaObject.propertyOffset(); i < metaObject.propertyCount(); i++) {
            QMetaProperty property = metaObject.property(i);//获取属性名称
            QVariant propertyValue = object->property(property.name());//获取属性
            if (QString(property.typeName()).startsWith("QList")) {//如果是QList/QVector
                //qDebug() << property.name() << "是" << property.typeName() << "是QList";
                qJsonObject[property.name()] = toJSONArray(propertyValue);
            } else if (QMetaType::typeFlags(property.typeId()) & QMetaType::TypeFlag::IsPointer) {//如果是指针类型
                //qDebug() << property.name() << "是" << property.typeName() << "是指针";
                qJsonObject[property.name()] = toJSONObject(propertyValue.value<QObject *>());
            } else if (property.typeId() == QMetaType::Type::QDateTime) {//QDateTime转换为QString
                qJsonObject[property.name()] = propertyValue.toString();
            } else if (property.typeId() == QMetaType::Type::QByteArray) {//QByteArray进行Base64加密，转QString
                qJsonObject[property.name()] = QString::fromUtf8(propertyValue.toByteArray().toBase64());
            } else {
                qJsonObject[property.name()] = propertyValue.toJsonValue();
            }
        }
        return qJsonObject;
    }
};

#endif //BOOKMARKET_JSON_H
