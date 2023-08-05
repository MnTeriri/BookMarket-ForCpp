#ifndef BOOKMARKET_DATABASEBEAN_H
#define BOOKMARKET_DATABASEBEAN_H

#include <QSqlQuery>

class DataBaseBean {
private:
    static QString hostName;
    static int port;
    static QString dataBaseName;
    static QString user;
    static QString password;
    static QSqlQuery *query;
public:
    static QSqlQuery *getConnection();
};

#endif //BOOKMARKET_DATABASEBEAN_H
