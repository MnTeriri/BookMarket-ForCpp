#ifndef BOOKMARKET_ADDRESS_H
#define BOOKMARKET_ADDRESS_H

#include <QObject>
#include <QString>
#include <QMetaType>

class Address : public QObject {
Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId)
    Q_PROPERTY(QString uid READ getUid WRITE setUid)
    Q_PROPERTY(QString province READ getProvince WRITE setProvince)
    Q_PROPERTY(QString city READ getCity WRITE setCity)
    Q_PROPERTY(QString district READ getDistrict WRITE setDistrict)
    Q_PROPERTY(QString address READ getAddress WRITE setAddress)
    Q_PROPERTY(QString receiver_name READ getReceiverName WRITE setReceiverName)
    Q_PROPERTY(QString phone READ getPhone WRITE setPhone)
    Q_PROPERTY(int is_default READ getIsDefault WRITE setIsDefault)
    Q_PROPERTY(int status READ getStatus WRITE setStatus)
private:
    int id;//地址编号
    QString uid;//用户编号
    QString province;//省
    QString city;//市
    QString district;//区
    QString address;//详细地址
    QString receiver_name;//收货人
    QString phone;//手机号码
    int is_default;//0不选中、1为选中
    int status;//0为假删除，1为未删除
public:
    Q_INVOKABLE Address(QObject *parent= nullptr) : QObject(parent) {}

    int getId() const {
        return id;
    }

    void setId(int id) {
        Address::id = id;
    }

    const QString &getUid() const {
        return uid;
    }

    void setUid(const QString &uid) {
        Address::uid = uid;
    }

    const QString &getProvince() const {
        return province;
    }

    void setProvince(const QString &province) {
        Address::province = province;
    }

    const QString &getCity() const {
        return city;
    }

    void setCity(const QString &city) {
        Address::city = city;
    }

    const QString &getDistrict() const {
        return district;
    }

    void setDistrict(const QString &district) {
        Address::district = district;
    }

    const QString &getAddress() const {
        return address;
    }

    void setAddress(const QString &address) {
        Address::address = address;
    }

    const QString &getReceiverName() const {
        return receiver_name;
    }

    void setReceiverName(const QString &receiverName) {
        Address::receiver_name = receiverName;
    }

    const QString &getPhone() const {
        return phone;
    }

    void setPhone(const QString &phone) {
        Address::phone = phone;
    }

    int getIsDefault() const {
        return is_default;
    }

    void setIsDefault(int isDefault) {
        Address::is_default = isDefault;
    }

    int getStatus() const {
        return status;
    }

    void setStatus(int status) {
        Address::status = status;
    }
};

Q_DECLARE_METATYPE(Address)
#endif //BOOKMARKET_ADDRESS_H
