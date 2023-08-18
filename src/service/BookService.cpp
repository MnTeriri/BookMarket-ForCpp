#include "BookService.h"
#include "../utils/JSON.h"

BookService::BookService(QObject *parent) : QObject(parent) {

}

QJsonObject BookService::getBookList(QString bname, int page, int count) {
    QJsonObject jsonObject;
    QVector<Book *> list = bookDao.getBookList(bname, page, count);
    int recordsTotal = bookDao.getRecordsTotal();
    int recordsFiltered = bookDao.getRecordsFiltered(bname);
    jsonObject["bookList"] = JSON::toJSONArray(list);
    jsonObject["recordsTotal"] = recordsTotal;
    jsonObject["recordsFiltered"] = recordsFiltered;
    qDeleteAll(list);
    return jsonObject;
}

QVariant BookService::getBookList(QJsonObject param) {
    QJsonObject jsonObject;
    QVector<Book *> list = bookDao.getBookList(param["bname"].toString(), param["page"].toInt(), param["count"].toInt());
    int recordsTotal = bookDao.getRecordsTotal();
    int recordsFiltered = bookDao.getRecordsFiltered(param["bname"].toString());
    jsonObject["bookList"] = JSON::toJSONArray(list);
    jsonObject["recordsTotal"] = recordsTotal;
    jsonObject["recordsFiltered"] = recordsFiltered;
    qDeleteAll(list);
    return jsonObject;
}
