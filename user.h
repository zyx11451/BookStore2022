//
// Created by 123 on 2022/12/4.
//

#ifndef MAIN_CPP_USER_H
#define MAIN_CPP_USER_H

#include<string>
#include <set>
#include "book.h"
#include "readandwrite.h"




class password_type {
public:
    char a[31];

    password_type();

    password_type(std::string);

    ~password_type() = default;

    password_type &operator=(const password_type &b);

    bool operator==(const password_type &b);
};
class name_type {
public:
    char a[31];

    name_type();

    name_type(std::string);

    ~name_type()=default;

    name_type &operator=(const name_type &b);
};

class user {
private:
    password_type user_id;
    password_type password;
    name_type name;
    int privilege;
public:
    user();

    user(std::string user_id_,std::string password_,std::string name_,int privilege_);

    ~user() = default;

    void log_in(password_type user_id);

    void log_in(password_type user_id,password_type password);

    void log_out(int user_id);

    void change_password(int user_id);

    void delete_user(int user_id);

    void add_user();

    void user_register();

    void buy(std::string, int);

    void show();

    void select(std::string);

    void book_modify(std::string);

    void book_import(int quantity, double total_cost);

    bool operator<(const user &b);
};
struct selection{
    password_type now_user_id;
    ISBN now_book;
};
#endif //MAIN_CPP_USER_H
