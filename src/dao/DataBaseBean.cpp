#include "DataBaseBean.h"

QString DataBaseBean::hostName = "127.0.0.1";
int DataBaseBean::port = 3306;
QString DataBaseBean::dataBaseName = "database_achieve_class_design";
QString DataBaseBean::user = "root";
QString DataBaseBean::password = "root";
QSqlQuery *DataBaseBean::query = nullptr;

QSqlQuery* DataBaseBean::getConnection() {
    if (query == nullptr) {
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName(hostName);
        db.setPort(port);
        db.setDatabaseName(dataBaseName);
        db.setUserName(user);
        db.setPassword(password);
        db.open();
        query = new QSqlQuery(db);
    }
    return query;
}
