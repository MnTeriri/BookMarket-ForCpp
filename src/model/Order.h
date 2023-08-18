#ifndef BOOKMARKET_ORDER_H
#define BOOKMARKET_ORDER_H

#include <QObject>
#include <QString>
#include <QDateTime>
#include <QVector>
#include "Address.h"
#include "OrderBook.h"

class Order : public QObject {
Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId)
    Q_PROPERTY(QString oid READ getOid WRITE setOid)
    Q_PROPERTY(QString uid READ getUid WRITE setUid)
    Q_PROPERTY(int aid READ getAid WRITE setAid)
    Q_PROPERTY(Address* address READ getAddress WRITE setAddress)
    Q_PROPERTY(QVector<OrderBook*> books READ getBooks WRITE setBooks)
    Q_PROPERTY(double price READ getPrice WRITE setPrice)
    Q_PROPERTY(int status READ getStatus WRITE setStatus)
    Q_PROPERTY(QDateTime created_time READ getCreatedTime WRITE setCreatedTime)
    Q_PROPERTY(QDateTime pay_time READ getPayTime WRITE setPayTime)
    Q_PROPERTY(QDateTime send_time READ getSendTime WRITE setSendTime)
    Q_PROPERTY(QDateTime finish_time READ getFinishTime WRITE setFinishTime)
private:
    int id;
    QString oid;//订单编号
    QString uid;//用户编号
    int aid;//地址编号
    Address* address;//地址信息
    QVector<OrderBook*> books;//订单当中购买书籍的信息
    double price;//总金额
    int status;//订单状态 0待付款、1已付款、2已发货、3交易成功、4交易取消、5退货、6退货成功
    QDateTime created_time;//创建时间
    QDateTime pay_time;//付款时间
    QDateTime send_time;//发货时间
    QDateTime finish_time;//完成时间
public:
    Q_INVOKABLE Order(QObject *parent= nullptr) : QObject(parent) {}

    ~Order() override {
        delete address;
        qDeleteAll(books);
        books.clear();
    }

    int getId() const {
        return id;
    }

    void setId(int id) {
        Order::id = id;
    }

    const QString &getOid() const {
        return oid;
    }

    void setOid(const QString &oid) {
        Order::oid = oid;
    }

    const QString &getUid() const {
        return uid;
    }

    void setUid(const QString &uid) {
        Order::uid = uid;
    }

    int getAid() const {
        return aid;
    }

    void setAid(int aid) {
        Order::aid = aid;
    }

    Address *getAddress() const {
        return address;
    }

    void setAddress(Address *address) {
        Order::address = address;
    }

    const QVector<OrderBook *> &getBooks() const {
        return books;
    }

    void setBooks(const QVector<OrderBook *> &books) {
        Order::books = books;
    }

    double getPrice() const {
        return price;
    }

    void setPrice(double price) {
        Order::price = price;
    }

    int getStatus() const {
        return status;
    }

    void setStatus(int status) {
        Order::status = status;
    }

    const QDateTime &getCreatedTime() const {
        return created_time;
    }

    void setCreatedTime(const QDateTime &createdTime) {
        created_time = createdTime;
    }

    const QDateTime &getPayTime() const {
        return pay_time;
    }

    void setPayTime(const QDateTime &payTime) {
        pay_time = payTime;
    }

    const QDateTime &getSendTime() const {
        return send_time;
    }

    void setSendTime(const QDateTime &sendTime) {
        send_time = sendTime;
    }

    const QDateTime &getFinishTime() const {
        return finish_time;
    }

    void setFinishTime(const QDateTime &finishTime) {
        finish_time = finishTime;
    }
};

#endif //BOOKMARKET_ORDER_H
