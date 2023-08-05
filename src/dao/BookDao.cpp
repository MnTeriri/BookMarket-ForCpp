#include "BookDao.h"
#include "DataBaseBean.h"
#include "../utils/DataBaseUtils.h"

QVector<Book *> BookDao::getBookList(QString bname, int page, int count) {
    QString sql = "SELECT Book.id, bid, cid,cname, bname, author, publisher, publish_time, image, price, discount, count, description, status "
                  "FROM Book INNER JOIN Category ON Book.cid = Category.id "
                  "WHERE bname LIKE ? LIMIT ?,?";
    QVector<Book *> list = DataBaseUtils::search<Book>(sql, "%" + bname + "%", (page - 1) * count, count);
    return list;
}

int BookDao::getRecordsTotal() {
    QVariant result = DataBaseUtils::searchCount("SELECT COUNT(id) FROM Book");
    return result.toInt();
}

int BookDao::getRecordsFiltered(QString bname) {
    QVariant result = DataBaseUtils::searchCount("SELECT COUNT(id) FROM Book WHERE bname LIKE ?", "%" + bname + "%");
    return result.toInt();
}

QVector<Book *> BookDao::executeSearch(QSqlQuery *query) {
    QVector<Book *> list;
    while (query->next()) {
        Book *book = new Book;
        book->setId(query->value("id").toInt());
        book->setBid(query->value("bid").toString());
        book->setCid(query->value("cid").toInt());
        book->setBname(query->value("bname").toString());
        book->setAuthor(query->value("author").toString());
        book->setPublisher(query->value("publisher").toString());
        book->setPublishTime(query->value("publish_time").toDateTime());
        book->setImage(query->value("image").toByteArray());
        book->setPrice(query->value("price").toDouble());
        book->setDiscount(query->value("discount").toDouble());
        book->setCount(query->value("count").toInt());
        book->setDescription(query->value("description").toString());
        book->setStatus(query->value("status").toInt());
        list.push_back(book);
    }
    return list;
}



