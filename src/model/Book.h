#ifndef BOOKMARKET_BOOK_H
#define BOOKMARKET_BOOK_H

#include <QObject>
#include <QString>
#include <QDateTime>
#include <QByteArray>
#include <QVariant>
#include <ostream>

class Book : public QObject {
Q_OBJECT

private:
    int id;
    QString bid;//图书编号（ISBN）
    int cid;//分类号
    QString cname;//分类名
    QString bname;//图书名称
    QString author;//作者名称
    QString publisher;//出版社名称
    QDateTime publishTime;//出版时间
    QByteArray image;
    QString imageString;//书籍图片
    double price;//价格
    double discount;//折扣
    int count;//数量
    QString description;//图书描述
    int status;//图书状态 0正常、1缺货、2下架

public:
    Book(QObject *parent = nullptr) : QObject(parent) {}

    int getId() const {
        return id;
    }

    void setId(int id) {
        Book::id = id;
    }

    const QString &getBid() const {
        return bid;
    }

    void setBid(const QString &bid) {
        Book::bid = bid;
    }

    int getCid() const {
        return cid;
    }

    void setCid(int cid) {
        Book::cid = cid;
    }

    const QString &getCname() const {
        return cname;
    }

    void setCname(const QString &cname) {
        Book::cname = cname;
    }

    const QString &getBname() const {
        return bname;
    }

    void setBname(const QString &bname) {
        Book::bname = bname;
    }

    const QString &getAuthor() const {
        return author;
    }

    void setAuthor(const QString &author) {
        Book::author = author;
    }

    const QString &getPublisher() const {
        return publisher;
    }

    void setPublisher(const QString &publisher) {
        Book::publisher = publisher;
    }

    const QDateTime &getPublishTime() const {
        return publishTime;
    }

    void setPublishTime(const QDateTime &publishTime) {
        Book::publishTime = publishTime;
    }

    const QByteArray &getImage() const {
        return image;
    }

    void setImage(const QByteArray &image) {
        Book::image = image;
    }

    const QString &getImageString() const {
        return imageString;
    }

    void setImageString(const QString &imageString) {
        Book::imageString = imageString;
    }

    double getPrice() const {
        return price;
    }

    void setPrice(double price) {
        Book::price = price;
    }

    double getDiscount() const {
        return discount;
    }

    void setDiscount(double discount) {
        Book::discount = discount;
    }

    int getCount() const {
        return count;
    }

    void setCount(int count) {
        Book::count = count;
    }

    const QString &getDescription() const {
        return description;
    }

    void setDescription(const QString &description) {
        Book::description = description;
    }

    int getStatus() const {
        return status;
    }

    void setStatus(int status) {
        Book::status = status;
    }

    friend QDebug &operator<<(QDebug os, const Book &book) {
        os << (QObject *) &book << " id: " << book.id << " bid: " << book.bid << " cid: " << book.cid
           << " cname: " << book.cname << " bname: " << book.bname << " author: " << book.author << " publisher: "
           << book.publisher << " publishTime: " << book.publishTime << " image: " << book.image << " imageString: "
           << book.imageString << " price: " << book.price << " discount: " << book.discount << " count: " << book.count
           << " description: " << book.description << " status: " << book.status;
        return os;
    }

};

#endif //BOOKMARKET_BOOK_H
