#ifndef BOOKMARKET_JSON_H
#define BOOKMARKET_JSON_H

#include <QJsonArray>
#include <QJsonObject>
#include <QMetaProperty>

class JSON {
public:
    template<class T>
    static QJsonArray toJSONArray(QVector<T *> list) {
        QJsonArray jsonArray;
        for (int i = 0; i < list.size(); i++) {
            jsonArray.append(toJSONObject(list[i]));
        }
        return jsonArray;
    }

    template<class T>
    static QJsonObject toJSONObject(T *object) {
        QJsonObject qJsonObject;
        QMetaObject metaObject = T::staticMetaObject;
        for (int i = metaObject.propertyOffset(); i < metaObject.propertyCount(); i++) {
            QMetaProperty propertyName = metaObject.property(i);//获取属性名称
            QVariant propertyValue = object->property(propertyName.name());//获取属性值
            if (propertyName.typeId() == QMetaType::Type::QDateTime) {
                //QDateTime转换为QString
                qJsonObject[propertyName.name()] = propertyValue.toString();
            } else if (propertyName.typeId() == QMetaType::Type::QByteArray) {
                //QByteArray进行Base64加密，转QString
                qJsonObject[propertyName.name()] = QString::fromUtf8(propertyValue.toByteArray().toBase64());
            } else {
                qJsonObject[propertyName.name()] = propertyValue.toJsonValue();
            }
        }
        return qJsonObject;
    }
};

#endif //BOOKMARKET_JSON_H
