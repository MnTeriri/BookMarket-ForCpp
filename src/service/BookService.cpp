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
