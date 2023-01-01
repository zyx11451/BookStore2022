//
// Created by 123 on 2022/12/4.
//

#ifndef MAIN_CPP_BOOK_H
#define MAIN_CPP_BOOK_H

#include <string>
#include <set>
#include "user.h"
class ISBN{
private:
    char a[21];
public:
    ISBN();

    ISBN(std::string);

    ~ISBN()=default;

    bool operator==(const ISBN &b);

    bool operator!=(const ISBN &b);

    bool operator>=(const ISBN &b);

    bool operator>(const ISBN &b);

    bool operator<=(const ISBN &b);

    bool operator<(const ISBN &b);

    ISBN &operator=(const ISBN &b);
};
class my_string{
public:
    char a[61];
    my_string();

    my_string(std::string);

    ~my_string()=default;

    bool operator==(const my_string &b);

    bool operator!=(const my_string &b);

    bool operator>=(const my_string &b);

    bool operator>(const my_string &b);

    bool operator<=(const my_string &b);

    bool operator<(const my_string &b);

    my_string &operator=(const my_string &b);
};
class Book {
private:
    my_string book_name;
    my_string author;
    ISBN isbn;
    my_string key_word[30];
    int quantity;
    double price;
public:
    Book(std::string book_name_,
         std::string author_,
         std::string isbn_,
         std::string keyword_,
         int quantity_,
         double price_);
    friend user;
    bool operator==(const Book &b);

    bool operator!=(const Book &b);

    bool operator>=(const Book &b);

    bool operator>(const Book &b);

    bool operator<=(const Book &b);

    bool operator<(const Book &b);
};

#endif //MAIN_CPP_BOOK_H
