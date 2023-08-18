#include "AddressDao.h"
#include "../utils/DataBaseUtils.h"

Address *AddressDao::search(int id) {
    QString sql = "SELECT * FROM Address WHERE id=?";
    QVector<Address *> list = DataBaseUtils::search<Address>(sql, id);
    return list[0];
}
