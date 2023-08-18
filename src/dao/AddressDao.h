#ifndef BOOKMARKET_ADDRESSDAO_H
#define BOOKMARKET_ADDRESSDAO_H


#include "../model/Address.h"

class AddressDao {
public:
    Address* search(int id);
};


#endif //BOOKMARKET_ADDRESSDAO_H
