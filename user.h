//
// Created by 123 on 2022/12/4.
//

#ifndef MAIN_CPP_USER_H
#define MAIN_CPP_USER_H

#include<string>
#include <set>

class user {
private:
    int user_id;
    std::string password;
    std::string name;
    int privilege;
public:
    user();

    ~user();

    virtual void log_in(int user_id);

    virtual void log_out(int user_id);

    virtual void change_password(int user_id);

    virtual void delete_user(int user_id);

    virtual void add_user();

    virtual void user_register();

    virtual void buy(std::string, int);

    virtual void show();

    virtual void select(std::string);

    virtual void book_modify(std::string);

    virtual void book_import(int quantity, double total_cost);
};

class owner : public user {
public:
    void log_in(int user_id);

    void change_password(int user_id);

    void delete_user(int user_id);

    void add_user();
};

class assistant : public user {
public:
    void add_user();
};

class visitor : public user {
public:
    void log_in(int user_id);

    virtual void log_out(int user_id);

    virtual void change_password(int user_id);

    virtual void user_register();
};

std::set<std::string> user_name;
#endif //MAIN_CPP_USER_H
