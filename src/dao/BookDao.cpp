#include "BookDao.h"
#include "DataBaseBean.h"

using namespace std;

QVector<Book *> BookDao::getBookList(QString bname, int cid, int page, int count) {
    QSqlQuery query = DataBaseBean::getConnection();
    QString sql = "SELECT * FROM Book WHERE bname LIKE ? AND cid=? LIMIT ?,?";
    query.prepare(sql);
    query.bindValue(0, "%" + bname + "%");
    query.bindValue(1, cid);
    query.bindValue(2, (page - 1) * count);
    query.bindValue(3, count);
    query.exec();
    QVector<Book *> list = executeSearch(query);
    return list;
}

QVector<Book *> BookDao::executeSearch(QSqlQuery query) {
    QVector<Book *> list;
    while (query.next()) {
        Book *book = new Book;
        book->setId(query.value("id").toInt());
        book->setBid(query.value("bid").toString());
        book->setCid(query.value("cid").toInt());
        book->setBname(query.value("bname").toString());
        book->setAuthor(query.value("author").toString());
        book->setPublisher(query.value("publisher").toString());
        book->setPublishTime(query.value("publish_time").toDateTime());
        //book->setImage(query.value("image").toByteArray());
        book->setPrice(query.value("price").toDouble());
        book->setDiscount(query.value("discount").toDouble());
        book->setCount(query.value("count").toInt());
        book->setDescription(query.value("description").toString());
        book->setStatus(query.value("status").toInt());
        qDebug() << *book;
        list.push_back(book);
    }
    return list;
}
