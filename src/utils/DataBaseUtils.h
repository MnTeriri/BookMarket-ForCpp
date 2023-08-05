#include <QVector>
#include <QMetaObject>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlResult>
#include <QSqlRecord>
#include <QDebug>

class DataBaseUtils {
public:
    template<class ...Args>
    static int addData(QString sql, Args...var) {
        return modify(sql, var...);
    }

    template<class ...Args>
    static int updateData(QString sql, Args...var) {
        return modify(sql, var...);
    }

    template<class ...Args>
    static int deleteData(QString sql, Args...var) {
        return modify(sql, var...);
    }

    template<class T, class ...Args>
    static QVector<T *> search(QString sql, Args...var) {
        QVector<QVariant> args{var...};//获取不定长参数
        QVector<T *> list;
        QSqlQuery *query = DataBaseBean::getConnection();
        query->prepare(sql);
        for (int i = 0; i < args.size(); i++) {
            query->bindValue(i, args[i]);//与sql语句绑定
        }
        query->exec();
        QStringList headList;//获取sql查询表头
        QSqlRecord sqlRecord = query->record();
        for (int i = 0; i < sqlRecord.count(); i++) {
            headList << sqlRecord.fieldName(i);
        }
        //qDebug() << headList;
        while (query->next()) {
            T *t = (T *) T::staticMetaObject.newInstance();//把值填充到对象中
            for (int i = 0; i < headList.size(); i++) {
                QString fieldName = headList[i].toLower();
                t->setProperty(fieldName.toStdString().data(), query->value(i));
            }
            list.push_back(t);
        }
        return list;
    }

    template<class ...Args>
    static QVariant searchCount(QString sql, Args...var) {
        QVector<QVariant> args{var...};//获取不定长参数
        QSqlQuery *query = DataBaseBean::getConnection();
        query->prepare(sql);
        for (int i = 0; i < args.size(); i++) {
            query->bindValue(i, args[i]);//与sql语句绑定
        }
        query->exec();
        query->next();
        return query->value(0);
    }

private:
    template<class ...Args>
    static int modify(QString sql, Args...var) {
        int modify = 0;
        QVector<QVariant> args{var...};
        QSqlQuery *query = DataBaseBean::getConnection();
        query->prepare(sql);
        for (int i = 0; i < args.size(); i++) {
            query->bindValue(i, args[i]);
        }
        query->exec();
        modify = query->numRowsAffected();
        return modify;
    }
};