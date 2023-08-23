#ifndef BOOKMARKET_ORDERBOOK_H
#define BOOKMARKET_ORDERBOOK_H

#include <QObject>
#include <QString>
#include "Book.h"

class OrderBook : public QObject {
Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId)
    Q_PROPERTY(QString oid READ getOid WRITE setOid)
    Q_PROPERTY(QString bid READ getBid WRITE setBid)
    Q_PROPERTY(Book* book READ getBook WRITE setBook)
    Q_PROPERTY(int count READ getCount WRITE setCount)
    Q_PROPERTY(double price READ getPrice WRITE setPrice)
    Q_PROPERTY(double discount READ getDiscount WRITE setDiscount)
private:
    int id;
    QString oid;//订单编号
    QString bid;//图书编号
    Book* book;//图书信息
    int count;//选购数量
    double price;//价格
    double discount;//折扣
public:
    Q_INVOKABLE OrderBook(QObject *parent = nullptr) : QObject(parent) {}

    ~OrderBook() override {
        delete book;
    }

    int getId() const {
        return id;
    }

    void setId(int id) {
        OrderBook::id = id;
    }

    const QString &getOid() const {
        return oid;
    }

    void setOid(const QString &oid) {
        OrderBook::oid = oid;
    }

    const QString &getBid() const {
        return bid;
    }

    void setBid(const QString &bid) {
        OrderBook::bid = bid;
    }

    Book *getBook() const {
        return book;
    }

    void setBook(Book *book) {
        OrderBook::book = book;
    }

    int getCount() const {
        return count;
    }

    void setCount(int count) {
        OrderBook::count = count;
    }

    double getPrice() const {
        return price;
    }

    void setPrice(double price) {
        OrderBook::price = price;
    }

    double getDiscount() const {
        return discount;
    }

    void setDiscount(double discount) {
        OrderBook::discount = discount;
    }
};

Q_DECLARE_METATYPE(OrderBook*)
#endif //BOOKMARKET_ORDERBOOK_H
