//
// Created by 123 on 2022/12/4.
//

#ifndef MAIN_CPP_BOOK_H
#define MAIN_CPP_BOOK_H

#include <string>
#include <set>
#include "user.h"

class Book {
private:
    std::string book_name;
    std::string author;
    std::string isbn;
    std::string key_word;
    int quantity;
    double price;
public:
    Book();
    friend user;

};

std::set<std::string> ISBN;
#endif //MAIN_CPP_BOOK_H
